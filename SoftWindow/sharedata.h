#ifndef SHAREDATA_H
#define SHAREDATA_H
#include <QString>
#include <QMap>

struct CLASSSTRUCT{
    int category;
    QString proImage;
    QString proName;
    int proStar;
    QString proDescription;
    CLASSSTRUCT(int cate,const QString & image,const QString & name,int star,const QString & desc):
        category(cate),proImage(image),proName(name),proStar(star),proDescription(desc){}
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

struct SCREENIMAGE{
    int imageId;
    int releaseId;
    QString imageUrl;
    SCREENIMAGE(int imageid,int releaseid,const QString & imageurl):
        imageId(imageid),releaseId(releaseid),imageUrl(imageurl){}
};

typedef QMap<int,QString> CATEGORYMAP;
typedef QMap<int,CLASSSTRUCT> CLASSSTRUCTMAP;
typedef QMap<int,int> ELEMENTNUMBERMAP;
typedef QMap<int,UPDATESTRUCT> UPDATESTRUCTMAP;
typedef QMap<int,int> RECOMMENDMAP;
typedef QMap<int,SCREENIMAGE> SCREENIMAGEMAP;

class ShareData
{
public:
    CATEGORYMAP cateMap;
    CLASSSTRUCTMAP classStrMap;
    ELEMENTNUMBERMAP classElementNumMap;
    UPDATESTRUCTMAP updateStrMap;
    RECOMMENDMAP recommendMap;
    SCREENIMAGEMAP screenImageMap;
};

#endif // SHAREDATA_H
