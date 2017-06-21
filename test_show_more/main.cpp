#include "testshowmore.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestShowMore w;
    w.show();

    return a.exec();
}
