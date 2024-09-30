#!/usr/bin/env python3
from collections import Counter
from pprint import pprint

<<<<<<< HEAD
from openpilot.selfdrive.car.docs import get_all_car_docs
=======
from opendbc.car.docs import get_all_car_docs
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

if __name__ == "__main__":
  cars = get_all_car_docs()
  make_count = Counter(l.make for l in cars)
  print("\n", "*" * 20, len(cars), "total", "*" * 20, "\n")
  pprint(make_count)
