#include "thread.h"

testthread::testthread()
{
    manager = new QNetworkAccessManager();
    image = new QPixmap();
//    imageBtn  = new QPushButton();
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)),Qt::QueuedConnection);

}

testthread::~testthread()
{

}

void testthread::run()
{
//    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)),Qt::QueuedConnection);
    manager->get(QNetworkRequest(QUrl(imagePath)));
    exec();
}

void testthread::getInfo(QString &string, QPushButton *btn)
{
    imageBtn = btn;
    imagePath = string;
}

void testthread::replyFinished(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        image->loadFromData(reply->readAll());
        imageBtn->setIcon(*image);
        imageBtn->setIconSize(imageBtn->size());
    }
}
