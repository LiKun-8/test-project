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
#include "sharedata.h"


class SoftThread : public QThread
{
    Q_OBJECT

public:
    SoftThread(int jsonFlag,ShareData *shareData);
    void setElement(Element *e);

//protected:
    void run();

private:
    Element *element;
    QProcess *process ;
    int flag;
    QStringList arg;
    ShareData *shareDataThread;

protected slots:
//    void readprocess();
    void sta();
};

#endif // SOFTTHREADH
