#pragma once

#include <QMovie>
#include <QLabel>
#include <QPushButton>

#include "common/util.h"
<<<<<<< HEAD
#ifdef SUNNYPILOT
#include "selfdrive/ui/sunnypilot/ui.h"
#else
#include "selfdrive/ui/ui.h"
#endif
=======
#include "selfdrive/ui/ui.h"
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

class RecordButton : public QPushButton {
  Q_OBJECT

public:
  RecordButton(QWidget* parent = 0);

private:
  void paintEvent(QPaintEvent*) override;
};

class BodyWindow : public QWidget {
  Q_OBJECT

public:
  BodyWindow(QWidget* parent = 0);

private:
  bool charging = false;
  uint64_t last_button = 0;
  FirstOrderFilter fuel_filter;
  QLabel *face;
  QMovie *awake, *sleep;
  RecordButton *btn;
  void paintEvent(QPaintEvent*) override;

private slots:
  void updateState(const UIState &s);
  void offroadTransition(bool onroad);
};
