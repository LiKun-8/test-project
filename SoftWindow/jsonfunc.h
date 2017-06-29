#ifndef JSONFUNCH
#define JSONFUNCH

#include <QObject>
#include <QProcess>
#include <QByteArray>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMap>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include "softthread.h"

#define CATEGORIES  1
#define RELEASE     2
#define PRODUCTS    3



class JSONFUNC : public QObject
{
    Q_OBJECT

public:
    JSONFUNC(ShareData *shareData);
    int GetCategoryNum();
    void GetRelease();
    void SetAppname();
    ShareData *jsonData;

protected slots:
    void JsonAnalysis(QNetworkReply *reply);

signals:
    void CurlIsOk();
    void NumIsOk(int num);


private:
    int jsonFlag;
    int categoryNum;
    QByteArray testArray;
    QNetworkAccessManager *manager;
};

#endif // JSONFUNCH
