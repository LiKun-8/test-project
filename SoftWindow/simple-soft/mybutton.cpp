#include "mybutton.h"
#include <QDebug>
#include <QToolTip>
MyButton::MyButton()
{

}

MyButton::~MyButton()
{

}

void MyButton::enterEvent(QEvent *)
{
    setStyleSheet("QPushButton{background: dodgerblue;}");
}

void MyButton::leaveEvent(QEvent *)
{
    setStyleSheet("QPushButton{background: none;}");
}

