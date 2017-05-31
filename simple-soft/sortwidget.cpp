#include "sortwidget.h"
#include <QVector>
#include <QDebug>
#include <QSpacerItem>
#include <QPainter>
#include <QPen>

SortWidget::SortWidget(QWidget *parent) :
    QWidget(parent)
{
    widget = new QWidget();
    widget->setMinimumSize(944,640);

    topsort = new Top_Sort();
    grid_Layout = new QGridLayout();
    grid_Layout->setSpacing(24);
    tt = new Element[19];
    for(int i=0;i<19;i++)
    {
        demo_Element.append(tt[i].base_Widget);
    }
    spacer = new QSpacerItem(24,24,QSizePolicy::Minimum,QSizePolicy::Expanding);

    main_Layout = new QVBoxLayout();
    main_Layout->addWidget(topsort->widget);
    main_Layout->addLayout(grid_Layout);
    main_Layout->addSpacerItem(spacer);

    widget->setLayout(main_Layout);
}

SortWidget::~SortWidget()
{
}

void SortWidget::resizeEvent(QResizeEvent *event)
{
//    qDebug()<<"The window is resize!"<<endl;
    int num_Element =0;
    int column = (this->size().width()-224)/144;
    int row = (demo_Element.size()/column)+1;

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



