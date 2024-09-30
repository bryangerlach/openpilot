<<<<<<< HEAD
#!/bin/bash

while read hash submodule ref; do
  git -C $submodule fetch --depth 3000 origin master
=======
#!/usr/bin/env bash

while read hash submodule ref; do
  git -C $submodule fetch --depth 4000 origin master
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  git -C $submodule branch -r --contains $hash | grep "origin/master"
  if [ "$?" -eq 0 ]; then
    echo "$submodule ok"
  else
    echo "$submodule: $hash is not on master"
    exit 1
  fi
done <<< $(git submodule status --recursive)
