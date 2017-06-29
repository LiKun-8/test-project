#include "mywidget.h"

//extern int g_Flag;
MyWidget::MyWidget()
{
    m_ImageBtn = new QPushButton(this);
    m_ImageBtn->setFixedSize(64,64);
    m_ImageManager = new QNetworkAccessManager();
    m_ImagePix = new QPixmap();
    m_Flag = 0;
    connect(m_ImageManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(ReplyFinished(QNetworkReply*)),Qt::QueuedConnection);
}

void MyWidget::GetImage(QString imagePath)
{
    m_ImagePath = imagePath;
}

void MyWidget::ReplyFinished(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        m_ImagePix->loadFromData(reply->readAll());
        m_ImageBtn->setIcon(*m_ImagePix);
        m_ImageBtn->setIconSize(m_ImageBtn->size());
    }
    else
    {
        qDebug()<<"reply is error!"<<endl;
    }

    reply->deleteLater();
    m_ImageManager->deleteLater();
}
void MyWidget::paintEvent(QPaintEvent *event)
{
    if(m_Flag == 0 && m_ImagePath != NULL)
   {
        m_Flag++;
        m_ImageManager->get(QNetworkRequest(QUrl(m_ImagePath)));
    }
}
