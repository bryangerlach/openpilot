#pragma once

#include <QStackedLayout>
#include <QWidget>

#include "selfdrive/ui/qt/home.h"
#include "selfdrive/ui/qt/offroad/onboarding.h"
#include "selfdrive/ui/qt/offroad/settings.h"

class MainWindow : public QWidget {
  Q_OBJECT

public:
<<<<<<< HEAD
  explicit MainWindow(QWidget *parent = nullptr) : MainWindow(parent, nullptr, nullptr, nullptr) {}

protected:
  explicit MainWindow(QWidget* parent, HomeWindow* hw = nullptr, SettingsWindow* sw = nullptr, OnboardingWindow* ow = nullptr);
  HomeWindow *homeWindow;
  SettingsWindow *settingsWindow;
  OnboardingWindow *onboardingWindow;
  virtual void closeSettings();
=======
  explicit MainWindow(QWidget *parent = 0);
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

private:
  bool eventFilter(QObject *obj, QEvent *event) override;
  void openSettings(int index = 0, const QString &param = "");
<<<<<<< HEAD

  QStackedLayout *main_layout;
=======
  void closeSettings();

  QStackedLayout *main_layout;
  HomeWindow *homeWindow;
  SettingsWindow *settingsWindow;
  OnboardingWindow *onboardingWindow;
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
};
