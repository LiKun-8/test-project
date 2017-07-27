#ifndef THREADWIDGET_H
#define THREADWIDGET_H

#include <QWidget>
#include <QProgressBar>
#include <QDialog>

class ThreadWidget : public QDialog
{
    Q_OBJECT
public:
    explicit ThreadWidget();
    QProgressBar *bar;
    void showbar();
    void outputNum(int i);
signals:

public slots:

};

#endif // THREADWIDGET_H
