#include "getnetworkimage.h"
#define NUM 500
#define ROW 50

GetNetworkImage::GetNetworkImage(QWidget *parent)
    : QWidget(parent)
{
    scrollArea = new QScrollArea(this);
    widget = new QWidget();
    layout = new QGridLayout(widget);
    layout->setSpacing(15);
    m_MyWidget = new MyWidget[NUM];

    int x = 0;
    for(int i = 0;i<ROW;i++)
    {
        for(int j = 0;j<10;j++)
        {
            layout->addWidget(&m_MyWidget[x],i,j);
            m_MyWidget[x].setFixedSize(64,64);
            if(x<(NUM-1))
            {
                x++;
            }
            else
            {
                break;
            }
        }
    }

    int y=0;
    for(int i = 0;i<NUM;i++)
    {
        if(y<10)
        {
            testpath = QString("%1%2%3").arg("http://k2.jsqq.net/uploads/allimg/1705/7_170524143440_").arg(y+1).arg(".jpg");
            y++;
        }
        else
        {
            testpath = QString("%1%2%3").arg("http://k2.jsqq.net/uploads/allimg/1705/7_170524143440_").arg(1).arg(".jpg");
            y=1;
        }
        imageMap.insert(i+1,testpath);
    }

    QMap<int,QString>::iterator it = imageMap.begin();
    for(int i = 0;it!=imageMap.end() && i<NUM;++it,i++)
    {
        m_MyWidget[i].GetImage(it.value());
    }

    scrollArea->setWidget(widget);
    this->resize(820,440);
}

GetNetworkImage::~GetNetworkImage()
{
    delete [] m_MyWidget;
}

bool GetNetworkImage::event(QEvent *event)
{
    if(event->type() == QEvent::Resize)
    {
        scrollArea->resize(this->width(),this->height());
        return true;
    }
    return QWidget::event(event);
}

