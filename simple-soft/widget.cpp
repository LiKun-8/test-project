#include "widget.h"
#include "ui_widget.h"
#include <QVector>
#include <QDebug>
#include <QSpacerItem>
#include <QPainter>
#include <QPen>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setMinimumSize(944,640);
    main_Layout = new QGridLayout();
//    main_Layout->setMargin(0);
    main_Layout->setSpacing(24);
    tt = new Element[19];
    for(int i=0;i<17;i++)
    {
        demo_Element.append(tt[i].base_Widget);
    }
    spacer = new QSpacerItem(24,24,QSizePolicy::Minimum,QSizePolicy::Expanding);

    topsort = new Top_Sort();
    vb_Layout = new QVBoxLayout();
    vb_Layout->addWidget(topsort->widget);
    vb_Layout->addLayout(main_Layout);
    vb_Layout->addSpacerItem(spacer);

    setLayout(vb_Layout);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::resizeEvent(QResizeEvent *event)
{
//    qDebug()<<"The window is resize!"<<endl;
//    qDebug()<<"widget.width = "<<this->size().width();
    int num_Element =0;
    int column = (this->size().width()-224)/144;
    int row = (demo_Element.size()/column)+1;

    if(column < 0 || row < 0)
    {
        qDebug()<<"column or row is error!"<<endl;
    }

    if(!main_Layout->isEmpty())
    {
//        qDebug()<<"main_Layout isn't empty!!!"<<endl;
        for(int i=0;i<demo_Element.size();i++)
            main_Layout->removeWidget(demo_Element.at(i));
    }

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            main_Layout->addWidget(demo_Element.at(num_Element),i,j);
            if(num_Element<demo_Element.size()-1)
                num_Element++;
            else {
                break;
            }
        }
    }
}



