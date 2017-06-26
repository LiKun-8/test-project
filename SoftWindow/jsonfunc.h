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

struct CLASSSTRUCT{
    int category;
    QString btnimage;
    QString btnname;
    int btnstar;
    CLASSSTRUCT(int cate,const QString & image,const QString & name,int star):
        category(cate),btnimage(image),btnname(name),btnstar(star){}
};

typedef QMap<int,QString> CATEGORYMAP;
typedef QMap<int,CLASSSTRUCT> CLASSSTRUCTMAP;
typedef QMap<int,int> ELEMENTNUMBERMAP;

class JSONFUNC : public QObject
{
    Q_OBJECT

public:
    JSONFUNC();
    int GetCategoryNum();
    void SetAppname();
    CATEGORYMAP cateMap;
    CLASSSTRUCTMAP classStrMap;
    ELEMENTNUMBERMAP classElementNumMap;

protected slots:
    void ReadProcess();

signals:
    void CurlIsOk();

private:
    int jsonFlag;
    int categoryNum;
    QProcess *process ;
};

#endif // JSONFUNCH
