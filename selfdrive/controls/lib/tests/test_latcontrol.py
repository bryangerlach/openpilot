from parameterized import parameterized

from cereal import car, log
<<<<<<< HEAD
from openpilot.selfdrive.car.car_helpers import interfaces
from openpilot.selfdrive.car.honda.values import CAR as HONDA
from openpilot.selfdrive.car.toyota.values import CAR as TOYOTA
from openpilot.selfdrive.car.nissan.values import CAR as NISSAN
=======
from opendbc.car.car_helpers import interfaces
from opendbc.car.honda.values import CAR as HONDA
from opendbc.car.toyota.values import CAR as TOYOTA
from opendbc.car.nissan.values import CAR as NISSAN
from openpilot.selfdrive.car.card import convert_to_capnp
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
from openpilot.selfdrive.controls.lib.latcontrol_pid import LatControlPID
from openpilot.selfdrive.controls.lib.latcontrol_torque import LatControlTorque
from openpilot.selfdrive.controls.lib.latcontrol_angle import LatControlAngle
from openpilot.selfdrive.controls.lib.vehicle_model import VehicleModel
<<<<<<< HEAD
from openpilot.common.mock.generators import generate_liveLocationKalman
=======
from openpilot.selfdrive.locationd.helpers import Pose
from openpilot.common.mock.generators import generate_livePose
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e


class TestLatControl:

  @parameterized.expand([(HONDA.HONDA_CIVIC, LatControlPID), (TOYOTA.TOYOTA_RAV4, LatControlTorque),  (NISSAN.NISSAN_LEAF, LatControlAngle)])
  def test_saturation(self, car_name, controller):
<<<<<<< HEAD
    CarInterface, CarController, CarState = interfaces[car_name]
    CP = CarInterface.get_non_essential_params(car_name)
    CI = CarInterface(CP, CarController, CarState)
=======
    CarInterface, CarController, CarState, RadarInterface = interfaces[car_name]
    CP = CarInterface.get_non_essential_params(car_name)
    CI = CarInterface(CP, CarController, CarState)
    CP = convert_to_capnp(CP)
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
    VM = VehicleModel(CP)

    controller = controller(CP.as_reader(), CI)

    CS = car.CarState.new_message()
    CS.vEgo = 30
    CS.steeringPressed = False

    params = log.LiveParametersData.new_message()

<<<<<<< HEAD
    llk = generate_liveLocationKalman()
    for _ in range(1000):
      _, _, lac_log = controller.update(True, CS, VM, params, False, 1, llk)
=======
    lp = generate_livePose()
    pose = Pose.from_live_pose(lp.livePose)

    for _ in range(1000):
      _, _, lac_log = controller.update(True, CS, VM, params, False, 1, pose)
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

    assert lac_log.saturated
