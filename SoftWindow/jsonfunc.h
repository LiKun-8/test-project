#ifndef JSONFUNCH
#define JSONFUNCH

#include <QObject>
#include <QProcess>
#include <QByteArray>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMap>

#define CATEGORIES  1
#define PRODUCT     2
#define PRODUCTS    3

struct SORTSTRUCT{
    int category;
    QString btnimage;
    QString btnname;
    int btnstar;
    SORTSTRUCT(int cate,const QString & image,const QString & name,int star):
        category(cate),btnimage(image),btnname(name),btnstar(star){}
};


class JSONFUNC : public QObject
{
    Q_OBJECT

public:
    JSONFUNC();
    int getCategoryNum();
    void setAppname();

protected slots:
    void readprocess();

signals:
    void curlIsOk();

private:
    int jsonFlag;
    int categoryNum;
    QProcess *process ;
    int flag;
//    QStringList arg;

};

#endif // JSONFUNCH
