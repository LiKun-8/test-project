#include "thread.h"
#include "api/myhelper.h"
#include <QDebug>

int Thread::num = 0;
int Thread::row = 0;

Thread::Thread()
{
    progressBar = new QProgressBar();
    connect(this,SIGNAL(finished()),this,SLOT(message()),Qt::QueuedConnection);
}

void Thread::run()
{
    qDebug()<<"this id : "<<this->currentThreadId();
    for(int i = 0; i<=4999;i++)
    {
        myHelper::sleep(1);
        emit updateBar(i);
    }
}

void Thread::message()
{
    qDebug()<<"the thread is finished!"<<endl;
}
