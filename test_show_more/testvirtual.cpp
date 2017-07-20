#include "testvirtual.h"

TestVirtual::TestVirtual()
{
}

void TestVirtual::setnum()
{
    setNum(5);
}

//调用const对象上的非const成员函数是不允许的，因为非常量成员函数不允许修
void TestVirtual::displayOutput(const TestShowMore& test)
{
    test.testPrint();
}

//void TestVirtual::testPrint() const
//{
//    qDebug()<<"it is testvirtual."<<endl;
//}
