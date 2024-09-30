#pragma once

#include <QPushButton>

#include "system/hardware/hw.h"
<<<<<<< HEAD
#ifdef SUNNYPILOT
#include "selfdrive/ui/sunnypilot/qt/widgets/controls.h"
#define ToggleControl ToggleControlSP
#define ButtonControl ButtonControlSP
#else
#include "selfdrive/ui/qt/widgets/controls.h"
#endif
=======
#include "selfdrive/ui/qt/widgets/controls.h"
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

// SSH enable toggle
class SshToggle : public ToggleControl {
  Q_OBJECT

public:
  SshToggle() : ToggleControl(tr("Enable SSH"), "", "", Hardware::get_ssh_enabled()) {
    QObject::connect(this, &SshToggle::toggleFlipped, [=](bool state) {
      Hardware::set_ssh_enabled(state);
    });
  }
};

// SSH key management widget
class SshControl : public ButtonControl {
  Q_OBJECT

public:
  SshControl();

private:
  Params params;

  void refresh();
  void getUserKeys(const QString &username);
};
