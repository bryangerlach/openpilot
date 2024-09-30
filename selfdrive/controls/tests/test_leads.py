import cereal.messaging as messaging

<<<<<<< HEAD
from openpilot.selfdrive.test.process_replay import replay_process_with_name
from openpilot.selfdrive.car.toyota.values import CAR as TOYOTA
=======
from opendbc.car.toyota.values import CAR as TOYOTA
from openpilot.selfdrive.test.process_replay import replay_process_with_name
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e


class TestLeads:
  def test_radar_fault(self):
    # if there's no radar-related can traffic, radard should either not respond or respond with an error
    # this is tightly coupled with underlying car radar_interface implementation, but it's a good sanity check
    def single_iter_pkg():
      # single iter package, with meaningless cans and empty carState/modelV2
      msgs = []
<<<<<<< HEAD
      for _ in range(5):
        can = messaging.new_message("can", 1)
        cs = messaging.new_message("carState")
        msgs.append(can.as_reader())
        msgs.append(cs.as_reader())
=======
      for _ in range(500):
        can = messaging.new_message("can", 1)
        cs = messaging.new_message("carState")
        cp = messaging.new_message("carParams")
        msgs.append(can.as_reader())
        msgs.append(cs.as_reader())
        msgs.append(cp.as_reader())
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
      model = messaging.new_message("modelV2")
      msgs.append(model.as_reader())

      return msgs

    msgs = [m for _ in range(3) for m in single_iter_pkg()]
<<<<<<< HEAD
    out = replay_process_with_name("radard", msgs, fingerprint=TOYOTA.TOYOTA_COROLLA_TSS2)
    states = [m for m in out if m.which() == "radarState"]
    failures = [not state.valid and len(state.radarState.radarErrors) for state in states]
=======
    out = replay_process_with_name("card", msgs, fingerprint=TOYOTA.TOYOTA_COROLLA_TSS2)
    states = [m for m in out if m.which() == "liveTracks"]
    failures = [not state.valid and len(state.liveTracks.errors) for state in states]
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

    assert len(states) == 0 or all(failures)
