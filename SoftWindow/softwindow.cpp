#include "softwindow.h"
#include <QDebug>
#include <QEvent>

SoftWindow::SoftWindow(QWidget *parent)
    : QWidget(parent)
{
    historyPage = 0;
    nowPage = 0;
    this->resize(960,640);
    hbLayout = new QHBoxLayout();
    vbLayout = new QVBoxLayout();

    //初始化窗口
    initMainWindow();

    //上部布局
    hbLayout->addWidget(btnReturn);
    hbLayout->addWidget(btnNext);
    hbLayout->addWidget(btnRefresh);
    hbLayout->addSpacerItem(leftSpace);
    hbLayout->addWidget(btnHome);
    hbLayout->addWidget(btnSort);
    hbLayout->addWidget(btnUpdate);
    hbLayout->addWidget(btnManager);
    hbLayout->addSpacerItem(rightSpace);\
    hbLayout->addWidget(lineSearch);
    hbLayout->setSpacing(20);
    hbLayout->setMargin(16);

    //整体布局
    vbLayout->addLayout(hbLayout);
    vbLayout->addWidget(stwwindow);
    vbLayout->setMargin(0);
    vbLayout->setSpacing(0);
    this->setLayout(vbLayout);

    connect(btnHome,SIGNAL(clicked(bool)),this,SLOT(onBtnHome()));
    connect(btnSort,SIGNAL(clicked(bool)),this,SLOT(onBtnClass()));
    connect(btnUpdate,SIGNAL(clicked(bool)),this,SLOT(onBtnUpdate()));
    connect(btnManager,SIGNAL(clicked(bool)),this,SLOT(onBtnManager()));
}

SoftWindow::~SoftWindow()
{
}

//跳转指定页面
void SoftWindow::setCurrentPage(int page)
{
    stwwindow->setCurrentIndex(page);
    stwwindow->move((this->size().width()-pageClass->size().width())/2,72);
}

void SoftWindow::initMainWindow()
{
    btnReturn = new QPushButton();
    btnReturn->setStyleSheet("background-image:url(:/image/return.png);");
    btnReturn->setFixedSize(36,36);
    btnNext = new QPushButton();
    btnNext->setStyleSheet("background-image:url(:/image/next.png);");
    btnNext->setFixedSize(36,36);
    btnRefresh = new QPushButton();
    btnRefresh->setStyleSheet("background-image:url(:/image/refresh.png);");
    btnRefresh->setFixedSize(36,36);
    btnHome = new QPushButton();
    btnHome->setText("HOME");
    btnHome->setFixedSize(80,24);
    btnSort = new QPushButton();
    btnSort->setText("CLASS");
    btnSort->setFixedSize(80,24);
    btnUpdate = new QPushButton();
    btnUpdate->setText("UPDATE");
    btnUpdate->setFixedSize(80,24);
    btnManager = new QPushButton();
    btnManager->setText("MANAGER");
    btnManager->setFixedSize(80,24);

    btnReturn->setFlat(true);
    btnNext->setFlat(true);
    btnRefresh->setFlat(true);
    btnHome->setFlat(true);
    btnSort->setFlat(true);
    btnUpdate->setFlat(true);
    btnManager->setFlat(true);

    leftSpace = new QSpacerItem(24, 24,QSizePolicy::Expanding);
    rightSpace = new QSpacerItem(24,48,QSizePolicy::Expanding,QSizePolicy::Minimum);

    lineSearch = new QLineEdit();
    lineSearch->setFixedSize(160,24);
    lineSearch->setPlaceholderText("please input txt");

    stwwindow = new QStackedWidget(this);
    stwwindow->setMaximumWidth(1200);

    pageHome = new QWidget();
    pageClass = new ClassPage();
    //    pageClass->setAcceptDrops();
    pageUpdate = new QWidget();
    pageManager = new QWidget();

    stwwindow->addWidget(pageHome);
    stwwindow->addWidget(pageClass);
    stwwindow->addWidget(pageUpdate);
    stwwindow->addWidget(pageManager);
    stwwindow->addWidget(pageClass->moreClassWidget);
    label1 = new QLabel(pageHome);
    label1->setText("HOME");
    label3 = new QLabel(pageUpdate);
    label3->setText("UPDATE");
    label4 = new QLabel(pageManager);
    label4->setText("MANAGER");

    btnHome->setFocusPolicy(Qt::NoFocus);
    btnManager->setFocusPolicy(Qt::NoFocus);
    btnNext->setFocusPolicy(Qt::NoFocus);
    btnRefresh->setFocusPolicy(Qt::NoFocus);
    btnReturn->setFocusPolicy(Qt::NoFocus);
    btnSort->setFocusPolicy(Qt::NoFocus);
    btnUpdate->setFocusPolicy(Qt::NoFocus);

    connect(pageClass,SIGNAL(setMore()),this,SLOT(onBtnMore()));
}

void SoftWindow::onBtnHome()
{
    setCurrentPage(HOMEPAGE);
}

void SoftWindow::onBtnClass()
{
    setCurrentPage(CLASSPAGE);
}

void SoftWindow::onBtnUpdate()
{
    setCurrentPage(UPDATEPAGE);
}

void SoftWindow::onBtnManager()
{
    setCurrentPage(MANAGERPAGE);
}

void SoftWindow::onBtnMore()
{
    setCurrentPage(MOREPAGE);
}


