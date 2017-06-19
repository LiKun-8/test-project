#include "softwindow.h"
#include <QDebug>
#include <QEvent>

QMap<int,QString> cate_Map;
QMap<int,SORTSTRUCT>  sort_Str_Map;


SoftWindow::SoftWindow(QWidget *parent)
    : QWidget(parent)
{
    history_Page = 0;
    now_Page = 0;
    this->resize(944,600);
    hb_Layout = new QHBoxLayout();
    vb_Layout = new QVBoxLayout();
    jsonFunc = new JSON_FUNC();


    init_Window();

    hb_Layout->addWidget(btn_Return);
    hb_Layout->addWidget(btn_Next);
    hb_Layout->addWidget(btn_Refresh);
    hb_Layout->addSpacerItem(left_Space);
    hb_Layout->addWidget(btn_Home);
    hb_Layout->addWidget(btn_Sort);
    hb_Layout->addWidget(btn_Update);
    hb_Layout->addWidget(btn_Manager);
    hb_Layout->addSpacerItem(right_Space);\
    hb_Layout->addWidget(line_Search);
    hb_Layout->setSpacing(20);
    hb_Layout->setMargin(16);

    vb_Layout->addLayout(hb_Layout);
    vb_Layout->addWidget(stw_window);
    vb_Layout->setMargin(0);
    vb_Layout->setSpacing(0);
    this->setLayout(vb_Layout);

    connect(btn_Home,SIGNAL(clicked(bool)),this,SLOT(On_Btn_Home()));
    connect(btn_Sort,SIGNAL(clicked(bool)),this,SLOT(On_Btn_Sort()));
    connect(btn_Update,SIGNAL(clicked(bool)),this,SLOT(On_Btn_Update()));
    connect(btn_Manager,SIGNAL(clicked(bool)),this,SLOT(On_Btn_Manager()));
}

SoftWindow::~SoftWindow()
{
}

void SoftWindow::Set_Current_Page(int page)
{
    stw_window->setCurrentIndex(page);
    //    qDebug()<<stw_window->size().width()<<"***"<<stw_window->size().height()<<endl;
    //        qDebug()<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    //    qDebug()<<page_Home->size().width()<<"***"<<page_Home->size().height()<<endl;
    //        qDebug()<<page_Sort->size().width()<<"***"<<page_Sort->size().height()<<endl;
    //    qDebug()<<page_Update->size().width()<<"***"<<page_Update->size().height()<<endl;
    //    qDebug()<<page_Manager->size().width()<<"***"<<page_Manager->size().height()<<endl;
    //        qDebug()<<this->size().width()<<"***"<<this->size().height()<<endl;
    //    qDebug()<<"sortWidget[1] == "<<sortWidget[1].widget->size().width()<<sortWidget[1].widget->size().height()<<endl;
    //        qDebug()<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    scroll->setGeometry(0,0,page_Sort->size().width(),page_Sort->size().height());
    //        scroll->setGeometry(0,0,this->size().width(),this->size().height());
}

void SoftWindow::init_Window()
{
    btn_Return = new QPushButton();
    btn_Return->setStyleSheet("background-image:url(:/image/return.png);");
    btn_Return->setFixedSize(36,36);
    btn_Next = new QPushButton();
    btn_Next->setStyleSheet("background-image:url(:/image/next.png);");
    btn_Next->setFixedSize(36,36);
    btn_Refresh = new QPushButton();
    btn_Refresh->setStyleSheet("background-image:url(:/image/refresh.png);");
    btn_Refresh->setFixedSize(36,36);
    btn_Home = new QPushButton();
    btn_Home->setText("HOME");
    btn_Home->setFixedSize(80,24);
    btn_Sort = new QPushButton();
    btn_Sort->setText("SORT");
    btn_Sort->setFixedSize(80,24);
    btn_Update = new QPushButton();
    btn_Update->setText("UPDATE");
    btn_Update->setFixedSize(80,24);
    btn_Manager = new QPushButton();
    btn_Manager->setText("MANAGER");
    btn_Manager->setFixedSize(80,24);

    //    btn_Manager->setStyleSheet("QPushButton{"
    //                               "border:3px  ;"//solid black
    //                               "border-radius:5px}");
    btn_Return->setFlat(true);
    btn_Next->setFlat(true);
    btn_Refresh->setFlat(true);
    btn_Home->setFlat(true);
    btn_Sort->setFlat(true);
    btn_Update->setFlat(true);
    btn_Manager->setFlat(true);

    left_Space = new QSpacerItem(24, 24,QSizePolicy::Expanding);
    right_Space = new QSpacerItem(24,48,QSizePolicy::Expanding,QSizePolicy::Minimum);

    line_Search = new QLineEdit();
    line_Search->setFixedSize(160,24);
    line_Search->setPlaceholderText("please input txt");

    stw_window = new QStackedWidget(this);
    stw_window->setMaximumWidth(1200);

    page_Home = new QWidget();
    page_Sort = new QWidget();
    //    page_Sort->setAcceptDrops();
    page_Update = new QWidget();
    page_Manager = new QWidget();

    stw_window->addWidget(page_Home);
    stw_window->addWidget(page_Sort);
    stw_window->addWidget(page_Update);
    stw_window->addWidget(page_Manager);
    label1 = new QLabel(page_Home);
    label1->setText("HOME");
    label3 = new QLabel(page_Update);
    label3->setText("UPDATE");
    label4 = new QLabel(page_Manager);
    label4->setText("MANAGER");

    create_Soft_Window();

    btn_Home->setFocusPolicy(Qt::NoFocus);
    btn_Manager->setFocusPolicy(Qt::NoFocus);
    btn_Next->setFocusPolicy(Qt::NoFocus);
    btn_Refresh->setFocusPolicy(Qt::NoFocus);
    btn_Return->setFocusPolicy(Qt::NoFocus);
    btn_Sort->setFocusPolicy(Qt::NoFocus);
    btn_Update->setFocusPolicy(Qt::NoFocus);
    //    process->waitForFinished();
}

void SoftWindow::create_Soft_Window()
{
    cate_num = jsonFunc->get_Category_Num();
    jsonFunc->set_App_name();

    connect(jsonFunc,SIGNAL(curl_IsOk()),this,SLOT(test_set_name()));


    qDebug()<<"cate_num == "<<cate_num<<endl;
    sortWidget = new SortWidget[cate_num];

    vb_Sort_layout = new QVBoxLayout();
    page_Sort_Widget = new QWidget();

    vb_Sort_layout = new QVBoxLayout();
    scroll = new QScrollArea(page_Sort);
    scroll->setFrameShape(QFrame::NoFrame); //去除窗口边框

    for(int i=0;i<cate_num;i++)
    {
        //        connect(&sortWidget[i],SIGNAL(more_Show(int)),this,SLOT(set_More_Show(int)));
        sortWidget[i].set_Category(i);
        sortWidget[i].set_Top_Name();
        //        sortWidget[i].set_Element_Name();
        vb_Sort_layout->addWidget(sortWidget[i].widget);
    }


    page_Sort_Spacer =new QSpacerItem(24,24,QSizePolicy::Minimum,QSizePolicy::Expanding);
    scroll->setWidget(page_Sort_Widget);
    vb_Sort_layout->addSpacerItem(page_Sort_Spacer);
    vb_Sort_layout->setMargin(0);
    page_Sort_Widget->setLayout(vb_Sort_layout);
    //滚动条不可见，只能通过鼠标滑动
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll->setWidgetResizable(true);
}


void SoftWindow::On_Btn_Home()
{
    Set_Current_Page(HOME_PAGE);
}

void SoftWindow::On_Btn_Sort()
{
    Set_Current_Page(SOFT_PAGE);
    stw_window->move((this->size().width()-page_Sort->size().width())/2,72);
}

void SoftWindow::On_Btn_Update()
{
    Set_Current_Page(UPDATE_PAGE);
}

void SoftWindow::On_Btn_Manager()
{
    Set_Current_Page(MANAGER_PAGE);
}

void SoftWindow::set_More_Show(int i)
{
    Set_Current_Page(MANAGER_PAGE);
    //    qDebug()<<"More show i == "<<i <<endl;
}

void SoftWindow::test_set_name()
{
    QMap<int,SORTSTRUCT>::iterator  it ;
    if(sort_Str_Map.isEmpty())
    {
        qDebug()<<"hello++++++++++++++++++++++++++++++++++"<<endl;
    }
    for(it  = sort_Str_Map.begin();it != sort_Str_Map.end(); ++it)
    {
        //        qDebug() << it.value().btn_name << endl;
    }

    for(int i = 0;i<cate_num;i++)
        sortWidget[i].set_Element_Name();
}



bool SoftWindow::event(QEvent *event)
{
    if(event->type() == QEvent::Resize)
    {
        scroll->setGeometry(0,0,page_Sort->size().width(),page_Sort->size().height());
        qDebug()<<page_Sort->size().width() << "   "<<page_Sort->size().height()<<endl;
        stw_window->move((this->size().width()-page_Sort->size().width())/2,72);
        return true;
    }
    return QWidget::event(event);
}

