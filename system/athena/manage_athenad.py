#!/usr/bin/env python3

import time
from multiprocessing import Process

from openpilot.common.params import Params
from openpilot.system.manager.process import launcher
from openpilot.common.swaglog import cloudlog
from openpilot.system.hardware import HARDWARE
from openpilot.system.version import get_build_metadata

ATHENA_MGR_PID_PARAM = "AthenadPid"


def main():
<<<<<<< HEAD
  manage_athenad("DongleId", ATHENA_MGR_PID_PARAM, 'athenad', 'system.athena.athenad')


def manage_athenad(dongle_id_param, pid_param, process_name, target):
  params = Params()
  dongle_id = params.get(dongle_id_param, encoding='utf-8')
=======
  params = Params()
  dongle_id = params.get("DongleId").decode('utf-8')
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  build_metadata = get_build_metadata()

  cloudlog.bind_global(dongle_id=dongle_id,
                       version=build_metadata.openpilot.version,
                       origin=build_metadata.openpilot.git_normalized_origin,
                       branch=build_metadata.channel,
                       commit=build_metadata.openpilot.git_commit,
                       dirty=build_metadata.openpilot.is_dirty,
                       device=HARDWARE.get_device_type())

  try:
    while 1:
<<<<<<< HEAD
      cloudlog.info(f"starting {process_name} daemon")
      proc = Process(name=process_name, target=launcher, args=(target, process_name))
      proc.start()
      proc.join()
      cloudlog.event(f"{process_name} exited", exitcode=proc.exitcode)
      time.sleep(5)
  except Exception:
    cloudlog.exception(f"manage_{process_name}.exception")
  finally:
    params.remove(pid_param)
=======
      cloudlog.info("starting athena daemon")
      proc = Process(name='athenad', target=launcher, args=('system.athena.athenad', 'athenad'))
      proc.start()
      proc.join()
      cloudlog.event("athenad exited", exitcode=proc.exitcode)
      time.sleep(5)
  except Exception:
    cloudlog.exception("manage_athenad.exception")
  finally:
    params.remove(ATHENA_MGR_PID_PARAM)

>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

if __name__ == '__main__':
  main()
