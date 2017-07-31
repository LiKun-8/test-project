#ifndef MEMORYMONITOR_H
#define MEMORYMONITOR_H

#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QVBoxLayout>

class MemoryMonitor : public QWidget
{
    Q_OBJECT
public:
    explicit MemoryMonitor(QWidget *parent = 0);

private:
    QLabel *labelInfo;
    QLabel *labelName;
    QVBoxLayout *vbLayout;

signals:

public slots:
};

#endif // MEMORYMONITOR_H
