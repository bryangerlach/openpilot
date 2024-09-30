# Rerun
Rerun is a tool to quickly visualize time series data. It supports all openpilot logs , both the `logMessages` and video logs.

[Instructions](https://rerun.io/docs/reference/viewer/overview) for navigation within the Rerun Viewer.

## Usage
```
<<<<<<< HEAD
usage: run.py [-h] [--demo] [--qcam] [--fcam] [--ecam] [--dcam] [--print_services] [--services [SERVICES ...]] [route_or_segment_name]

A helper to run rerun on openpilot routes

options:
  -h, --help                  show this help message and exit
  --demo                      Use the demo route instead of providing one (default: False)
  --qcam                      Log decimated driving camera (default: False)
  --fcam                      Log driving camera (default: False)
  --ecam                      Log wide camera (default: False)
  --dcam                      Log driver monitoring camera (default: False)
  --print_services            List out openpilot services (default: False)
  --services [SERVICES ...]   Specify openpilot services that will be logged. No service will be logged if not specified.
                              To log all services include 'all' as one of your services (default: [])
  --route [ROUTE]             The route or segment name to plot (default: None)
=======
usage: run.py [-h] [--demo] [--qcam] [--fcam] [--ecam] [--dcam] [route_or_segment_name]

A helper to run rerun on openpilot routes

positional arguments:
  route_or_segment_name
                        The route or segment name to plot (default: None)

options:
  -h, --help            show this help message and exit
  --demo                Use the demo route instead of providing one (default: False)
  --qcam                Show low-res road camera (default: False)
  --fcam                Show driving camera (default: False)
  --ecam                Show wide camera (default: False)
  --dcam                Show driver monitoring camera (default: False)
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
```

Examples using route name to observe accelerometer and qcamera:

<<<<<<< HEAD
`./run.py --services accelerometer --qcam --route "a2a0ccea32023010/2023-07-27--13-01-19"`

Examples using segment range (more on [SegmentRange](https://github.com/commaai/openpilot/tree/master/tools/lib)):

`./run.py --qcam --route "a2a0ccea32023010/2023-07-27--13-01-19/2:4"`

## Cautions:
- You can specify `--services all` to visualize all `logMessage`, but it will draw a lot of memory usage and take a long time to log all messages. Rerun isn't ready for logging big number of data.

- Logging hevc videos (`--fcam`, `--ecam`, and `--dcam`)  are expensive, and it's recommended to use `--qcam` for optimized performance. If possible, limiting your route to a few segments using `SegmentRange` will speed up logging and reduce memory usage

This example draws 13GB of memory:

`./run.py --services accelerometer --qcam --route "a2a0ccea32023010/2023-07-27--13-01-19"`


## Openpilot services
To list all openpilot services:

`./run.py --print_services`

Examples including openpilot services:

`./run.py --services accelerometer cameraodometry --route "a2a0ccea32023010/2023-07-27--13-01-19/0/q"`

Examples including all services:

`./run.py --services all --route "a2a0ccea32023010/2023-07-27--13-01-19/0/q"`

## Demo
`./run.py --services accelerometer carcontrol caroutput --qcam --demo`
=======
`./run.sh --qcam "a2a0ccea32023010/2023-07-27--13-01-19"`

Examples using segment range (more on [SegmentRange](https://github.com/commaai/openpilot/tree/master/tools/lib)):

`./run.sh --qcam "a2a0ccea32023010/2023-07-27--13-01-19/2:4"`

## Cautions:
- Showing hevc videos (`--fcam`, `--ecam`, and `--dcam`)  are expensive, and it's recommended to use `--qcam` for optimized performance. If possible, limiting your route to a few segments using `SegmentRange` will speed up logging and reduce memory usage

## Demo
`./run.sh --qcam --demo`
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
