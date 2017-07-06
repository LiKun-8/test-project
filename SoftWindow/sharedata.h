#ifndef SHAREDATA_H
#define SHAREDATA_H
#include <QString>
#include <QMap>

struct CLASSSTRUCT{
    int category;
    QString btnImage;
    QString btnName;
    int btnStar;
    CLASSSTRUCT(int cate,const QString & image,const QString & name,int star):
        category(cate),btnImage(image),btnName(name),btnStar(star){}
};

struct UPDATESTRUCT{
    int productId;
//    int releaseId;
    QString version;
    QString btnImage;
//    QString btnName;
    QString changeLog;
    QString downloadUrl;
    double packageSize;
    UPDATESTRUCT(int id,QString ver,const QString &image,const QString & changelog,const QString & downloadurl,double packagesize):
        productId(id),version(ver),btnImage(image),changeLog(changelog),downloadUrl(downloadurl),packageSize(packagesize){}
};

typedef QMap<int,QString> CATEGORYMAP;
typedef QMap<int,CLASSSTRUCT> CLASSSTRUCTMAP;
typedef QMap<int,int> ELEMENTNUMBERMAP;
typedef QMap<int,UPDATESTRUCT> UPDATESTRUCTMAP;

class ShareData
{
public:
    ShareData();

    CATEGORYMAP cateMap;
    CLASSSTRUCTMAP classStrMap;
    ELEMENTNUMBERMAP classElementNumMap;
    UPDATESTRUCTMAP updateStrMap;
};

#endif // SHAREDATA_H
