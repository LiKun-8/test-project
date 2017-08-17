#include "detailwidget.h"
#include <QQuickWidget>
#include <QLabel>
#include <QPushButton>
#include <QQuickWidget>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QQmlEngine>
#include <QProgressBar>
#include <QGridLayout>
#include <QScrollArea>
#include "sharedata.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "jsonfunc.h"
#include <QCoreApplication>
#include <QtMath>

DetailWidget::DetailWidget(QWidget *parent,ShareData *sdata,JSONFUNC *jsonData) : QWidget(parent)
{
    shareData = sdata;
    jsonFunc = jsonData;
    initialWidgets();
    layoutWidgets();
}

void DetailWidget::initialWidgets()
{
    lbProductImg = new QLabel(this);
    lbProductImg->resize(128,128);

    lbProductName = new QLabel(this);
    lbProductName->setText("yinyue");

    lbComment = new QLabel(tr("Comment:"),this);
    lbCommentStar = new QLabel[5];
    lbCommentMark = new QLabel(this);
    lbProductVersion = new QLabel(tr("Version:"),this);
    lbVersionNo = new QLabel(this);
    lbProductSize = new QLabel(tr("Size:"),this);
    lbSizeValue = new QLabel(this);
    btnState = new QPushButton(this);

    lbAppInfo = new QLabel(this);
    lbAppInfo->setText(tr("Application Introduction"));
    lbAppInfoDetail = new QLabel(this);
    QString appInfo("qq yinyue");
    lbAppInfoDetail->setText(tr(appInfo.toLatin1()));

    lbUserComment = new QLabel(this);
    lbUserComment->setText(tr("User Comment Mark"));
    lbUserCommMark = new QLabel(this);
    lbUserCommStar = new QLabel(this);
    lbTotalCommenters = new QLabel(this);
    lbStarLevel1 = new QLabel(this);
    lbStarLevel2 = new QLabel(this);
    lbStarLevel3 = new QLabel(this);
    lbStarLevel4 = new QLabel(this);
    lbStarLevel5 = new QLabel(this);
    pbStarLevel1 = new QProgressBar(this);
    pbStarLevel2 = new QProgressBar(this);
    pbStarLevel3 = new QProgressBar(this);
    pbStarLevel4 = new QProgressBar(this);
    pbStarLevel5 = new QProgressBar(this);
    lbLevel1Users = new QLabel(this);
    lbLevel2Users = new QLabel(this);
    lbLevel3Users = new QLabel(this);
    lbLevel4Users = new QLabel(this);
    lbLevel5Users = new QLabel(this);

    lbmyMark = new QLabel(this);
    lbmyStarLevel = new QLabel(this);
    lbmyComment = new QLabel(this);
    teCommContent = new QTextEdit(this);
    teCommContent->setMaximumHeight(500);
    btnSubmit = new QPushButton(tr("submit"),this);
    btnCancel = new QPushButton(tr("Cancel"),this);

    qmlEnginer = new QQmlEngine;
    imgBoxer = new QQuickWidget(qmlEnginer,this);
    userCommBoxer = new QQuickWidget(qmlEnginer,this);

    imgBoxer->setSource(QUrl::fromLocalFile(":/Imgboxer.qml"));
//    imgBoxer->resize(940,200);


    userCommBoxer->setSource(QUrl::fromLocalFile(":/Comment.qml"));
//    userCommBoxer->resize(940,1000);




    hly1 = new QHBoxLayout;
    hly2 = new QHBoxLayout;
    hly3 = new QHBoxLayout;
    hly4 = new QHBoxLayout;
    hly5 = new QHBoxLayout;
    hly6 = new QHBoxLayout;
    hly7 = new QHBoxLayout;
    hly8 = new QHBoxLayout;
    hly9 = new QHBoxLayout;
//    hly10 = new QHBoxLayout;
//    hly11 = new QHBoxLayout;
//    hly12 = new QHBoxLayout;
    vly1 = new QVBoxLayout;
    vly2 = new QVBoxLayout;
    vly3 = new QVBoxLayout;
    vly4 = new QVBoxLayout;
    vly5 = new QVBoxLayout;
//    vly6 = new QVBoxLayout;
    vly = new QVBoxLayout;
    gly = new QGridLayout;

}

void DetailWidget::refreshPage(int)
{


}

void DetailWidget::layoutWidgets()
{
    //part1

    hly2->addWidget(lbComment);

    hly2->addWidget(lbCommentStar);
    hly2->addWidget(lbCommentStar+1);
    hly2->addWidget(lbCommentStar+2);
    hly2->addWidget(lbCommentStar+3);
    hly2->addWidget(lbCommentStar+4);

    hly2->addWidget(lbCommentMark);
    hly3->addWidget(lbProductVersion);
    hly3->addWidget(lbVersionNo);
    hly4->addWidget(lbProductSize);
    hly4->addWidget(lbSizeValue);


    vly1->addWidget(lbProductName);
    vly1->addLayout(hly2);
    vly1->addLayout(hly3);
    vly1->addLayout(hly4);

    lbProductName->setText("qq Music");
    lbProductImg->setText("nice");
    hly1->addWidget(lbProductImg);
    hly1->addLayout(vly1);
    hly1->setAlignment(lbProductImg,Qt::AlignLeft);
    hly1->setAlignment(vly1,Qt::AlignRight);

    hly5->addLayout(hly1);
    hly5->addWidget(btnState);
    hly5->setAlignment(hly1,Qt::AlignLeft);
    hly5->setAlignment(btnState,Qt::AlignRight);

    //part2
    vly2->addWidget(lbAppInfo);
    vly2->addWidget(lbAppInfoDetail);

    //part3

    vly3->addWidget(lbUserComment);

    vly4->addWidget(lbUserCommMark);
    vly4->addWidget(lbUserCommStar);
    vly4->addWidget(lbTotalCommenters);
    lbTotalCommenters->setText("people");


    gly->addWidget(lbStarLevel1,0,0);
    gly->addWidget(pbStarLevel1,0,1);
    gly->addWidget(lbLevel1Users,0,2);

    gly->addWidget(lbStarLevel2,1,0);
    gly->addWidget(pbStarLevel2,1,1);
    gly->addWidget(lbLevel2Users,1,2);

    gly->addWidget(lbStarLevel3,2,0);
    gly->addWidget(pbStarLevel3,2,1);
    gly->addWidget(lbLevel3Users,2,2);

    gly->addWidget(lbStarLevel4,3,0);
    gly->addWidget(pbStarLevel4,3,1);
    gly->addWidget(lbLevel4Users,3,2);

    gly->addWidget(lbStarLevel5,4,0);
    gly->addWidget(pbStarLevel5,4,1);
    gly->addWidget(lbLevel5Users,4,2);




    hly7->addWidget(lbmyMark);
    hly7->addWidget(lbmyStarLevel);
    hly7->addWidget(lbmyComment);
    lbmyMark->setText("MyMark");

    hly9->addLayout(vly4);
    hly9->addLayout(gly);
    hly9->addLayout(hly7);

    //input comment area
    vly5->addWidget(teCommContent);
    hly8->addWidget(btnSubmit);
    hly8->addWidget(btnCancel);
    vly5->addLayout(hly8);
    vly5->setAlignment(hly8,Qt::AlignRight);

    vly3->addLayout(hly9);
    vly3->addLayout(vly5);

    vly->addLayout(hly5);
    vly->addWidget(imgBoxer);
    vly->addLayout(vly2);
    vly->addLayout(vly3);
    vly->addWidget(userCommBoxer);
    setLayout(vly);
}

void DetailWidget::toPage(int productId)
{
    for(auto item = shareData->classStrMap.begin();item.key() == productId;item++)
    {
        getImage(item.value().proImage);
        lbProductName->setText(item.value().proName);


    }
    for(auto item1 = shareData->updateStrMap.begin(); item1.value().productId == productId; item1++)
    {
        lbProductSize->setText(octetsToString(item1.value().packageSize));
        lbProductVersion->setText(item1.value().version);
    }
}

void DetailWidget::getImage(QString headUrl)
{
    imageManager = new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl(headUrl));
    connect(imageManager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));
    imageManager->get(request);
}

void DetailWidget::replyFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(bytes);
        lbProductImg->setPixmap(pixmap);
        lbProductImg->resize(128,128);

    }
}

void DetailWidget::initStar(double num)
{
    for(int i = 0;i < 5;i++)
    {
        lbCommentStar[i].setFixedSize(10,10);
        lbCommentStar[i].setPixmap(QPixmap(":/image/空星.png"));
    }

    for(int i = 0;i < num;i++)
    {
        lbCommentStar[i].setPixmap(QPixmap(":/image/全星.png"));
    }

    if(num - qFloor(num) > 0)
    {
        lbCommentStar[(int)num].setPixmap(QPixmap(":/image/半星.png"));
    }
}

QString DetailWidget::octetsToString( qint64 octets )
{
#define THE_FACTOR 1024
    static const qint64 kb = THE_FACTOR;
    static const qint64 mb = THE_FACTOR * kb;
    static const qint64 gb = THE_FACTOR * mb;

    QString s;
    qreal value = octets;

    // Whether we care about decimals: only for GB and only
    // if it's less than 10 GB.
    bool round = true;

    if (octets >= gb) {
        s = QCoreApplication::translate("Size", "%L1 GB");
        value /= gb;
        round = false;
    } else if (octets >= mb) {
        s = QCoreApplication::translate("Size", "%L1 MB");
        value /= mb;
    } else if (octets >= kb) {
        s = QCoreApplication::translate("Size", "%L1 KB");
        value /= kb;
    } else  {
        s = QCoreApplication::translate("Size", "%L1 B");
    }

    if (value > 9.95)
        round = true;

    if (round)
        return s.arg(qRound(value));

    return s.arg(value, 0, 'f', 2);
}
