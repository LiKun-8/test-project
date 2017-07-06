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
#include "sharedata.h"

#define CATEGORIES  1
#define RELEASE     2
#define PRODUCTS    3

class JSONFUNC : public QObject
{
    Q_OBJECT

public:
    JSONFUNC(ShareData *shareData);
    void getCategoryNum();
    void getRelease(int array, int size);
    void setAppname();
    ShareData *jsonData;

protected slots:
    void jsonAnalysis(QNetworkReply *reply);

signals:
    void curlIsOk();
    void numIsOk(int num);
    void updateIsOk();

private:
    int jsonFlag;
    int categoryNum;
    QByteArray testArray;
    QNetworkAccessManager *manager;
    void getCategoryNum(QJsonObject obj);
    void getProducts(QJsonObject obj);
    void getRelease(QJsonObject obj);
    QString releaseStr;
};

#endif // JSONFUNCH
