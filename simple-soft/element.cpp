#include "element.h"
#include <QFont>

Element::Element()
{
    base_Widget = new QWidget();
    base_Widget->setFixedSize(144,74);

    vb_Layout = new QVBoxLayout();
    hb_Layout = new QHBoxLayout();

    btn_Image = new QPushButton();
    btn_Image->setFixedSize(64,64);
    btn_Name = new QPushButton();
    btn_Name->setFixedSize(72,22);
    set_BtnName("软件");
    //    QFont xx("Timer",12,QFont::Bold);
    //    btn_Name->setFont(xx);
    btn_Start = new QPushButton();
    btn_Start->setFixedSize(72,10);
    btn_Start->setEnabled(false);
    btn_Status = new QPushButton();
    btn_Status->setFixedSize(72,24);
    //    btn_Image->setFlat(true);
    //    btn_Name->setFlat(true);
    //    btn_Start->setFlat(true);
    //    btn_Status->setFlat(true);

    vb_Layout->addWidget(btn_Name);
    vb_Layout->addWidget(btn_Start);
    vb_Layout->addWidget(btn_Status);
    hb_Layout->addWidget(btn_Image);
    hb_Layout->addLayout(vb_Layout);

    vb_Layout->setMargin(0);
    hb_Layout->setMargin(0);
    vb_Layout->setSpacing(0);
    hb_Layout->setSpacing(0);
    base_Widget->setLayout(hb_Layout);
}
Element::~Element()
{

}

void Element::set_BtnImage(QString imagePath)
{
    btn_Image->setStyleSheet(imagePath);
}

void Element::set_BtnName(QString name)
{
    btn_Name->setText(name);
}

void Element::set_BtnStart()
{

}

void Element::set_BtnStatus()
{

}
