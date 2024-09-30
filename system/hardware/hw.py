import os
from pathlib import Path

from openpilot.system.hardware import PC

DEFAULT_DOWNLOAD_CACHE_ROOT = "/tmp/comma_download_cache"

class Paths:
  @staticmethod
  def comma_home() -> str:
    return os.path.join(str(Path.home()), ".comma" + os.environ.get("OPENPILOT_PREFIX", ""))

  @staticmethod
  def log_root() -> str:
    if os.environ.get('LOG_ROOT', False):
      return os.environ['LOG_ROOT']
    elif PC:
      return str(Path(Paths.comma_home()) / "media" / "0" / "realdata")
    else:
      return '/data/media/0/realdata/'

  @staticmethod
  def swaglog_root() -> str:
    if PC:
      return os.path.join(Paths.comma_home(), "log")
    else:
      return "/data/log/"

  @staticmethod
  def swaglog_ipc() -> str:
    return "ipc:///tmp/logmessage" + os.environ.get("OPENPILOT_PREFIX", "")

  @staticmethod
  def download_cache_root() -> str:
    if os.environ.get('COMMA_CACHE', False):
      return os.environ['COMMA_CACHE'] + "/"
    return DEFAULT_DOWNLOAD_CACHE_ROOT + os.environ.get("OPENPILOT_PREFIX", "") + "/"

  @staticmethod
  def persist_root() -> str:
    if PC:
      return os.path.join(Paths.comma_home(), "persist")
    else:
      return "/persist/"

  @staticmethod
  def stats_root() -> str:
    if PC:
      return str(Path(Paths.comma_home()) / "stats")
    else:
      return "/data/stats/"

  @staticmethod
  def config_root() -> str:
    if PC:
      return Paths.comma_home()
    else:
      return "/tmp/.comma"
<<<<<<< HEAD

  @staticmethod
  def community_crash_root() -> str:
    if PC:
      return str(Path(Paths.comma_home()) / "community" / "crashes")
    else:
      return "/data/community/crashes"

  @staticmethod
  def model_root() -> str:
    if PC:
      return str(Path(Paths.comma_home()) / "media" / "0" / "models")
    else:
      return "/data/media/0/models"

  @staticmethod
  def mapd_root() -> str:
    if PC:
      return str(Path(Paths.comma_home()) / "media" / "0" / "osm")
    else:
      return "/data/media/0/osm"
=======
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
