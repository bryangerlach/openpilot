#pragma once

#include <QJsonObject>
#include <QNetworkReply>
#include <QString>
#include <QTimer>

#include "common/util.h"
<<<<<<< HEAD
#include "selfdrive/ui/qt/util.h"
=======
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

namespace CommaApi {

const QString BASE_URL = util::getenv("API_HOST", "https://api.commadotai.com").c_str();
QByteArray rsa_sign(const QByteArray &data);
QString create_jwt(const QJsonObject &payloads = {}, int expiry = 3600);

}  // namespace CommaApi

/**
 * Makes a request to the request endpoint.
 */

class HttpRequest : public QObject {
  Q_OBJECT

public:
<<<<<<< HEAD
  enum class Method {GET, DELETE, POST, PUT};

  explicit HttpRequest(QObject* parent, bool create_jwt = true, int timeout = 20000);
  virtual void sendRequest(const QString &requestURL, Method method);
  void sendRequest(const QString &requestURL) { sendRequest(requestURL, Method::GET);}
=======
  enum class Method {GET, DELETE};

  explicit HttpRequest(QObject* parent, bool create_jwt = true, int timeout = 20000);
  void sendRequest(const QString &requestURL, const Method method = Method::GET);
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  bool active() const;
  bool timeout() const;

signals:
  void requestDone(const QString &response, bool success, QNetworkReply::NetworkError error);

protected:
  QNetworkReply *reply = nullptr;
<<<<<<< HEAD
  static QNetworkAccessManager *nam();
  QTimer *networkTimer = nullptr;
  bool create_jwt;
  virtual QNetworkRequest prepareRequest(const QString& requestURL);
  virtual QString GetJwtToken() const { return CommaApi::create_jwt(); }
  virtual QString GetUserAgent() const { return getUserAgent(); }

protected slots:
=======

private:
  static QNetworkAccessManager *nam();
  QTimer *networkTimer = nullptr;
  bool create_jwt;

private slots:
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  void requestTimeout();
  void requestFinished();
};
