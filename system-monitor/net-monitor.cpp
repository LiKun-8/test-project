#include "net-monitor.h"

NetMonitor::NetMonitor(QWidget *parent) : QWidget(parent)
{
    labelInfo = new QLabel();
    labelName = new QLabel();
    labelInfo->setText("网络使用率");
    labelName->setText("网络");
    vbLayout = new QVBoxLayout(this);

    vbLayout->addWidget(labelInfo,3);
    vbLayout->addWidget(labelName,1);

    this->setLayout(vbLayout);
}
