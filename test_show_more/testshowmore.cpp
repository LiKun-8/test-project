#include "testshowmore.h"

TestShowMore::TestShowMore(QWidget *parent)
    : QMainWindow(parent)
{
    num = 0;
}

TestShowMore::TestShowMore(const TestShowMore &other)
{

}

TestShowMore &TestShowMore::operator =(const TestShowMore &other)
{

}

void TestShowMore::testPrint() const
{
    qDebug()<<"it is : "<<num<<endl;
}

TestShowMore::~TestShowMore()
{

}

void TestShowMore::setNum(int x)
{
    num = x;
}
