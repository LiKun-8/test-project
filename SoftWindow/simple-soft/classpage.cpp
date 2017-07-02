#include "classpage.h"

ClassPage::ClassPage(QWidget *parent) : QWidget(parent)
{
    scrollClass = new QScrollArea(this);
    shareDaba = new ShareData();
    jsonFunc = new JSONFUNC(shareDaba);
    jsonFunc->getCategoryNum();
    moreClassWidget = new MorePage();

    connect(jsonFunc,SIGNAL(curlIsOk()),moreClassWidget,SLOT(createMorewindow()),Qt::QueuedConnection);
    connect(jsonFunc,SIGNAL(numIsOk(int)),this,SLOT(createClassWindow(int)),Qt::QueuedConnection);
    connect(jsonFunc,SIGNAL(curlIsOk()),this,SLOT(setClassElementName()),Qt::QueuedConnection);
}

//创建分类页
void ClassPage::createClassWindow(int catenum)
{
    cateNum = catenum;
    classWidget = new ClassWidget[catenum];
    vbClasslayout = new QVBoxLayout();
    pageClassWidget = new QWidget();

    vbClasslayout = new QVBoxLayout();
    scrollClass->setFrameShape(QFrame::NoFrame); //去除窗口边框

    for(int i=0;i<catenum;i++)
    {
        connect(&classWidget[i],SIGNAL(moreShow(int)),this,SLOT(setMoreShow(int)));
        classWidget[i].setCategory(i);
        classWidget[i].setTopName(shareDaba->cateMap);
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
    jsonFunc->setAppname();
}


//设置分类软件的属性
void ClassPage::setClassElementName()
{
    qDebug()<<__FUNCTION__<<endl;
    if(shareDaba->classStrMap.isEmpty())
    {
        qDebug()<<"classStrMap is Empty!"<<endl;
    }

    for(int i = 0;i<cateNum;i++)
    {
        classWidget[i].initElement(shareDaba->classElementNumMap);
        classWidget[i].setElementName(shareDaba->classStrMap);
        classWidget[i].setElementImage(shareDaba->classStrMap);
    }
}

//测试更多页面跳转
void ClassPage::setMoreShow(int i)
{
    moreClassWidget->showMore->setTopName(i,shareDaba->cateMap);
    moreClassWidget->showMore->setElementNum(shareDaba->classElementNumMap);
    moreClassWidget->showMore->setElementName(i,shareDaba->classStrMap);
    moreClassWidget->showMore->setElementImage(i,shareDaba->classStrMap);
    moreClassWidget->scrollMore->resize(this->size().width(),this->size().height());
    emit setMore();
}
