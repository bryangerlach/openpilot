#pragma once

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QStackedLayout>
#include <QTimer>
#include <QWidget>

#include "common/params.h"
#include "selfdrive/ui/qt/offroad/driverview.h"
#include "selfdrive/ui/qt/body.h"
#include "selfdrive/ui/qt/onroad/onroad_home.h"
#include "selfdrive/ui/qt/sidebar.h"
<<<<<<< HEAD
#include "selfdrive/ui/qt/widgets/offroad_alerts.h"
#include "selfdrive/ui/ui.h"

#ifdef SUNNYPILOT
#include "selfdrive/ui/sunnypilot/qt/widgets/controls.h"
#include "selfdrive/ui/sunnypilot/qt/offroad_home.h"
#include "selfdrive/ui/sunnypilot/qt/onroad/onroad_home.h"
#define OnroadWindow OnroadWindowSP
#define OffroadHome OffroadHomeSP
#else
#include "selfdrive/ui/qt/widgets/controls.h"
#include "selfdrive/ui/qt/onroad/onroad_home.h"
#include "selfdrive/ui/qt/offroad_home.h"
#endif
=======
#include "selfdrive/ui/qt/widgets/controls.h"
#include "selfdrive/ui/qt/widgets/offroad_alerts.h"
#include "selfdrive/ui/ui.h"

class OffroadHome : public QFrame {
  Q_OBJECT

public:
  explicit OffroadHome(QWidget* parent = 0);

signals:
  void openSettings(int index = 0, const QString &param = "");

private:
  void showEvent(QShowEvent *event) override;
  void hideEvent(QHideEvent *event) override;
  void refresh();

  Params params;

  QTimer* timer;
  ElidedLabel* version;
  QStackedLayout* center_layout;
  UpdateAlert *update_widget;
  OffroadAlert* alerts_widget;
  QPushButton* alert_notif;
  QPushButton* update_notif;
};
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

class HomeWindow : public QWidget {
  Q_OBJECT

public:
  explicit HomeWindow(QWidget* parent = 0);

signals:
  void openSettings(int index = 0, const QString &param = "");
  void closeSettings();

public slots:
  void offroadTransition(bool offroad);
  void showDriverView(bool show);
  void showSidebar(bool show);

protected:
  void mousePressEvent(QMouseEvent* e) override;
  void mouseDoubleClickEvent(QMouseEvent* e) override;

<<<<<<< HEAD
=======
private:
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  Sidebar *sidebar;
  OffroadHome *home;
  OnroadWindow *onroad;
  BodyWindow *body;
  DriverViewWindow *driver_view;
  QStackedLayout *slayout;

<<<<<<< HEAD
protected slots:
  virtual void updateState(const UIState &s);
=======
private slots:
  void updateState(const UIState &s);
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
};
