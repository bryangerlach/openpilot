<<<<<<< HEAD
#!/bin/bash
=======
#!/usr/bin/env bash
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

SCRIPT_DIR=$(dirname "$0")
BASEDIR=$(realpath "$SCRIPT_DIR/../../../")
cd $BASEDIR

<<<<<<< HEAD
MAX_EXAMPLES=300
INTERNAL_SEG_CNT=300
FILEREADER_CACHE=1
INTERNAL_SEG_LIST=selfdrive/car/tests/test_models_segs.txt

cd selfdrive/car/tests && pytest test_models.py test_car_interfaces.py
=======
export MAX_EXAMPLES=300
export INTERNAL_SEG_CNT=300
export FILEREADER_CACHE=1
export INTERNAL_SEG_LIST=selfdrive/car/tests/test_models_segs.txt

cd selfdrive/car/tests && pytest test_models.py test_car_interfaces.py
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
