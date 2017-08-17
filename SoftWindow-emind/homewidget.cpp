#include "homewidget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QTableView>
#include <QQuickWidget>
#include <QQmlEngine>
#include <QScrollArea>
#include "ClassAndMorePage/recommendwidget.h"
#include "sharedata.h"

HomeWidget::HomeWidget(QWidget *parent,ShareData *data) : QWidget(parent)
{
    resize(940,640);

    vly = new QVBoxLayout;

//    line2 = new QFrame(this);
//    line2->resize(960,2);
//    line2->setAutoFillBackground(true);
//    line2->setFrameShadow(QFrame::Raised);
//    line2->setFrameShape(QFrame::HLine);

    recommWidget = new RecommendWidget(this,data);
    connect(recommWidget,SIGNAL(toDetailPage(int)),this,SIGNAL(toDetailPage(int)));

    qmlEngine = new QQmlEngine;
    imgBox = new QQuickWidget(qmlEngine,this);
    imgBox->setMaximumSize(QSize(900,800));
    imgBox->setSource(QUrl::fromLocalFile(":/Imgbox.qml"));

//    vly->addWidget(line2,Qt::AlignCenter);
    vly->addWidget(imgBox);
    vly->setAlignment(imgBox,Qt::AlignCenter);
    vly->addWidget(recommWidget);
    setLayout(vly);

}

void HomeWidget::refreshPage(int)
{

}

HomeWidget::~HomeWidget()
{
//    delete recommWidget;
}
