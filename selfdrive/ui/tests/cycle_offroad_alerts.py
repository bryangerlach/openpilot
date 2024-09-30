#!/usr/bin/env python3
import os
import sys
import time
import json

from openpilot.common.basedir import BASEDIR
from openpilot.common.params import Params
<<<<<<< HEAD
from openpilot.selfdrive.controls.lib.alertmanager import set_offroad_alert
=======
from openpilot.selfdrive.selfdrived.alertmanager import set_offroad_alert
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

if __name__ == "__main__":
  params = Params()

<<<<<<< HEAD
  with open(os.path.join(BASEDIR, "selfdrive/controls/lib/alerts_offroad.json")) as f:
=======
  with open(os.path.join(BASEDIR, "selfdrive/selfdrived/alerts_offroad.json")) as f:
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
    offroad_alerts = json.load(f)

  t = 10 if len(sys.argv) < 2 else int(sys.argv[1])
  while True:
    print("setting alert update")
    params.put_bool("UpdateAvailable", True)
<<<<<<< HEAD
    r = open(os.path.join(BASEDIR, "CHANGELOGS.md")).read()
=======
    r = open(os.path.join(BASEDIR, "RELEASES.md")).read()
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
    r = r[:r.find('\n\n')]  # Slice latest release notes
    params.put("UpdaterNewReleaseNotes", r + "\n")

    time.sleep(t)
    params.put_bool("UpdateAvailable", False)

    # cycle through normal alerts
    for a in offroad_alerts:
      print("setting alert:", a)
      set_offroad_alert(a, True)
      time.sleep(t)
      set_offroad_alert(a, False)

    print("no alert")
    time.sleep(t)
