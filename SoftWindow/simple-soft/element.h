#ifndef ELEMENT_H
#define ELEMENT_H
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include "mybutton.h"

class Element:public QObject
{
    Q_OBJECT

public:
    Element();
    ~Element();

    QWidget *base_Widget;
    void init();//初始化布局
    void set_BtnImage(QString imagePath);//设置应用图标
    void set_BtnName(QString name);//设置应用名字
    void set_BtnStart();//设置应用评分
    void set_BtnStatus(QString status);//设置应用状态
    void set_Button(bool);
    int category;//应用的分类
    void set_category(int cate);//设置应用分类

private slots:
    void btn_Status_Slot();

private:
    QPushButton *btn_Image;
    QPushButton *btn_Name;
    QPushButton *btn_star;
    MyButton *btn_Status;//自定义的按钮
    QVBoxLayout *vb_Layout;
    QHBoxLayout *hb_Layout;
};

#endif // ELEMENT_H

