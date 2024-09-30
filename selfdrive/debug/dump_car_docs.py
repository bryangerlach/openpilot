#!/usr/bin/env python3
import argparse
import pickle

<<<<<<< HEAD
from openpilot.selfdrive.car.docs import get_all_car_docs
=======
from opendbc.car.docs import get_all_car_docs
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e


def dump_car_docs(path):
  with open(path, 'wb') as f:
    pickle.dump(get_all_car_docs(), f)
  print(f'Dumping car info to {path}')


if __name__ == "__main__":
  parser = argparse.ArgumentParser()
  parser.add_argument("--path", required=True)
  args = parser.parse_args()
  dump_car_docs(args.path)
