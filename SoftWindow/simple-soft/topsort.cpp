#include "topsort.h"
#include <QDebug>

Top_Sort::Top_Sort()
{
    category = 0;
    widget = new QWidget();
    btn_Top = new QPushButton();
    btn_Top->setFlat(true);
    label_Top = new QLabel();
    spacer_Top = new QSpacerItem(0,48,QSizePolicy::Expanding,QSizePolicy::Minimum);
    label_Top->setStyleSheet("border-left-width: 3px;border-style: solid;border-left-color: rgb(65,105,225);");
    label_Top->setMaximumHeight(16);
    label_Top->setContentsMargins(8,0,0,0);

    set_Btn_Data();
//    set_Label_Data();


    line_Top = new QLabel();
    line_Top->setStyleSheet("border-top-width: 1px;border-style: solid;border-top-color: rgb(220, 220, 220);");
    line_Top->setMaximumHeight(32);

    //美化布局
    hb_Top_Layout = new QHBoxLayout();
    hb_Top_Layout->addWidget(label_Top);
    hb_Top_Layout->addSpacerItem(spacer_Top);
    hb_Top_Layout->addWidget(btn_Top);

    vb_Top_Layout = new QVBoxLayout();
    vb_Top_Layout->setSpacing(0);
    vb_Top_Layout->setMargin(0);
    vb_Top_Layout->addLayout(hb_Top_Layout);
    vb_Top_Layout->addWidget(line_Top);
    vb_Top_Layout->setContentsMargins(16,0,16,0);

    widget->setLayout(vb_Top_Layout);
    widget->setMaximumHeight(48);
    btn_Top->setFocusPolicy(Qt::NoFocus);
    btn_Top->setMaximumWidth(48);
    btn_Top->setStyleSheet("text-align: right;");//设置按钮文字显示位置
    btn_Top->setStyleSheet("background-color: rgb(255, 128, 64);");//设置按钮背景颜色
    btn_Top->setCursor(Qt::PointingHandCursor);
    connect(btn_Top,SIGNAL(clicked(bool)),this,SLOT(send_Slot_Btn()));
}

Top_Sort::~Top_Sort()
{

}

void Top_Sort::set_Btn_Data()
{
    btn_Top->setText("更多  >");
}

void Top_Sort::set_Label_Data(QString data)
{
    label_Top->setText(data);
}

void Top_Sort::set_category(int cate)
{
    category = cate;
}

void Top_Sort::set_Topbtn_Hide()
{
    btn_Top->hide();
}

void Top_Sort::send_Slot_Btn()
{
    emit show_All(category);
//    qDebug()<<"top sort  show all!"<<endl;
}
