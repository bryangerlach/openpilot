<<<<<<< HEAD
#!/bin/bash
=======
#!/usr/bin/env bash
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

echo "compressing training guide images"
optipng -o7 -strip all training/*

# This can sometimes provide smaller images
# mogrify -quality 100 -format jpg training/*
