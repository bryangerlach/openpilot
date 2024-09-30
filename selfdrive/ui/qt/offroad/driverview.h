#pragma once

#include "selfdrive/ui/qt/widgets/cameraview.h"

class DriverViewWindow : public CameraWidget {
  Q_OBJECT

public:
  explicit DriverViewWindow(QWidget *parent);

signals:
  void done();

protected:
<<<<<<< HEAD
=======
  mat4 calcFrameMatrix() override;
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  void showEvent(QShowEvent *event) override;
  void hideEvent(QHideEvent *event) override;
  void paintGL() override;

  Params params;
  QPixmap face_img;
};
