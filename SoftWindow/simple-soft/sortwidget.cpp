#include "sortwidget.h"
#include <QVector>
#include <QDebug>
#include <QSpacerItem>
#include <QPainter>
#include <QPen>
#include <QEvent>

SortWidget::SortWidget(QWidget *parent) :
    QWidget(parent)
{
    widget = new QWidget();
    widget->setMinimumSize(640,0);
    topsort = new Top_Sort();
    grid_Layout = new QGridLayout();
    grid_Layout->setSpacing(24);
    int x=15;
    tt = new Element[x];
    for(int i=0;i<x;i++)
    {
        demo_Element.append(tt[i].base_Widget);
    }

    softThread = new SoftThread();
    softThread->set_Element(tt);
    softThread->run();
//    spacer = new QSpacerItem(24,24,QSizePolicy::Minimum,QSizePolicy::Expanding);

    main_Layout = new QVBoxLayout();
    main_Layout->addWidget(topsort->widget);
    main_Layout->addLayout(grid_Layout);
//    main_Layout->addSpacerItem(spacer);

    widget->setLayout(main_Layout);
    widget->installEventFilter(this);

    connect(topsort,SIGNAL(show_All(int)),this,SLOT(send_More_Show(int)));
}

SortWidget::~SortWidget()
{
}

void SortWidget::set_Category(int cate)
{
    tt->set_category(cate);
    topsort->set_category(cate);
}

bool SortWidget::eventFilter(QObject *target, QEvent *event)
{
    if(target == widget)
       {
           if(event->type() == QEvent::Resize)
           {
               int num_Element =0;
               int column = (widget->size().width()+45)/192;
               int row;
               if(demo_Element.size()%column == 0)
               {
                   row  = (demo_Element.size()/column);
               }
               else
               {
                   row  = (demo_Element.size()/column)+1;
               }
               if(column < 0 || row < 0)
               {
                   qDebug()<<"column or row is error!"<<endl;
               }

               if(!grid_Layout->isEmpty())
               {
                   for(int i=0;i<demo_Element.size();i++)
                       grid_Layout->removeWidget(demo_Element.at(i));
               }

               for(int i=0;i<row;i++)
               {
                   for(int j=0;j<column;j++)
                   {
                       grid_Layout->addWidget(demo_Element.at(num_Element),i,j);
                       if(num_Element<demo_Element.size()-1)
                           num_Element++;
                       else {
                           break;
                       }
                   }
               }
           }
           return true;
       }
    return QWidget::eventFilter(target,event);
}

void SortWidget::send_More_Show(int i)
{
    emit more_Show(i);
//    qDebug()<<" More  Show  !!!!!!!"<<endl;
}



