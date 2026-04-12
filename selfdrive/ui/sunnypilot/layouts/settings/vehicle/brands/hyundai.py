"""
Copyright (c) 2021-, Haibin Wen, sunnypilot, and a number of other contributors.

This file is part of sunnypilot and is licensed under the MIT License.
See the LICENSE.md file in the root directory for more details.
"""
from openpilot.selfdrive.ui.sunnypilot.layouts.settings.vehicle.brands.base import BrandSettings
from openpilot.selfdrive.ui.ui_state import ui_state
from openpilot.system.ui.lib.multilang import tr
from openpilot.system.ui.sunnypilot.widgets.list_view import multiple_button_item_sp, option_item_sp
from opendbc.car.hyundai.values import CAR, UNSUPPORTED_LONGITUDINAL_CAR


class HyundaiSettings(BrandSettings):
  def __init__(self):
    super().__init__()
    self.alpha_long_available = False

    tuning_texts = [tr("Off"), tr("Dynamic"), tr("Predictive")]
    self.longitudinal_tuning_item = multiple_button_item_sp(tr("Custom Longitudinal Tuning"), "", tuning_texts,
                                                            button_width=300, callback=self._on_tuning_selected,
                                                            param="HyundaiLongitudinalTuning", inline=False)

    self.steer_max_item = option_item_sp(
      title=lambda: tr("Max Steering Torque"),
      min_val=100, max_val=400, value_chagne_step=5,
      param="CustomSteerMax",
      unit=""
    )
    self.steer_allowance_item = option_item_sp(
      title=lambda: tr("CustomAllowance"),
      min_val=50, max_val=250, value_chagne_step=50,
      param="CustomAllowance",
      unit=""
    )
    self.steer_threshold_item = option_item_sp(
      title=lambda: tr("Steering Threshold"),
      min_val=50, max_val=250, value_chagne_step=50,
      param="CustomThreshold",
      unit=""
    )
    self.steer_delta_up_item = option_item_sp(
      title=lambda: tr("Steer Delta Up"),
      min_val=1, max_val=4, value_chagne_step=1,
      param="CustomDeltaUp",
      unit=""
    )
    self.steer_delta_down_item = option_item_sp(
      title=lambda: tr("Steer Delta Down"),
      min_val=2, max_val=7, value_chagne_step=1,
      param="CustomDeltaDown",
      unit=""
    )
    self.items = [self.longitudinal_tuning_item, self.steer_max_item, self.steer_allowance_item,
                  self.steer_delta_down_item, self.steer_delta_up_item, self.steer_threshold_item]

  @staticmethod
  def _on_tuning_selected(index):
    ui_state.params.put("HyundaiLongitudinalTuning", index)

  def update_settings(self):
    self.alpha_long_available = False
    bundle = ui_state.params.get("CarPlatformBundle")
    if bundle:
      platform = bundle.get("platform")
      self.alpha_long_available = CAR[platform] not in set().union(*UNSUPPORTED_LONGITUDINAL_CAR.values())
    elif ui_state.CP is not None:
      self.alpha_long_available = ui_state.CP.alphaLongitudinalAvailable

    tuning_param = int(ui_state.params.get("HyundaiLongitudinalTuning") or "0")
    long_enabled = ui_state.has_longitudinal_control

    long_tuning_descs = [
      tr("Your vehicle will use the Default longitudinal tuning."),
      tr("Your vehicle will use the Dynamic longitudinal tuning."),
      tr("Your vehicle will use the Predictive longitudinal tuning."),
    ]
    long_tuning_desc = long_tuning_descs[tuning_param] if tuning_param < len(long_tuning_descs) else long_tuning_descs[0]

    longitudinal_tuning_disabled = not ui_state.is_offroad() or not long_enabled
    if longitudinal_tuning_disabled:
      if not ui_state.is_offroad():
        long_tuning_desc = tr("This feature is unavailable while the car is onroad.")
      elif not long_enabled:
        long_tuning_desc = tr("This feature is unavailable because sunnypilot Longitudinal Control (Alpha) is not enabled.")

    # custom settings
    self.steer_max_item.set_visible(True)
    self.steer_allowance_item.set_visible(True)
    self.steer_delta_down_item.set_visible(True)
    self.steer_delta_up_item.set_visible(True)
    self.steer_threshold_item.set_visible(True)
    self.steer_max_item.set_enabled(True)
    self.steer_allowance_item.set_enabled(True)
    self.steer_delta_down_item.set_enabled(True)
    self.steer_delta_up_item.set_enabled(True)
    self.steer_threshold_item.set_enabled(True)

    self.longitudinal_tuning_item.action_item.set_enabled(not longitudinal_tuning_disabled)
    self.longitudinal_tuning_item.set_description(long_tuning_desc)
    self.longitudinal_tuning_item.show_description(True)
    self.longitudinal_tuning_item.action_item.set_selected_button(tuning_param)
    self.longitudinal_tuning_item.set_visible(self.alpha_long_available)
