#include "showmore.h"
#include <QDebug>
#include "json_func.h"
#define MAX_NUMBER 180

extern QMap<int,QString> cate_Map;
extern QMap<int,SORTSTRUCT>  sort_Str_Map;
extern QMap<int,int> sort_Element_Num;

ShowMore::ShowMore(QWidget *parent) : QWidget(parent)
{
    more_Widget = new QWidget();
    more_TopSort = new Top_Sort();
    more_TopSort->set_Topbtn_Hide();
    mainLayout = new QVBoxLayout();
    more_Element = new Element[MAX_NUMBER];
    ele_Layout = new QGridLayout();
    ele_Layout->setSpacing(24);
    more_Widget->setMinimumSize(640,0);
    more_Widget->installEventFilter(this);

    int test = 0;
    for(int i = 0;i<36;i++)
    {
        for(int j = 0;j<5;j++)
        {
            ele_Layout->addWidget(more_Element[test].base_Widget,i,j,1,1,Qt::AlignLeft);
            more_Element[test].base_Widget->hide();

            if(test < (MAX_NUMBER-1))
            {
                test++;
            }
            else
            {
                break;
            }
        }

    }
    category_Flag = -1;
    space_Widget = new QWidget[5];
    mainLayout->addWidget(more_TopSort->widget);
    mainLayout->addLayout(ele_Layout);
    //    this->layout()->addWidget(more_TopSort->widget);
    more_Widget->setLayout(mainLayout);
}

//设置软件名字
void ShowMore::set_Element_Name(int category)
{
    if(sort_Str_Map.isEmpty())
    {
        qDebug()<<"the sort_str is empty!"<<endl;
    }

    QMap<int,SORTSTRUCT>::iterator item = sort_Str_Map.begin();

    int showNum = 0;
    for(;item != sort_Str_Map.end();++item)
    {
        if(item.value().category == (category+1))
        {
            more_Element[showNum].set_BtnName(item.value().btn_name);
            more_Element[showNum].base_Widget->show();
            showNum++;
        }
    }

    for(int hideNum = showNum;hideNum<MAX_NUMBER;hideNum++)
    {
        more_Element[hideNum].base_Widget->hide();

    }
}

//设置软件类名字
void ShowMore::set_Top_Name(int category)
{
    category_Flag = category;
    if(cate_Map.isEmpty())
    {
        qDebug()<<"the cate_Map is empty!"<<endl;
    }

    if(cate_Map.contains(category+1))
    {
        QMap<int,QString>::iterator it = cate_Map.find(category+1);
        more_TopSort->set_Label_Data(it.value());
    }

}

bool ShowMore::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == more_Widget)
    {
        if(event->type() == QEvent::Resize)
        {
            if(category_Flag == -1)
            {
                return true;
            }

            QMap<int,int>::iterator it = sort_Element_Num.find(category_Flag+1);
            int num_Element = it.value();
            int column = (more_Widget->size().width()+48)/192;
            int row;

            if(num_Element%column == 0)
            {
                row  = (num_Element/column);
            }
            else
            {
                row  = (num_Element/column)+1;
            }


            if(column < 0 || row < 0)
            {
                qDebug()<<"column or row is error!"<<endl;
            }

            if(!ele_Layout->isEmpty())
            {
                //现有的控件不必清空,只是对现有的控件进行排序,空Widget每次都要清空
                for(int i = 0;i < 5;i++)
                {
                    ele_Layout->removeWidget(&space_Widget[i]);
                }

            }

            //对软件控件进行重新排序
            int num=0;
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<column;j++)
                {

                    ele_Layout->addWidget(more_Element[num].base_Widget,i,j,1,1,Qt::AlignLeft);

                    if(num<(num_Element-1))
                    {
                        num++;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            //为不够一行的软件类添加空控件，使布局好看
            for(int i = 0;i<(column - num_Element);++i)
            {
                ele_Layout->addWidget(&space_Widget[i],0,num_Element+i,1,1,Qt::AlignLeft);
            }

            //隐藏多余的控件
            if(num_Element>column)
            {
                for(int i = num_Element;i<MAX_NUMBER;i++)
                {

                    more_Element[i].base_Widget->hide();
                }
                for(int i = 0;i<num_Element;i++)
                {

                    more_Element[i].base_Widget->show();
                }
            }
        }
    }
    return QWidget::eventFilter(watched,event);
}
