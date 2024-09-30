#include "selfdrive/ui/qt/request_repeater.h"

RequestRepeater::RequestRepeater(QObject *parent, const QString &requestURL, const QString &cacheKey,
                                 int period, bool while_onroad) : HttpRequest(parent) {
  timer = new QTimer(this);
  timer->setTimerType(Qt::VeryCoarseTimer);
<<<<<<< HEAD

  connectTimer(requestURL, while_onroad);

  timer->start(period * 1000);

  setupCacheProcess(cacheKey);
}

void RequestRepeater::connectTimer(const QString &requestURL, bool while_onroad) {
=======
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  QObject::connect(timer, &QTimer::timeout, [=]() {
    if ((!uiState()->scene.started || while_onroad) && device()->isAwake() && !active()) {
      sendRequest(requestURL);
    }
  });
<<<<<<< HEAD
}

void RequestRepeater::setupCacheProcess(const QString &cacheKey) {
=======

  timer->start(period * 1000);

>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  if (!cacheKey.isEmpty()) {
    prevResp = QString::fromStdString(params.get(cacheKey.toStdString()));
    if (!prevResp.isEmpty()) {
      QTimer::singleShot(500, [=]() { emit requestDone(prevResp, true, QNetworkReply::NoError); });
    }
    QObject::connect(this, &HttpRequest::requestDone, [=](const QString &resp, bool success) {
      if (success && resp != prevResp) {
        params.put(cacheKey.toStdString(), resp.toStdString());
        prevResp = resp;
      }
    });
  }
}
