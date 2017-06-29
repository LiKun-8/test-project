#include "getnetworkimage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GetNetworkImage w;
    w.show();

    return a.exec();
}
