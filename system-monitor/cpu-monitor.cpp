#include "cpu-monitor.h"

CpuMonitor::CpuMonitor(QWidget *parent) : QWidget(parent)
{
    labelInfo = new QLabel();
    labelName = new QLabel();
    labelInfo->setText("CPU使用率");
    labelName->setText("处理器");
    vbLayout = new QVBoxLayout(this);

    vbLayout->addWidget(labelInfo,3);
    vbLayout->addWidget(labelName,1);

    this->setLayout(vbLayout);
}
