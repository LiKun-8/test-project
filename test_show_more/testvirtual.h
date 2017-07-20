#ifndef TESTVIRTUAL_H
#define TESTVIRTUAL_H
#include "testshowmore.h"


class TestVirtual : public TestShowMore
{
public:
    TestVirtual();
    void setnum();
    void displayOutput(const TestShowMore &test);
//    void testPrint() const;

private:
    int x;
};

#endif // TESTVIRTUAL_H
