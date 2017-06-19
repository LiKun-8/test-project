#include "element.h"
#include <QFont>
#include <QDebug>

Element::Element()
{
    base_Widget = new QWidget();
    base_Widget->setFixedSize(144,74);

    vb_Layout = new QVBoxLayout();
    hb_Layout = new QHBoxLayout();

    btn_Image = new QPushButton();
    btn_Image->setFixedSize(64,64);
//    btn_Image->setStyleSheet("background-image:url(:/image/gift.png);outline: none;");
    set_BtnImage("/home/lk/qt-project/SoftWindow/image/gift.png");
    btn_Name = new QPushButton();
    btn_Name->setFixedSize(72,22);
    btn_Name->setStyleSheet("text-align: left;");//设置按钮文字显示位置-左对齐

    //    QFont xx("Timer",12,QFont::Bold);
    //    btn_Name->setFont(xx);
    btn_Image->setFlat(true);
    btn_Name->setFlat(true);
    vb_Layout->addWidget(btn_Name);
    vb_Layout->setMargin(0);
    vb_Layout->setSpacing(0);

    hb_Layout->addWidget(btn_Image);
    init();
    hb_Layout->addLayout(vb_Layout);
    hb_Layout->setMargin(0);
    hb_Layout->setSpacing(0);
    base_Widget->setLayout(hb_Layout);
}

Element::~Element()
{

}

void Element::init()
{
    btn_Start = new QPushButton();
    btn_Start->setFixedSize(72,10);
    btn_Start->setEnabled(false);
    btn_Status = new MyButton();
    btn_Status->setFixedSize(72,24);
    //    btn_Start->setFlat(true);
    //    btn_Status->setFlat(true);
    vb_Layout->addWidget(btn_Start);
    vb_Layout->addWidget(btn_Status);
    set_BtnStatus("download");
    connect(btn_Status,SIGNAL(clicked(bool)),this,SLOT(btn_Status_Slot()));

    //去除矩形虚线框
    btn_Name->setFocusPolicy(Qt::NoFocus);
    btn_Image->setFocusPolicy(Qt::NoFocus);
    btn_Start->setFocusPolicy(Qt::NoFocus);
    btn_Status->setFocusPolicy(Qt::NoFocus);
}

void Element::set_BtnImage(QString imagePath)
{
    QPixmap pix = QPixmap(imagePath);
    btn_Image->setIcon(pix);
    btn_Image->setIconSize(pix.size());
//    btn_Image->setStyleSheet(imagePath);
}

void Element::set_BtnName(QString name)
{
    //使文本生成省略号(...)
    QFontMetrics metrice(btn_Name->font());
    QString nameText = metrice.elidedText(name,Qt::ElideRight,btn_Name->width());
    btn_Name->setText(nameText);
    btn_Name->setToolTip(name);
}

void Element::set_BtnStart()
{

}

void Element::set_BtnStatus(QString status)
{
    btn_Status->setText(status);
    btn_Status->setToolTip(status);
}

void Element::set_Button(bool)
{

}

void Element::btn_Status_Slot()
{
    btn_Status->setText("NULL");
    btn_Status->setEnabled(false);
//    qDebug()<<"btn  status slot"<<endl;
    btn_Status->setToolTip(btn_Status->text());
}

void Element::set_category(int cate)
{
    category = cate;
    qDebug()<<"Element   category is : "<<category<<endl;
}
