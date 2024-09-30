#include <QApplication>
#include <QtWidgets>

#include "selfdrive/ui/qt/qt_window.h"
#include "selfdrive/ui/qt/util.h"
#include "selfdrive/ui/qt/widgets/cameraview.h"

int main(int argc, char *argv[]) {
  initApp(argc, argv);

  QApplication a(argc, argv);
  QWidget w;
  setMainWindow(&w);

  QVBoxLayout *layout = new QVBoxLayout(&w);
  layout->setMargin(0);
  layout->setSpacing(0);

  {
    QHBoxLayout *hlayout = new QHBoxLayout();
    layout->addLayout(hlayout);
<<<<<<< HEAD
    hlayout->addWidget(new CameraWidget("navd", VISION_STREAM_MAP, false));
    hlayout->addWidget(new CameraWidget("camerad", VISION_STREAM_ROAD, false));
=======
    hlayout->addWidget(new CameraWidget("camerad", VISION_STREAM_ROAD));
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  }

  {
    QHBoxLayout *hlayout = new QHBoxLayout();
    layout->addLayout(hlayout);
<<<<<<< HEAD
    hlayout->addWidget(new CameraWidget("camerad", VISION_STREAM_DRIVER, false));
    hlayout->addWidget(new CameraWidget("camerad", VISION_STREAM_WIDE_ROAD, false));
=======
    hlayout->addWidget(new CameraWidget("camerad", VISION_STREAM_DRIVER));
    hlayout->addWidget(new CameraWidget("camerad", VISION_STREAM_WIDE_ROAD));
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  }

  return a.exec();
}
