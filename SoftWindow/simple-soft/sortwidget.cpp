#include "sortwidget.h"
#include <QVector>
#include <QDebug>
#include <QSpacerItem>
#include <QPainter>
#include <QPen>
#include <QEvent>
#include "json_func.h"

extern QMap<int,QString> cate_Map;
extern QMap<int,SORTSTRUCT>  sort_Str_Map;
extern QMap<int,int> sort_Element_Num;

SortWidget::SortWidget(QWidget *parent) :
    QWidget(parent)
{
    widget = new QWidget();
    widget->setMinimumSize(640,0);
    topsort = new Top_Sort();


    grid_Layout = new QGridLayout();
    grid_Layout->setSpacing(24);

    main_Layout = new QVBoxLayout();
    main_Layout->addWidget(topsort->widget);
    main_Layout->addLayout(grid_Layout);

    widget->setLayout(main_Layout);
    widget->installEventFilter(this);

    connect(topsort,SIGNAL(show_All(int)),this,SLOT(send_More_Show(int)));

    space_Widget = new QWidget[5];
    for(int i =0 ;i<5;i++)
    {
        space_Widget[i].setFixedSize(144,74);
    }
}

SortWidget::~SortWidget()
{
}
//设置分类标志
void SortWidget::set_Category(int cate)
{
    //    tt->set_category(cate);
    topsort->set_category(cate);
    category = cate;
}

//事件过滤器
bool SortWidget::eventFilter(QObject *target, QEvent *event)
{
    if(target == widget)
    {
        if(event->type() == QEvent::Resize)
        {
            int num_Element =0;
            int column = (widget->size().width()+48)/192;
            int row;
            qDebug()<<"colum  ==  "<<column<<endl;
            if(demo_Element.isEmpty())
            {
                return true;
            }

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

                if(demo_Element.size() <= column)
                {
                    for(int i = 0;i<(column);i++)
                    {
                        grid_Layout->removeWidget(&space_Widget[i]);
                    }
                }
            }

            for(int i=0;i<row;i++)
            {
                for(int j=0;j<column;j++)
                {
                    grid_Layout->addWidget(demo_Element.at(num_Element),i,j,1,1,Qt::AlignLeft);
                    if(num_Element<demo_Element.size()-1)
                    {
                        num_Element++;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            for(int i = 0;i<(column - demo_Element.size());i++)
            {
//                qDebug()<<"column - demo_element   ==  "<<(column - demo_Element.size())<<endl;
                grid_Layout->addWidget(&space_Widget[i],0,demo_Element.size()+i,1,1,Qt::AlignLeft);
            }
//            qDebug()<<"grid_layout_columncount  ==  "<<grid_Layout->columnCount()  << " demo_elemeng.size  ==  " <<demo_Element.size()<<endl;
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

//设置分类项名字
void SortWidget::set_Top_Name()
{
    if(cate_Map.isEmpty())
    {
        qDebug()<<"the cate_Map is empty!"<<endl;
    }

    if(cate_Map.contains(category+1))
    {
        QMap<int,QString>::iterator it = cate_Map.find(category+1);
        topsort->set_Label_Data(it.value());
        //        qDebug()<<"the it.value is : "<<it.value()<<endl;
    }

}

//设置软件项名字
void SortWidget::set_Element_Name()
{

    if(sort_Str_Map.isEmpty())
    {
        qDebug()<<"the sort_str is empty!"<<endl;
    }
    //    qDebug()<<"the  category is : "<<category<<endl;
    QMap<int,SORTSTRUCT>::iterator item = sort_Str_Map.begin();
    int i = 0;
    for(;item != sort_Str_Map.end();++item)
    {
        //        qDebug()<<"the sort_str is empty!"<<item.value().btn_name<<endl;
        if(item.value().category == (category+1))
        {
            if(i < 15)
            {
                tt[i].set_BtnName(item.value().btn_name);
                i++;
            }
            else
            {
                break;
            }
        }
    }
}

//初始化软件项
void SortWidget::init_Element(int i)
{
    QMap<int,int>::iterator it = sort_Element_Num.find(category+1);
    tt = new Element[it.value()];
    if(it.value()<=15)
    {
        for(int i=0;i<it.value();i++)
        {
            demo_Element.append(tt[i].base_Widget);
        }
    }
    else
    {
        for(int i = 0; i<15;i++)
        {
            demo_Element.append(tt[i].base_Widget);
        }
    }
}



