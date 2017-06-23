#ifndef JSON_FUNC_H
#define JSON_FUNC_H

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
    QString btn_image;
    QString btn_name;
    int btn_star;
    SORTSTRUCT(int cate,const QString & image,const QString & name,int star):
        category(cate),btn_image(image),btn_name(name),btn_star(star){}
};


class JSON_FUNC : public QObject
{
    Q_OBJECT

public:
    JSON_FUNC();
    int get_Category_Num();
    void set_App_name();

protected slots:
    void read_process();

signals:
    void curl_IsOk();

private:
    int json_Flag;
    int category_Num;
    QProcess *process ;
    int flag;
//    QStringList arg;

};

#endif // JSON_FUNC_H
