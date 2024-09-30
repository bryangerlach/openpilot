<<<<<<< HEAD
#!/bin/bash
=======
#!/usr/bin/env bash
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
clang++ -I /home/batman/one/external/tensorflow/include/ -L /home/batman/one/external/tensorflow/lib -Wl,-rpath=/home/batman/one/external/tensorflow/lib main.cc -ltensorflow
