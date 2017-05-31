#include "sortwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SortWidget  w;
//    w.setWindowFlags(Qt::FramelessWindowHint);
    w.widget->show();
    w.show();
    return a.exec();
}
