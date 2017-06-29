#ifndef THREAD_H
#define THREAD_H
#include <QThread>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QPushButton>
#include <QtNetwork/QNetworkRequest>
#include <QPixmap>
#include <QUrl>
#include <QByteArray>
#include <QGridLayout>
#include <QDebug>

class testthread : public QThread
{
public:
    testthread();
    ~testthread();
    void run();
    QNetworkAccessManager *manager;
    QPixmap *image;
    QString imagePath;
    QPushButton *imageBtn;

    void getInfo(QString &string,QPushButton *btn);

protected slots:
    void replyFinished(QNetworkReply *reply);
};

#endif // THREAD_H
