import os
import socket
from urllib.parse import urlparse

from openpilot.tools.lib.url_file import URLFile

DATA_ENDPOINT = os.getenv("DATA_ENDPOINT", "http://data-raw.comma.internal/")


<<<<<<< HEAD
def internal_source_available():
  try:
    hostname = urlparse(DATA_ENDPOINT).hostname
    port = urlparse(DATA_ENDPOINT).port or 80
=======
def internal_source_available(url=DATA_ENDPOINT):
  try:
    hostname = urlparse(url).hostname
    port = urlparse(url).port or 80
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
    with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as s:
      s.connect((hostname, port))
    return True
  except (socket.gaierror, ConnectionRefusedError):
    pass
  return False


def resolve_name(fn):
  if fn.startswith("cd:/"):
    return fn.replace("cd:/", DATA_ENDPOINT)
  return fn


def file_exists(fn):
  fn = resolve_name(fn)
  if fn.startswith(("http://", "https://")):
    return URLFile(fn).get_length_online() != -1
  return os.path.exists(fn)


def FileReader(fn, debug=False):
  fn = resolve_name(fn)
  if fn.startswith(("http://", "https://")):
    return URLFile(fn, debug=debug)
  return open(fn, "rb")
