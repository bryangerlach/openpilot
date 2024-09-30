<<<<<<< HEAD
#!/bin/bash
=======
#!/usr/bin/env bash
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

{
  #start pulseaudio daemon
  sudo pulseaudio -D

  # create a virtual null audio and set it to default device
  sudo pactl load-module module-null-sink sink_name=virtual_audio
  sudo pactl set-default-sink virtual_audio
} > /dev/null 2>&1
