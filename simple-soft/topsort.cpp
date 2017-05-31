#include "topsort.h"

Top_Sort::Top_Sort()
{
    widget = new QWidget();
    btn_Top = new QPushButton();
    label_Top = new QLabel();
    spacer_Top = new QSpacerItem(0,48,QSizePolicy::Expanding,QSizePolicy::Minimum);


    set_Btn_Data();
    set_Label_Data();

    line_Top = new QLabel();
    line_Top = new QLabel();
    line_Top->setStyleSheet("border-top-width: 1px;border-style: solid;border-top-color: rgb(220, 220, 220);");
    line_Top->setMaximumHeight(32);

    //美化布局
    hb_Top_Layout = new QHBoxLayout();
    hb_Top_Layout->setContentsMargins(16,0,16,0);
    hb_Top_Layout->addWidget(label_Top);
    hb_Top_Layout->addSpacerItem(spacer_Top);
    hb_Top_Layout->addWidget(btn_Top);

    vb_Top_Layout = new QVBoxLayout();
    vb_Top_Layout->setSpacing(0);
    vb_Top_Layout->setMargin(0);
    vb_Top_Layout->addLayout(hb_Top_Layout);
    vb_Top_Layout->addWidget(line_Top);
    widget->setLayout(vb_Top_Layout);
}

void Top_Sort::set_Btn_Data()
{
    btn_Top->setText("更多");
}

void Top_Sort::set_Label_Data()
{
    label_Top->setText("软件");
}
