#!/usr/bin/env python3
<<<<<<< HEAD
from openpilot.selfdrive.car.values import BRANDS
=======
from opendbc.car.values import BRANDS
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

for brand in BRANDS:
  all_flags = set()
  for platform in brand:
    if platform.config.flags != 0:
      all_flags |= set(platform.config.flags)

  if len(all_flags):
    print(brand.__module__.split('.')[-2].upper() + ':')
    for flag in sorted(all_flags):
      print(f'  {flag.name:<24}:', {platform.name for platform in brand.with_flags(flag)})
    print()
