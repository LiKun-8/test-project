#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QEvent>

class MyButton:public QPushButton
{
public:
    MyButton();
    ~MyButton();

private:
    virtual void enterEvent(QEvent*);
    virtual void leaveEvent(QEvent*);
};
#endif // MYBUTTON_H
