#include "testvirtual.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestShowMore w;

    TestVirtual x;
    x.setnum();
    x.displayOutput(w);
    x.displayOutput(x);
//    x.testPrint();

    return a.exec();
}
