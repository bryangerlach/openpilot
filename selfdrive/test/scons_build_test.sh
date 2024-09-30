<<<<<<< HEAD
#!/bin/bash
=======
#!/usr/bin/env bash
set -e
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

SCRIPT_DIR=$(dirname "$0")
BASEDIR=$(realpath "$SCRIPT_DIR/../../")
cd $BASEDIR

<<<<<<< HEAD
# tests that our build system's dependencies are configured properly, 
# needs a machine with lots of cores
scons --clean
scons --no-cache --random -j$(nproc)
=======
# tests that our build system's dependencies are configured properly,
# needs a machine with lots of cores

# helpful commands:
# scons -Q --tree=derived

cd $BASEDIR/opendbc_repo/
scons --clean
scons --no-cache --random -j$(nproc)
if ! scons -q; then
  echo "FAILED: all build products not up to date after first pass."
  exit 1
fi
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
