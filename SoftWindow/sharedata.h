#ifndef SHAREDATA_H
#define SHAREDATA_H
#include <QString>
#include <QMap>

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


class ShareData
{
public:
    ShareData();

    CATEGORYMAP cateMap;
    CLASSSTRUCTMAP classStrMap;
    ELEMENTNUMBERMAP classElementNumMap;
};

#endif // SHAREDATA_H
