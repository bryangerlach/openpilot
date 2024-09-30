from collections import namedtuple
<<<<<<< HEAD
=======
import capnp
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
import pathlib
import shutil
import sys
import jinja2
import matplotlib.pyplot as plt
import numpy as np
import os
import pywinctl
import time

<<<<<<< HEAD
from cereal import messaging, car, log
from msgq.visionipc import VisionIpcServer, VisionStreamType

from cereal.messaging import SubMaster, PubMaster
from openpilot.common.mock import mock_messages
from openpilot.common.params import Params
from openpilot.common.realtime import DT_MDL
from openpilot.common.transformations.camera import DEVICE_CAMERAS
from openpilot.selfdrive.test.helpers import with_processes
from openpilot.selfdrive.test.process_replay.vision_meta import meta_from_camera_state

UI_DELAY = 0.5 # may be slower on CI?

NetworkType = log.DeviceState.NetworkType
NetworkStrength = log.DeviceState.NetworkStrength

EventName = car.CarEvent.EventName
EVENTS_BY_NAME = {v: k for k, v in EventName.schema.enumerants.items()}


def setup_common(click, pm: PubMaster):
  Params().put("DongleId", "123456789012345")
  dat = messaging.new_message('deviceState')
  dat.deviceState.started = True
  dat.deviceState.networkType = NetworkType.cell4G
  dat.deviceState.networkStrength = NetworkStrength.moderate
  dat.deviceState.freeSpacePercent = 80
  dat.deviceState.memoryUsagePercent = 2
  dat.deviceState.cpuTempC = [2,]*3
  dat.deviceState.gpuTempC = [2,]*3
  dat.deviceState.cpuUsagePercent = [2,]*8

  pm.send("deviceState", dat)

def setup_homescreen(click, pm: PubMaster):
  setup_common(click, pm)

def setup_settings_device(click, pm: PubMaster):
  setup_common(click, pm)

  click(100, 100)

def setup_settings_network(click, pm: PubMaster):
  setup_common(click, pm)

  setup_settings_device(click, pm)
  click(300, 600)

def setup_onroad(click, pm: PubMaster):
  setup_common(click, pm)

  dat = messaging.new_message('pandaStates', 1)
  dat.pandaStates[0].ignitionLine = True
  dat.pandaStates[0].pandaType = log.PandaState.PandaType.uno

  pm.send("pandaStates", dat)

  d = DEVICE_CAMERAS[("tici", "ar0231")]
  server = VisionIpcServer("camerad")
  server.create_buffers(VisionStreamType.VISION_STREAM_ROAD, 40, False, d.fcam.width, d.fcam.height)
  server.create_buffers(VisionStreamType.VISION_STREAM_DRIVER, 40, False, d.dcam.width, d.dcam.height)
  server.create_buffers(VisionStreamType.VISION_STREAM_WIDE_ROAD, 40, False, d.fcam.width, d.fcam.height)
  server.start_listener()

  time.sleep(0.5) # give time for vipc server to start

  IMG = np.zeros((int(d.fcam.width*1.5), d.fcam.height), dtype=np.uint8)
  IMG_BYTES = IMG.flatten().tobytes()

  cams = ('roadCameraState', 'wideRoadCameraState')

  frame_id = 0
  for cam in cams:
    msg = messaging.new_message(cam)
    cs = getattr(msg, cam)
    cs.frameId = frame_id
    cs.timestampSof = int((frame_id * DT_MDL) * 1e9)
    cs.timestampEof = int((frame_id * DT_MDL) * 1e9)
    cam_meta = meta_from_camera_state(cam)

    pm.send(msg.which(), msg)
    server.send(cam_meta.stream, IMG_BYTES, cs.frameId, cs.timestampSof, cs.timestampEof)

@mock_messages(['liveLocationKalman'])
def setup_onroad_map(click, pm: PubMaster):
  setup_onroad(click, pm)

  click(500, 500)

  time.sleep(UI_DELAY) # give time for the map to render

def setup_onroad_sidebar(click, pm: PubMaster):
  setup_onroad_map(click, pm)
  click(500, 500)

CASES = {
  "homescreen": setup_homescreen,
  "settings_device": setup_settings_device,
  "settings_network": setup_settings_network,
  "onroad": setup_onroad,
  "onroad_map": setup_onroad_map,
  "onroad_sidebar": setup_onroad_sidebar
=======
from cereal import log
from msgq.visionipc import VisionIpcServer, VisionStreamType
from cereal.messaging import PubMaster, log_from_bytes, sub_sock
from openpilot.common.basedir import BASEDIR
from openpilot.common.params import Params
from openpilot.common.prefix import OpenpilotPrefix
from openpilot.common.transformations.camera import CameraConfig, DEVICE_CAMERAS
from openpilot.selfdrive.selfdrived.alertmanager import set_offroad_alert
from openpilot.selfdrive.test.helpers import with_processes
from openpilot.selfdrive.test.process_replay.migration import migrate_controlsState
from openpilot.tools.lib.logreader import LogReader
from openpilot.tools.lib.framereader import FrameReader
from openpilot.tools.lib.route import Route

UI_DELAY = 0.5 # may be slower on CI?
TEST_ROUTE = "a2a0ccea32023010|2023-07-27--13-01-19"

STREAMS: list[tuple[VisionStreamType, CameraConfig, bytes]] = []
OFFROAD_ALERTS = ['Offroad_StorageMissing', 'Offroad_IsTakingSnapshot']
DATA: dict[str, capnp.lib.capnp._DynamicStructBuilder] = dict.fromkeys(
  ["carParams", "deviceState", "pandaStates", "controlsState", "selfdriveState",
  "liveCalibration", "modelV2", "radarState", "driverMonitoringState", "carState",
  "driverStateV2", "roadCameraState", "wideRoadCameraState", "driverCameraState"], None)

def setup_homescreen(click, pm: PubMaster):
  pass

def setup_settings_device(click, pm: PubMaster):
  click(100, 100)

def setup_settings_toggles(click, pm: PubMaster):
  setup_settings_device(click, pm)
  click(278, 760)
  time.sleep(UI_DELAY)

def setup_onroad(click, pm: PubMaster):
  vipc_server = VisionIpcServer("camerad")
  for stream_type, cam, _ in STREAMS:
    vipc_server.create_buffers(stream_type, 5, False, cam.width, cam.height)
  vipc_server.start_listener()

  uidebug_received_cnt = 0
  packet_id = 0
  uidebug_sock = sub_sock('uiDebug')

  # Condition check for uiDebug processing
  check_uidebug = DATA['deviceState'].deviceState.started and not DATA['carParams'].carParams.notCar

  # Loop until 20 'uiDebug' messages are received
  while uidebug_received_cnt <= 20:
    for service, data in DATA.items():
      if data:
        data.clear_write_flag()
        pm.send(service, data)

    for stream_type, _, image in STREAMS:
      vipc_server.send(stream_type, image, packet_id, packet_id, packet_id)

    if check_uidebug:
      while uidebug_sock.receive(non_blocking=True):
        uidebug_received_cnt += 1
    else:
      uidebug_received_cnt += 1

    packet_id += 1
    time.sleep(0.05)

def setup_onroad_disengaged(click, pm: PubMaster):
  DATA['selfdriveState'].selfdriveState.enabled = False
  setup_onroad(click, pm)
  DATA['selfdriveState'].selfdriveState.enabled = True

def setup_onroad_override(click, pm: PubMaster):
  DATA['selfdriveState'].selfdriveState.state = log.SelfdriveState.OpenpilotState.overriding
  setup_onroad(click, pm)
  DATA['selfdriveState'].selfdriveState.state = log.SelfdriveState.OpenpilotState.enabled


def setup_onroad_wide(click, pm: PubMaster):
  DATA['selfdriveState'].selfdriveState.experimentalMode = True
  DATA["carState"].carState.vEgo = 1
  setup_onroad(click, pm)

def setup_onroad_sidebar(click, pm: PubMaster):
  setup_onroad(click, pm)
  click(500, 500)
  setup_onroad(click, pm)

def setup_onroad_wide_sidebar(click, pm: PubMaster):
  setup_onroad_wide(click, pm)
  click(500, 500)
  setup_onroad_wide(click, pm)

def setup_body(click, pm: PubMaster):
  DATA['carParams'].carParams.carName = "BODY"
  DATA['carParams'].carParams.notCar = True
  DATA['carState'].carState.charging = True
  DATA['carState'].carState.fuelGauge = 50.0
  setup_onroad(click, pm)

def setup_keyboard(click, pm: PubMaster):
  setup_settings_device(click, pm)
  click(250, 575)
  click(2020, 218)
  click(1830, 80)
  click(2035, 808)
  click(90, 480)

def setup_driver_camera(click, pm: PubMaster):
  setup_settings_device(click, pm)
  click(1950, 435)
  DATA['deviceState'].deviceState.started = False
  setup_onroad(click, pm)
  DATA['deviceState'].deviceState.started = True

def setup_onroad_alert(click, pm: PubMaster, text1, text2, size, status=log.SelfdriveState.AlertStatus.normal):
  print(f'setup onroad alert, size: {size}')
  state = DATA['selfdriveState']
  origin_state_bytes = state.to_bytes()
  cs = state.selfdriveState
  cs.alertText1 = text1
  cs.alertText2 = text2
  cs.alertSize = size
  cs.alertStatus = status
  cs.alertType = "test_onroad_alert"
  setup_onroad(click, pm)
  DATA['selfdriveState'] = log_from_bytes(origin_state_bytes).as_builder()

def setup_onroad_alert_small(click, pm: PubMaster):
  setup_onroad_alert(click, pm, 'This is a small alert message', '', log.SelfdriveState.AlertSize.small)

def setup_onroad_alert_mid(click, pm: PubMaster):
  setup_onroad_alert(click, pm, 'Medium Alert', 'This is a medium alert message', log.SelfdriveState.AlertSize.mid)

def setup_onroad_alert_full(click, pm: PubMaster):
  setup_onroad_alert(click, pm, 'Full Alert', 'This is a full alert message', log.SelfdriveState.AlertSize.full)

def setup_offroad_alert(click, pm: PubMaster):
  for alert in OFFROAD_ALERTS:
    set_offroad_alert(alert, True)

  # Toggle between settings and home to refresh the offroad alert widget
  setup_settings_device(click, pm)
  click(240, 216)

def setup_update_available(click, pm: PubMaster):
  Params().put_bool("UpdateAvailable", True)
  release_notes_path = os.path.join(BASEDIR, "RELEASES.md")
  with open(release_notes_path) as file:
    release_notes = file.read().split('\n\n', 1)[0]
  Params().put("UpdaterNewReleaseNotes", release_notes + "\n")

  setup_settings_device(click, pm)
  click(240, 216)

def setup_pair_device(click, pm: PubMaster):
  click(1950, 435)
  click(1800, 900)

CASES = {
  "homescreen": setup_homescreen,
  "prime": setup_homescreen,
  "pair_device": setup_pair_device,
  "settings_device": setup_settings_device,
  "settings_toggles": setup_settings_toggles,
  "onroad": setup_onroad,
  "onroad_disengaged": setup_onroad_disengaged,
  "onroad_override": setup_onroad_override,
  "onroad_sidebar": setup_onroad_sidebar,
  "onroad_alert_small": setup_onroad_alert_small,
  "onroad_alert_mid": setup_onroad_alert_mid,
  "onroad_alert_full": setup_onroad_alert_full,
  "onroad_wide": setup_onroad_wide,
  "onroad_wide_sidebar": setup_onroad_wide_sidebar,
  "driver_camera": setup_driver_camera,
  "body": setup_body,
  "offroad_alert": setup_offroad_alert,
  "update_available": setup_update_available,
  "keyboard": setup_keyboard
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
}

TEST_DIR = pathlib.Path(__file__).parent

TEST_OUTPUT_DIR = TEST_DIR / "report_1"
SCREENSHOTS_DIR = TEST_OUTPUT_DIR / "screenshots"


class TestUI:
  def __init__(self):
    os.environ["SCALE"] = "1"
    sys.modules["mouseinfo"] = False

  def setup(self):
<<<<<<< HEAD
    self.sm = SubMaster(["uiDebug"])
    self.pm = PubMaster(["deviceState", "pandaStates", "controlsState", 'roadCameraState', 'wideRoadCameraState', 'liveLocationKalman'])
    while not self.sm.valid["uiDebug"]:
      self.sm.update(1)
    time.sleep(UI_DELAY) # wait a bit more for the UI to start rendering
=======
    self.pm = PubMaster(list(DATA.keys()))
    DATA['deviceState'].deviceState.networkType = log.DeviceState.NetworkType.wifi
    DATA['deviceState'].deviceState.lastAthenaPingTime = 0
    for _ in range(10):
      self.pm.send('deviceState', DATA['deviceState'])
      DATA['deviceState'].clear_write_flag()
      time.sleep(0.05)
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
    try:
      self.ui = pywinctl.getWindowsWithTitle("ui")[0]
    except Exception as e:
      print(f"failed to find ui window, assuming that it's in the top left (for Xvfb) {e}")
      self.ui = namedtuple("bb", ["left", "top", "width", "height"])(0,0,2160,1080)

  def screenshot(self):
    import pyautogui
    im = pyautogui.screenshot(region=(self.ui.left, self.ui.top, self.ui.width, self.ui.height))
    assert im.width == 2160
    assert im.height == 1080
    img = np.array(im)
    im.close()
    return img

  def click(self, x, y, *args, **kwargs):
    import pyautogui
    pyautogui.click(self.ui.left + x, self.ui.top + y, *args, **kwargs)
    time.sleep(UI_DELAY) # give enough time for the UI to react

  @with_processes(["ui"])
  def test_ui(self, name, setup_case):
    self.setup()

    setup_case(self.click, self.pm)

<<<<<<< HEAD
    time.sleep(UI_DELAY) # wait a bit more for the UI to finish rendering

=======
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
    im = self.screenshot()
    plt.imsave(SCREENSHOTS_DIR / f"{name}.png", im)


def create_html_report():
  OUTPUT_FILE = TEST_OUTPUT_DIR / "index.html"

  with open(TEST_DIR / "template.html") as f:
    template = jinja2.Template(f.read())

  cases = {f.stem: (str(f.relative_to(TEST_OUTPUT_DIR)), "reference.png") for f in SCREENSHOTS_DIR.glob("*.png")}
  cases = dict(sorted(cases.items()))

  with open(OUTPUT_FILE, "w") as f:
    f.write(template.render(cases=cases))

def create_screenshots():
  if TEST_OUTPUT_DIR.exists():
    shutil.rmtree(TEST_OUTPUT_DIR)

  SCREENSHOTS_DIR.mkdir(parents=True)

<<<<<<< HEAD
  t = TestUI()
  for name, setup in CASES.items():
    t.test_ui(name, setup)
=======
  route = Route(TEST_ROUTE)

  segnum = 2
  lr = LogReader(route.qlog_paths()[segnum])
  DATA['carParams'] = next((event.as_builder() for event in lr if event.which() == 'carParams'), None)
  for event in migrate_controlsState(lr):
    if event.which() in DATA:
      DATA[event.which()] = event.as_builder()

    if all(DATA.values()):
      break

  cam = DEVICE_CAMERAS[("tici", "ar0231")]
  road_img = FrameReader(route.camera_paths()[segnum]).get(0, pix_fmt="nv12")[0]
  STREAMS.append((VisionStreamType.VISION_STREAM_ROAD, cam.fcam, road_img.flatten().tobytes()))

  wide_road_img = FrameReader(route.ecamera_paths()[segnum]).get(0, pix_fmt="nv12")[0]
  STREAMS.append((VisionStreamType.VISION_STREAM_WIDE_ROAD, cam.ecam, wide_road_img.flatten().tobytes()))

  driver_img = FrameReader(route.dcamera_paths()[segnum]).get(0, pix_fmt="nv12")[0]
  STREAMS.append((VisionStreamType.VISION_STREAM_DRIVER, cam.dcam, driver_img.flatten().tobytes()))

  t = TestUI()

  for name, setup in CASES.items():
    with OpenpilotPrefix():
      params = Params()
      params.put("DongleId", "123456789012345")
      if name == 'prime':
        params.put('PrimeType', '1')
      elif name == 'pair_device':
        params.put('ApiCache_Device', '{"is_paired":0, "prime_type":-1}')

      t.test_ui(name, setup)
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

if __name__ == "__main__":
  print("creating test screenshots")
  create_screenshots()

  print("creating html report")
  create_html_report()
