#ifndef SOFTTHREAD_H
#define SOFTTHREAD_H

#include <QObject>
#include "simple-soft/element.h"
#include <QThread>
#include <QProcess>
#include <QByteArray>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class SoftThread : public QThread
{
    Q_OBJECT

public:
    SoftThread();
    void set_Element(Element *e);

//protected:
    void run();

private:
    Element *element;
    QProcess *process ;
    int flag;
    QStringList arg;

protected slots:
    void read_process();
    void sta();
};

#endif // SOFTTHREAD_H
