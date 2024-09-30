import datetime
from pathlib import Path

<<<<<<< HEAD
_MIN_DATE = datetime.datetime(year=2024, month=3, day=30)
=======
_MIN_DATE = datetime.datetime(year=2024, month=8, day=26)
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

def min_date():
  # on systemd systems, the default time is the systemd build time
  systemd_path = Path("/lib/systemd/systemd")
  if systemd_path.exists():
    d = datetime.datetime.fromtimestamp(systemd_path.stat().st_mtime)
    return d + datetime.timedelta(days=1)
  return _MIN_DATE

def system_time_valid():
  return datetime.datetime.now() > min_date()
