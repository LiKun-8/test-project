#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "cpu-monitor.h"
#include "memory-monitor.h"
#include "net-monitor.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QSpacerItem>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    CpuMonitor *cpuMonitor;
    MemoryMonitor *memMonitor;
    NetMonitor *netMonitor;
    QVBoxLayout *vbLayout;
    QPushButton *btnApp;
    QPushButton *btnUser;
    QPushButton *btnAll;
    QLabel *labelInfo;
    QHBoxLayout *hbLayout;
    QHBoxLayout *hbMainLayout;
    QVBoxLayout *vbProcessLayout;
    QSpacerItem *spacer;

protected slots:
    void onBtnapp();
    void onBtnall();
    void onBtnuser();
};

#endif // MAINWINDOW_H
