#ifndef GETNETWORKIMAGE_H
#define GETNETWORKIMAGE_H

#include <QWidget>
#include <QMap>
#include "mywidget.h"
#include <QScrollArea>
#include <QEvent>
#include <QVBoxLayout>

class GetNetworkImage : public QWidget
{
    Q_OBJECT

public:
    GetNetworkImage(QWidget *parent = 0);
    ~GetNetworkImage();
    QGridLayout *layout;

    MyWidget *m_MyWidget;
    QString testpath;
    QWidget *widget;
    QScrollArea *scrollArea;
    QMap<int,QString> imageMap;
private:
    bool event(QEvent *event);

protected slots:
};

#endif // GETNETWORKIMAGE_H
