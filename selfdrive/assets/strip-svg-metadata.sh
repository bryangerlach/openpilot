<<<<<<< HEAD
#!/bin/bash
=======
#!/usr/bin/env bash
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

# sudo apt install scour

for svg in $(find icons/ -type f | grep svg$); do
  # scour doesn't support overwriting input file
  scour $svg --remove-metadata $svg.tmp
  mv $svg.tmp $svg
done
