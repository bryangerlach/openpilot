#pragma once

#include <optional>
#include <vector>

#include <QDateTime>
#include <QFileSystemWatcher>
#include <QPainter>
#include <QPixmap>
#include <QSurfaceFormat>
#include <QWidget>

#include "cereal/gen/cpp/car.capnp.h"
#include "common/params.h"

<<<<<<< HEAD
#ifdef SUNNYPILOT
#define RETURN_IF_SUNNYPILOT return;
#else
#define RETURN_IF_SUNNYPILOT // Do nothing
#endif

QString getVersion();
QString getBrand();
QString getUserAgent();
std::optional<QString> getParamIgnoringDefault(const std::string &param_name, const std::string &default_value);
std::optional<QString> getDongleId();
QMap<QString, QString> getFromJsonFile(const QString &path);
=======
QString getVersion();
QString getBrand();
QString getUserAgent();
std::optional<QString> getDongleId();
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
QMap<QString, QString> getSupportedLanguages();
void setQtSurfaceFormat();
void sigTermHandler(int s);
QString timeAgo(const QDateTime &date);
void swagLogMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
void initApp(int argc, char *argv[], bool disable_hidpi = true);
QWidget* topWidget(QWidget* widget);
QPixmap loadPixmap(const QString &fileName, const QSize &size = {}, Qt::AspectRatioMode aspectRatioMode = Qt::KeepAspectRatio);
QPixmap bootstrapPixmap(const QString &id);
bool hasLongitudinalControl(const cereal::CarParams::Reader &car_params);

struct InterFont : public QFont {
  InterFont(int pixel_size, QFont::Weight weight = QFont::Normal) : QFont("Inter") {
    setPixelSize(pixel_size);
    setWeight(weight);
  }
};

class ParamWatcher : public QObject {
  Q_OBJECT

public:
  ParamWatcher(QObject *parent);
  void addParam(const QString &param_name);

signals:
  void paramChanged(const QString &param_name, const QString &param_value);

private:
  void fileChanged(const QString &path);

  QFileSystemWatcher *watcher;
  QHash<QString, QString> params_hash;
  Params params;
};
