#pragma once

#include <QPushButton>

<<<<<<< HEAD
#ifdef SUNNYPILOT
#include "selfdrive/ui/sunnypilot/ui.h"
#else
#include "selfdrive/ui/ui.h"
#endif
=======
#include "selfdrive/ui/ui.h"
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

const int btn_size = 192;
const int img_size = (btn_size / 4) * 3;

class ExperimentalButton : public QPushButton {
  Q_OBJECT

public:
  explicit ExperimentalButton(QWidget *parent = 0);
  void updateState(const UIState &s);

<<<<<<< HEAD
protected:
  bool experimental_mode;
  bool engageable;

=======
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
private:
  void paintEvent(QPaintEvent *event) override;
  void changeMode();

  Params params;
  QPixmap engage_img;
  QPixmap experimental_img;
<<<<<<< HEAD
=======
  bool experimental_mode;
  bool engageable;
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
};

void drawIcon(QPainter &p, const QPoint &center, const QPixmap &img, const QBrush &bg, float opacity);
