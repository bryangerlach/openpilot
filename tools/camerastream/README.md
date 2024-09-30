# Camera stream

<<<<<<< HEAD
`compressed_vipc.py` connects to a remote device running openpilot, decodes the video streams, and republishes them over VisionIPC. 

## Usage

### On the device 
=======
`compressed_vipc.py` connects to a remote device running openpilot, decodes the video streams, and republishes them over VisionIPC.

## Usage

### On the device
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
SSH into the device and run following in separate terminals:

`cd /data/openpilot/cereal/messaging && ./bridge`

`cd /data/openpilot/system/loggerd && ./encoderd`

`cd /data/openpilot/system/camerad && ./camerad`

Note that both the device and your PC must be on the same openpilot commit.

Alternatively paste this as a single command:
```
(
  cd /data/openpilot/cereal/messaging/
  ./bridge &

  cd /data/openpilot/system/camerad/
  ./camerad &

  cd /data/openpilot/system/loggerd/
  ./encoderd &

  wait
) ; trap 'kill $(jobs -p)' SIGINT
```
<<<<<<< HEAD
Ctrl+C will stop all three processes. 
=======
Ctrl+C will stop all three processes.
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

### On the PC
Decode the stream with `compressed_vipc.py`:

```cd ~/openpilot/tools/camerastream && ./compressed_vipc.py <ip>```

To actually display the stream, run `watch3` in separate terminal:

```cd ~/openpilot/selfdrive/ui/ && ./watch3```

## compressed_vipc.py usage
```
<<<<<<< HEAD
$ python compressed_vipc.py -h
=======
$ python3 compressed_vipc.py -h
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
usage: compressed_vipc.py [-h] [--nvidia] [--cams CAMS] [--silent] addr

Decode video streams and broadcast on VisionIPC

positional arguments:
  addr         Address of comma three

options:
  -h, --help   show this help message and exit
  --nvidia     Use nvidia instead of ffmpeg
  --cams CAMS  Cameras to decode
  --silent     Suppress debug output
```


## Example:
```
cd ~/openpilot/tools/camerastream && ./compressed_vipc.py comma-ffffffff --cams 0
cd ~/openpilot/selfdrive/ui/ && ./watch3
```
