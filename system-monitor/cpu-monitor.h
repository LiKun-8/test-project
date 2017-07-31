#ifndef CPUMONITOR_H
#define CPUMONITOR_H

#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QVBoxLayout>

class CpuMonitor : public QWidget
{
    Q_OBJECT
public:
    explicit CpuMonitor(QWidget *parent = 0);

private:
    QLabel *labelInfo;
    QLabel *labelName;
    QVBoxLayout *vbLayout;
signals:

public slots:
};

#endif // CPUMONITOR_H
