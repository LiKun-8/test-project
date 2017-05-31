#ifndef ELEMENT_H
#define ELEMENT_H
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

class Element
{
public:
    Element();
    ~Element();

    QWidget *base_Widget;
    void init();
    void set_BtnImage(QString imagePath);
    void set_BtnName(QString name);
    void set_BtnStart();
    void set_BtnStatus();
private:
    QPushButton *btn_Image;
    QPushButton *btn_Name;
    QPushButton *btn_Start;
    QPushButton *btn_Status;
    QVBoxLayout *vb_Layout;
    QHBoxLayout *hb_Layout;
};

#endif // ELEMENT_H

