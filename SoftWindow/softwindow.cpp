#include "softwindow.h"
#include <QDebug>
#include <QEvent>

//extern QMap<int,QString> cateMap;
//extern QMap<int,SORTSTRUCT>  sortStrMap;
//extern QMap<int,int> sortElementNum;

SoftWindow::SoftWindow(QWidget *parent)
    : QWidget(parent)
{
    historyPage = 0;
    nowPage = 0;
    this->resize(960,640);
    hbLayout = new QHBoxLayout();
    vbLayout = new QVBoxLayout();
    jsonFunc = new JSONFUNC();

    //初始化窗口
    InitMainWindow();

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

    connect(btnHome,SIGNAL(clicked(bool)),this,SLOT(OnBtnHome()));
    connect(btnSort,SIGNAL(clicked(bool)),this,SLOT(OnBtnSort()));
    connect(btnUpdate,SIGNAL(clicked(bool)),this,SLOT(OnBtnUpdate()));
    connect(btnManager,SIGNAL(clicked(bool)),this,SLOT(OnBtnManager()));
}

SoftWindow::~SoftWindow()
{
}

//跳转指定页面
void SoftWindow::SetCurrentPage(int page)
{
    stwwindow->setCurrentIndex(page);
    scrollClass->setGeometry(0,0,pageClass->size().width(),pageClass->size().height());
    scrollMore->setGeometry(0,0,pageMore->size().width(),pageMore->size().height());
}

void SoftWindow::InitMainWindow()
{
    jsonFunc = new JSONFUNC();

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

    //    btnManager->setStyleSheet("QPushButton{"
    //                               "border:3px  ;"//solid black
    //                               "border-radius:5px}");
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
    pageClass = new QWidget();
    //    pageClass->setAcceptDrops();
    pageUpdate = new QWidget();
    pageManager = new QWidget();
    pageMore = new QWidget();

    stwwindow->addWidget(pageHome);
    stwwindow->addWidget(pageClass);
    stwwindow->addWidget(pageUpdate);
    stwwindow->addWidget(pageManager);
    stwwindow->addWidget(pageMore);
    label1 = new QLabel(pageHome);
    label1->setText("HOME");
    label3 = new QLabel(pageUpdate);
    label3->setText("UPDATE");
    label4 = new QLabel(pageManager);
    label4->setText("MANAGER");

    CreateClassWindow();
    CreateMorewindow();

    btnHome->setFocusPolicy(Qt::NoFocus);
    btnManager->setFocusPolicy(Qt::NoFocus);
    btnNext->setFocusPolicy(Qt::NoFocus);
    btnRefresh->setFocusPolicy(Qt::NoFocus);
    btnReturn->setFocusPolicy(Qt::NoFocus);
    btnSort->setFocusPolicy(Qt::NoFocus);
    btnUpdate->setFocusPolicy(Qt::NoFocus);
}

//创建分类页
void SoftWindow::CreateClassWindow()
{
    catenum = jsonFunc->GetCategoryNum();
    jsonFunc->SetAppname();
    connect(jsonFunc,SIGNAL(CurlIsOk()),this,SLOT(SetClassElementName()));

    classWidget = new ClassWidget[catenum];
    vbClasslayout = new QVBoxLayout();
    pageClassWidget = new QWidget();

    vbClasslayout = new QVBoxLayout();
    scrollClass = new QScrollArea(pageClass);
    scrollClass->setFrameShape(QFrame::NoFrame); //去除窗口边框

    for(int i=0;i<catenum;i++)
    {
        connect(&classWidget[i],SIGNAL(moreShow(int)),this,SLOT(SetMoreShow(int)));
        classWidget[i].SetCategory(i);
        classWidget[i].SetTopName(jsonFunc->cateMap);
        vbClasslayout->addWidget(classWidget[i].widget);
    }

    pageClassSpacer =new QSpacerItem(24,24,QSizePolicy::Minimum,QSizePolicy::Expanding);
    scrollClass->setWidget(pageClassWidget);
    vbClasslayout->addSpacerItem(pageClassSpacer);
    vbClasslayout->setMargin(0);
    pageClassWidget->setLayout(vbClasslayout);
    //滚动条不可见，只能通过鼠标滑动
    scrollClass->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollClass->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollClass->setWidgetResizable(true);
}

void SoftWindow::CreateMorewindow()
{
    moreClassWidget = new ShowMore();
    pageMoreWidget = new QWidget();

    vbClasslayoutMore = new QVBoxLayout();
    scrollMore = new QScrollArea(pageMore);
    scrollMore->setFrameShape(QFrame::NoFrame); //去除窗口边框
    vbClasslayoutMore->addWidget(moreClassWidget->moreWidget);

    pageMoreSpacer =new QSpacerItem(24,24,QSizePolicy::Minimum,QSizePolicy::Expanding);
    scrollMore->setWidget(pageMoreWidget);
    vbClasslayoutMore->addSpacerItem(pageMoreSpacer);
    vbClasslayoutMore->setMargin(0);
    pageMoreWidget->setLayout(vbClasslayoutMore);
    //滚动条不可见，只能通过鼠标滑动
    scrollMore->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollMore->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollMore->setWidgetResizable(true);
}


void SoftWindow::OnBtnHome()
{
    SetCurrentPage(HOMEPAGE);
}

void SoftWindow::OnBtnSort()
{
    SetCurrentPage(CLASSPAGE);
    stwwindow->move((this->size().width()-pageClass->size().width())/2,72);
}

void SoftWindow::OnBtnUpdate()
{
    SetCurrentPage(UPDATEPAGE);
}

void SoftWindow::OnBtnManager()
{
    SetCurrentPage(MANAGERPAGE);
}

//测试更多页面跳转
void SoftWindow::SetMoreShow(const int i)
{
//    qDebug()<<pageClass->size()<<endl;
    SetCurrentPage(MOREPAGE);
    moreClassWidget->SetTopName(i,jsonFunc->cateMap);
    moreClassWidget->SetElementNum(jsonFunc->classElementNumMap);
    moreClassWidget->SetElementName(i,jsonFunc->classStrMap);
    moreClassWidget->SetElementImage(i,jsonFunc->classStrMap);
    stwwindow->move((this->size().width()-pageMore->size().width())/2,72);

}

//设置分类软件的属性
void SoftWindow::SetClassElementName()
{
//    qDebug()<<__FUNCTION__<<endl;
    if(jsonFunc->classStrMap.isEmpty())
    {
        qDebug()<<"classStrMap is Empty!"<<endl;
    }

    for(int i = 0;i<catenum;i++)
    {
        classWidget[i].InitElement(jsonFunc->classElementNumMap);
        classWidget[i].SetElementName(jsonFunc->classStrMap);
        classWidget[i].SetElementImage(jsonFunc->classStrMap);
    }
}

//事件处理，改变分类页面大小和位置
bool SoftWindow::event(QEvent *event)
{
    if(event->type() == QEvent::Resize)
    {
        scrollClass->setGeometry(0,0,pageClass->size().width(),pageClass->size().height());
        scrollMore->setGeometry(0,0,pageMore->size().width(),pageMore->size().height());
        stwwindow->move((this->size().width()-stwwindow->size().width())/2,72);
        return true;
    }

    return QWidget::event(event);
}

