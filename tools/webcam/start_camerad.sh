<<<<<<< HEAD
#!/bin/bash
=======
#!/usr/bin/env bash
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

# export the block below when call manager.py
export BLOCK="${BLOCK},camerad"
export USE_WEBCAM="1"

# Change camera index according to your setting
export CAMERA_ROAD_ID="0"
export CAMERA_DRIVER_ID="1"
export DUAL_CAMERA="2" # camera index for wide road camera

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

$DIR/camerad.py
