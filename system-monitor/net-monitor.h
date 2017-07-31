#ifndef NETMONITOR_H
#define NETMONITOR_H

#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QVBoxLayout>

class NetMonitor : public QWidget
{
    Q_OBJECT
public:
    explicit NetMonitor(QWidget *parent = 0);

private:
    QLabel *labelInfo;
    QLabel *labelName;
    QVBoxLayout *vbLayout;

signals:

public slots:
};

#endif // NETMONITOR_H
