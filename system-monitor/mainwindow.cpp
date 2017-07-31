#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    resize(QSize(900,640));
    cpuMonitor = new CpuMonitor();
    cpuMonitor->setMinimumWidth(200);
    memMonitor = new MemoryMonitor();
    netMonitor = new NetMonitor();
    vbLayout = new QVBoxLayout();
    btnAll = new QPushButton();
    btnAll->setText("所有");
    btnApp = new QPushButton();
    btnApp->setText("应用");
    btnUser = new QPushButton();
    btnUser->setText("用户");
    labelInfo = new QLabel();
    labelInfo->size().setWidth(400);
    vbProcessLayout = new QVBoxLayout();
    hbLayout = new QHBoxLayout();
    hbMainLayout = new QHBoxLayout(this);
    spacer = new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Expanding);

    hbLayout->addWidget(labelInfo);
    hbLayout->addSpacerItem(spacer);
    hbLayout->addWidget(btnAll);
    hbLayout->addWidget(btnApp);
    hbLayout->addWidget(btnUser);

    QWidget *testWidget = new QWidget();
    testWidget->setMinimumSize(600,600);
    vbProcessLayout->addLayout(hbLayout);
    vbProcessLayout->addWidget(testWidget);

    vbLayout->addWidget(cpuMonitor);
    vbLayout->addWidget(memMonitor);
    vbLayout->addWidget(netMonitor);

    hbMainLayout->addLayout(vbLayout);
    hbMainLayout->addLayout(vbProcessLayout);
    this->setLayout(hbMainLayout);
    this->layout()->setContentsMargins(0,0,0,0);

    labelInfo->setText("总共有xxx进程");
    connect(btnApp,SIGNAL(clicked(bool)),this,SLOT(onBtnapp()));
    connect(btnAll,SIGNAL(clicked(bool)),this,SLOT(onBtnall()));
    connect(btnUser,SIGNAL(clicked(bool)),this,SLOT(onBtnuser()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::onBtnapp()
{
    qDebug()<<"on button app";
}

void MainWindow::onBtnall()
{
    qDebug()<<"on button all";
}

void MainWindow::onBtnuser()
{
    qDebug()<<"on button user";
}

