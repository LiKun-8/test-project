#include "element.h"
#include <QFont>
#include <QDebug>

Element::Element()
{
    baseWidget = new QWidget();
    baseWidget->setFixedSize(144,74);

    vbLayout = new QVBoxLayout();
    hbLayout = new QHBoxLayout();

    btnImage = new QPushButton();
    btnImage->setFixedSize(64,64);
//    btnImage->setStyleSheet("background-image:url(:/image/gift.png);outline: none;");
    btnName = new QPushButton();
    btnName->setFixedSize(72,22);
    btnName->setStyleSheet("text-align: left;");//设置按钮文字显示位置-左对齐

    //    QFont xx("Timer",12,QFont::Bold);
    //    btnName->setFont(xx);
    btnImage->setFlat(true);
    btnName->setFlat(true);
    vbLayout->addWidget(btnName);
    vbLayout->setMargin(0);
    vbLayout->setSpacing(0);

    hbLayout->addWidget(btnImage);
    Init();
    hbLayout->addLayout(vbLayout);
    hbLayout->setMargin(0);
    hbLayout->setSpacing(0);
    baseWidget->setLayout(hbLayout);
}

Element::~Element()
{

}

void Element::Init()
{
    btnstar = new QPushButton();
    btnstar->setFixedSize(72,10);
    btnstar->setEnabled(false);
    btnStatus = new CustomButton();
    btnStatus->setFixedSize(72,24);
    //    btnstar->setFlat(true);
//        btnStatus->setFlat(true);
    vbLayout->addWidget(btnstar);
    vbLayout->addWidget(btnStatus);
    SetBtnStatus("download");
    connect(btnStatus,SIGNAL(clicked(bool)),this,SLOT(BtnStatusSlot()));

    //去除矩形虚线框
    btnName->setFocusPolicy(Qt::NoFocus);
    btnImage->setFocusPolicy(Qt::NoFocus);
    btnstar->setFocusPolicy(Qt::NoFocus);
    btnStatus->setFocusPolicy(Qt::NoFocus);
    btnStatus->setCursor(Qt::PointingHandCursor);
    btnName->setCursor(Qt::PointingHandCursor);
    btnImage->setCursor(Qt::PointingHandCursor);
}

void Element::SetBtnImage(QString imagePath)
{
    QPixmap pix = QPixmap(imagePath);
    btnImage->setIcon(pix);
    btnImage->setIconSize(pix.size());
//    btnImage->setStyleSheet(imagePath);
}

void Element::SetBtnName(QString name)
{
    //使文本生成省略号(...)
    QFontMetrics metrice(btnName->font());
    QString nameText = metrice.elidedText(name,Qt::ElideRight,btnName->width());
    btnName->setText(nameText);
    btnName->setToolTip(name);
}

void Element::SetBtnStart()
{

}

void Element::SetBtnStatus(QString status)
{
    btnStatus->setText(status);
    btnStatus->setToolTip(status);
}

void Element::SetButton(bool)
{

}

void Element::BtnStatusSlot()
{
    btnStatus->setText("NULL");
    btnStatus->setEnabled(false);
    btnStatus->setToolTip(btnStatus->text());
}

void Element::Setcategory(int cate)
{
    category = cate;
}
