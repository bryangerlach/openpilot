#pragma once

#include <map>
#include <string>

#include <QButtonGroup>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QWidget>

<<<<<<< HEAD
#include "selfdrive/ui/qt/util.h"

#ifdef SUNNYPILOT
#include "selfdrive/ui/sunnypilot/ui.h"
#include "selfdrive/ui/sunnypilot/qt/widgets/controls.h"
#define ListWidget ListWidgetSP
#define ParamControl ParamControlSP
#define ButtonControl ButtonControlSP
#define ButtonParamControl ButtonParamControlSP
#define ToggleControl ToggleControlSP
#define LabelControl LabelControlSP
#else
#include "selfdrive/ui/ui.h"
#include "selfdrive/ui/qt/widgets/controls.h"
#endif
=======
#include "selfdrive/ui/ui.h"
#include "selfdrive/ui/qt/util.h"
#include "selfdrive/ui/qt/widgets/controls.h"
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

// ********** settings window + top-level panels **********
class SettingsWindow : public QFrame {
  Q_OBJECT

public:
  explicit SettingsWindow(QWidget *parent = 0);
  void setCurrentPanel(int index, const QString &param = "");

protected:
  void showEvent(QShowEvent *event) override;

signals:
  void closeSettings();
  void reviewTrainingGuide();
  void showDriverView();
  void expandToggleDescription(const QString &param);

<<<<<<< HEAD
protected:
=======
private:
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  QPushButton *sidebar_alert_widget;
  QWidget *sidebar_widget;
  QButtonGroup *nav_btns;
  QStackedWidget *panel_widget;
};

class DevicePanel : public ListWidget {
  Q_OBJECT
public:
  explicit DevicePanel(SettingsWindow *parent);
<<<<<<< HEAD
  void showEvent(QShowEvent *event) override;
=======
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

signals:
  void reviewTrainingGuide();
  void showDriverView();

<<<<<<< HEAD
protected slots:
=======
private slots:
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  void poweroff();
  void reboot();
  void updateCalibDescription();

<<<<<<< HEAD
protected:
  Params params;
  ButtonControl *pair_device;
  QHBoxLayout *power_layout;
=======
private:
  Params params;
  ButtonControl *pair_device;
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
};

class TogglesPanel : public ListWidget {
  Q_OBJECT
public:
  explicit TogglesPanel(SettingsWindow *parent);
  void showEvent(QShowEvent *event) override;

public slots:
  void expandToggleDescription(const QString &param);

<<<<<<< HEAD
protected slots:
  virtual void updateState(const UIState &s);

protected:
=======
private slots:
  void updateState(const UIState &s);

private:
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  Params params;
  std::map<std::string, ParamControl*> toggles;
  ButtonParamControl *long_personality_setting;

<<<<<<< HEAD
  virtual void updateToggles();
=======
  void updateToggles();
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
};

class SoftwarePanel : public ListWidget {
  Q_OBJECT
public:
  explicit SoftwarePanel(QWidget* parent = nullptr);

<<<<<<< HEAD
protected:
  void showEvent(QShowEvent *event) override;
  virtual void updateLabels();
=======
private:
  void showEvent(QShowEvent *event) override;
  void updateLabels();
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  void checkForUpdates();

  bool is_onroad = false;

  QLabel *onroadLbl;
  LabelControl *versionLbl;
  ButtonControl *installBtn;
  ButtonControl *downloadBtn;
  ButtonControl *targetBranchBtn;

  Params params;
  ParamWatcher *fs_watch;
};
