#pragma once

#include "selfdrive/ui/qt/onroad/alerts.h"
<<<<<<< HEAD

#if SUNNYPILOT
#include "selfdrive/ui/sunnypilot/qt/onroad/annotated_camera.h"
#define AnnotatedCameraWidget AnnotatedCameraWidgetSP
#define UIState UIStateSP
#else
#include "selfdrive/ui/qt/onroad/annotated_camera.h"
#endif
=======
#include "selfdrive/ui/qt/onroad/annotated_camera.h"
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

class OnroadWindow : public QWidget {
  Q_OBJECT

public:
  OnroadWindow(QWidget* parent = 0);

<<<<<<< HEAD
protected:
  void paintEvent(QPaintEvent *event) override;
=======
private:
  void paintEvent(QPaintEvent *event);
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  OnroadAlerts *alerts;
  AnnotatedCameraWidget *nvg;
  QColor bg = bg_colors[STATUS_DISENGAGED];
  QHBoxLayout* split;

<<<<<<< HEAD
protected slots:
  virtual void offroadTransition(bool offroad);
  virtual void updateState(const UIState &s);
=======
private slots:
  void offroadTransition(bool offroad);
  void updateState(const UIState &s);
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
};
