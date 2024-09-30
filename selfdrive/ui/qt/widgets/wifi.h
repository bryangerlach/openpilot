#pragma once

#include <QFrame>
#include <QStackedLayout>
#include <QWidget>

<<<<<<< HEAD
#ifdef SUNNYPILOT
#include "selfdrive/ui/sunnypilot/ui.h"
#else
#include "selfdrive/ui/ui.h"
#endif
=======
#include "selfdrive/ui/ui.h"
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

class WiFiPromptWidget : public QFrame {
  Q_OBJECT

public:
  explicit WiFiPromptWidget(QWidget* parent = 0);

signals:
  void openSettings(int index = 0, const QString &param = "");

public slots:
  void updateState(const UIState &s);

protected:
  QStackedLayout *stack;
};
