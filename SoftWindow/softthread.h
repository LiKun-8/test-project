#ifndef SOFTTHREADH
#define SOFTTHREADH

#include <QObject>
#include <QThread>
#include <QProcess>
#include <QByteArray>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "simple-soft/element.h"

class SoftThread : public QThread
{
    Q_OBJECT

public:
    SoftThread();
    void setElement(Element *e);

//protected:
    void run();

private:
    Element *element;
    QProcess *process ;
    int flag;
    QStringList arg;

protected slots:
    void readprocess();
    void sta();
};

#endif // SOFTTHREADH
