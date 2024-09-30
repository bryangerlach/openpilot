#pragma once

#include <QWidget>

#include "selfdrive/ui/ui.h"

class OnroadAlerts : public QWidget {
  Q_OBJECT

public:
  OnroadAlerts(QWidget *parent = 0) : QWidget(parent) {}
  void updateState(const UIState &s);
  void clear();

protected:
  struct Alert {
    QString text1;
    QString text2;
    QString type;
<<<<<<< HEAD
    cereal::ControlsState::AlertSize size;
    cereal::ControlsState::AlertStatus status;
=======
    cereal::SelfdriveState::AlertSize size;
    cereal::SelfdriveState::AlertStatus status;
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

    bool equal(const Alert &other) const {
      return text1 == other.text1 && text2 == other.text2 && type == other.type;
    }
  };

<<<<<<< HEAD
  const QMap<cereal::ControlsState::AlertStatus, QColor> alert_colors = {
    {cereal::ControlsState::AlertStatus::NORMAL, QColor(0x15, 0x15, 0x15, 0xf1)},
    {cereal::ControlsState::AlertStatus::USER_PROMPT, QColor(0xDA, 0x6F, 0x25, 0xf1)},
    {cereal::ControlsState::AlertStatus::CRITICAL, QColor(0xC9, 0x22, 0x31, 0xf1)},
=======
  const QMap<cereal::SelfdriveState::AlertStatus, QColor> alert_colors = {
    {cereal::SelfdriveState::AlertStatus::NORMAL, QColor(0x15, 0x15, 0x15, 0xf1)},
    {cereal::SelfdriveState::AlertStatus::USER_PROMPT, QColor(0xDA, 0x6F, 0x25, 0xf1)},
    {cereal::SelfdriveState::AlertStatus::CRITICAL, QColor(0xC9, 0x22, 0x31, 0xf1)},
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  };

  void paintEvent(QPaintEvent*) override;
  OnroadAlerts::Alert getAlert(const SubMaster &sm, uint64_t started_frame);

  QColor bg;
  Alert alert = {};
};
