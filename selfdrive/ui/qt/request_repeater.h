#pragma once

#include "common/util.h"
<<<<<<< HEAD

#ifdef SUNNYPILOT
#include "selfdrive/ui/sunnypilot/ui.h"
#include "selfdrive/ui/sunnypilot/qt/api.h"
#else
#include "selfdrive/ui/ui.h"
#include "selfdrive/ui/qt/api.h"
#endif

class RequestRepeater : public HttpRequest {
public:
  void connectTimer(const QString& requestURL, bool while_onroad);
  void setupCacheProcess(const QString& cacheKey);
=======
#include "selfdrive/ui/qt/api.h"
#include "selfdrive/ui/ui.h"

class RequestRepeater : public HttpRequest {
public:
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  RequestRepeater(QObject *parent, const QString &requestURL, const QString &cacheKey = "", int period = 0, bool while_onroad=false);

private:
  Params params;
  QTimer *timer;
  QString prevResp;
};
