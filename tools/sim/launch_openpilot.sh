<<<<<<< HEAD
#!/bin/bash
=======
#!/usr/bin/env bash
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

export PASSIVE="0"
export NOBOARD="1"
export SIMULATION="1"
export SKIP_FW_QUERY="1"
export FINGERPRINT="HONDA_CIVIC_2022"

export BLOCK="${BLOCK},camerad,loggerd,encoderd,micd,logmessaged"
if [[ "$CI" ]]; then
  # TODO: offscreen UI should work
  export BLOCK="${BLOCK},ui"
fi

<<<<<<< HEAD
python -c "from openpilot.selfdrive.test.helpers import set_params_enabled; set_params_enabled()"
=======
python3 -c "from openpilot.selfdrive.test.helpers import set_params_enabled; set_params_enabled()"
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

SCRIPT_DIR=$(dirname "$0")
OPENPILOT_DIR=$SCRIPT_DIR/../../

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
cd $OPENPILOT_DIR/system/manager && exec ./manager.py
