#include "threadwidget.h"
#include <QDebug>
#include "api/myhelper.h"
ThreadWidget::ThreadWidget()
{
    bar = new QProgressBar(this);
    bar->setRange(0,4999);
    bar->setValue(0);
    bar->resize(QSize(400,30));
    this->resize(QSize(800,80));
    bar->move(200,25);
}

void ThreadWidget::showbar()
{
    for(int i = 0; i<=4999;i++)
    {
        myHelper::sleep(1);
        bar->setValue(i);
    }
    this->close();
}

void ThreadWidget::outputNum(int i)
{
    bar->setValue(i);
}

