#ifndef THREAD_H
#define THREAD_H
#include <QThread>
#include <QProgressBar>
#include <QObject>
#include "threadwidget.h"

class Thread : public QThread
{
    Q_OBJECT

public:
    Thread();
private:
    void run();
    QProgressBar *progressBar;
    static int num;
    static int row;
    ThreadWidget *widbar;
signals:
    void updateBar(int i);

protected slots:
    void message();
};

#endif // THREAD_H
