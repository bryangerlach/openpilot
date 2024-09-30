from cereal import car
from cereal import messaging
from cereal.messaging import SubMaster, PubMaster
<<<<<<< HEAD
from openpilot.selfdrive.ui.soundd import CONTROLS_TIMEOUT, check_controls_timeout_alert
=======
from openpilot.selfdrive.ui.soundd import SELFDRIVE_STATE_TIMEOUT, check_selfdrive_timeout_alert
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

import time

AudibleAlert = car.CarControl.HUDControl.AudibleAlert


class TestSoundd:
<<<<<<< HEAD
  def test_check_controls_timeout_alert(self):
    sm = SubMaster(['controlsState'])
    pm = PubMaster(['controlsState'])

    for _ in range(100):
      cs = messaging.new_message('controlsState')
      cs.controlsState.enabled = True

      pm.send("controlsState", cs)
=======
  def test_check_selfdrive_timeout_alert(self):
    sm = SubMaster(['selfdriveState'])
    pm = PubMaster(['selfdriveState'])

    for _ in range(100):
      cs = messaging.new_message('selfdriveState')
      cs.selfdriveState.enabled = True

      pm.send("selfdriveState", cs)
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

      time.sleep(0.01)

      sm.update(0)

<<<<<<< HEAD
      assert not check_controls_timeout_alert(sm)

    for _ in range(CONTROLS_TIMEOUT * 110):
      sm.update(0)
      time.sleep(0.01)

    assert check_controls_timeout_alert(sm)
=======
      assert not check_selfdrive_timeout_alert(sm)

    for _ in range(SELFDRIVE_STATE_TIMEOUT * 110):
      sm.update(0)
      time.sleep(0.01)

    assert check_selfdrive_timeout_alert(sm)
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

  # TODO: add test with micd for checking that soundd actually outputs sounds

