#!/usr/bin/env python3
<<<<<<< HEAD
import os
import numpy as np
=======
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
from cereal import car
from openpilot.common.params import Params
from openpilot.common.realtime import Priority, config_realtime_process
from openpilot.common.swaglog import cloudlog
<<<<<<< HEAD
from openpilot.selfdrive.modeld.constants import ModelConstants
from openpilot.selfdrive.controls.lib.longitudinal_planner import LongitudinalPlanner
from openpilot.selfdrive.controls.lib.lateral_planner import LateralPlanner
from openpilot.selfdrive.modeld.custom_model_metadata import CustomModelMetadata, ModelCapabilities
import cereal.messaging as messaging


def plannerd_thread():
=======
from openpilot.selfdrive.controls.lib.ldw import LaneDepartureWarning
from openpilot.selfdrive.controls.lib.longitudinal_planner import LongitudinalPlanner
import cereal.messaging as messaging


def main():
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  config_realtime_process(5, Priority.CTRL_LOW)

  cloudlog.info("plannerd is waiting for CarParams")
  params = Params()
  CP = messaging.log_from_bytes(params.get("CarParams", block=True), car.CarParams)
  cloudlog.info("plannerd got CarParams: %s", CP.carName)

<<<<<<< HEAD
  debug_mode = bool(int(os.getenv("DEBUG", "0")))

  longitudinal_planner = LongitudinalPlanner(CP)

  custom_model_metadata = CustomModelMetadata(params=params, init_only=True)
  model_use_lateral_planner = custom_model_metadata.valid and custom_model_metadata.capabilities & ModelCapabilities.LateralPlannerSolution
  lateral_planner = LateralPlanner(CP, debug=debug_mode, model_use_lateral_planner=model_use_lateral_planner)
  lateral_planner_svs = ['lateralPlanDEPRECATED', 'lateralPlanSPDEPRECATED']

  pm = messaging.PubMaster(['longitudinalPlan', 'longitudinalPlanSP'] + lateral_planner_svs)
  sm = messaging.SubMaster(['carControl', 'carState', 'controlsState', 'radarState', 'modelV2',
                            'longitudinalPlan', 'navInstruction', 'longitudinalPlanSP',
                            'liveMapDataSP', 'e2eLongStateSP', 'controlsStateSP'] + lateral_planner_svs,
=======
  ldw = LaneDepartureWarning()
  longitudinal_planner = LongitudinalPlanner(CP)
  pm = messaging.PubMaster(['longitudinalPlan', 'driverAssistance'])
  sm = messaging.SubMaster(['carControl', 'carState', 'controlsState', 'radarState', 'modelV2', 'selfdriveState'],
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
                           poll='modelV2', ignore_avg_freq=['radarState'])

  while True:
    sm.update()
    if sm.updated['modelV2']:
<<<<<<< HEAD
      lateral_planner.update(sm)
      lateral_planner.publish(sm, pm)
      longitudinal_planner.update(sm)
      longitudinal_planner.publish(sm, pm)


def main():
  plannerd_thread()
=======
      longitudinal_planner.update(sm)
      longitudinal_planner.publish(sm, pm)

      ldw.update(sm.frame, sm['modelV2'], sm['carState'], sm['carControl'])
      msg = messaging.new_message('driverAssistance')
      msg.valid = sm.all_checks(['carState', 'carControl', 'modelV2'])
      msg.driverAssistance.leftLaneDeparture = ldw.left
      msg.driverAssistance.rightLaneDeparture = ldw.right
      pm.send('driverAssistance', msg)
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e


if __name__ == "__main__":
  main()
