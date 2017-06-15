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
    void init();
    void set_BtnImage(QString imagePath);
    void set_BtnName(QString name);
    void set_BtnStart();
    void set_BtnStatus(QString status);
    void set_Button(bool);
    int category;
    void set_category(int cate);

private slots:
    void btn_Status_Slot();

private:
    QPushButton *btn_Image;
    QPushButton *btn_Name;
    QPushButton *btn_Start;
    MyButton *btn_Status;
    QVBoxLayout *vb_Layout;
    QHBoxLayout *hb_Layout;
};

#endif // ELEMENT_H

