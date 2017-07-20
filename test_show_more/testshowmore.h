#ifndef TESTSHOWMORE_H
#define TESTSHOWMORE_H

#include <QMainWindow>
#include <QDebug>

class TestShowMore : public QMainWindow
{
    Q_OBJECT

public:
    TestShowMore(QWidget *parent = 0);
    TestShowMore(const TestShowMore& other);
    TestShowMore& operator = (const TestShowMore& other);
    virtual void testPrint() const;
    ~TestShowMore();
    void setNum(int x);

private:
    int num;
};


#endif // TESTSHOWMORE_H
