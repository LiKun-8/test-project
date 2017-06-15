#include "softwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SoftWindow w;
    w.show();

    return a.exec();
}
