#include "memory-monitor.h"

MemoryMonitor::MemoryMonitor(QWidget *parent) : QWidget(parent)
{
    labelInfo = new QLabel();
    labelName = new QLabel();
    labelInfo->setText("内存使用率");
    labelName->setText("内存");
    vbLayout = new QVBoxLayout(this);

    vbLayout->addWidget(labelInfo,3);
    vbLayout->addWidget(labelName,1);

    this->setLayout(vbLayout);
}
