#include "jsonfunc.h"
#include <QDebug>

JSONFUNC::JSONFUNC(ShareData *shareData)
{
    manager = new QNetworkAccessManager();
    jsonData = shareData;
    jsonFlag = 0;
    categoryNum = 0;
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(jsonAnalysis(QNetworkReply*)));
}

//获取分类数目
void JSONFUNC::getCategoryNum()
{
    jsonFlag = CATEGORIES;
    manager->get(QNetworkRequest(QUrl("http://127.0.0.1:8888/categories")));
}

void JSONFUNC::getRelease()
{
    jsonFlag = RELEASE;
    manager->get(QNetworkRequest(QUrl("http://127.0.0.1:8888/release")));
}

//设置软件名字
void JSONFUNC::setAppname()
{
    jsonFlag = PRODUCTS;
    manager->get(QNetworkRequest(QUrl("http://127.0.0.1:8888/products")));
}

void JSONFUNC::jsonAnalysis(QNetworkReply *reply)
{
//    qDebug()<<__FUNCTION__<<endl;
    QByteArray dataRead;
    dataRead = reply->readAll();
    QJsonParseError jsonerror;
    QJsonDocument document = QJsonDocument::fromJson(dataRead,&jsonerror);

    if(jsonerror.error == QJsonParseError::NoError)
    {
        if(document.isObject())
        {
            QJsonObject obj = document.object();
            if(jsonFlag == CATEGORIES)
            {
               getCategoryNum(obj);
            }

            if(jsonFlag == PRODUCTS)
            {
                getProducts(obj);
            }
            if(jsonFlag == RELEASE)
            {
                getRelease(obj);
            }
        }
    }
    else {
        qDebug()<<"json is error"<<endl;
    }
}

void JSONFUNC::getCategoryNum(QJsonObject obj)
{
    if(obj.contains("Categories"))
    {
        QJsonValue test = obj.take("Categories");
        if(test.isArray())
        {
            QJsonArray str = test.toArray();
            int size = str.size();
            categoryNum = size;

            for(int i = 0;i < size;i++ )
            {
                QJsonValue value = str.at(i);
                if(value.isObject())
                {
                    int cate;
                    QString name;
                    QJsonObject obj2 = value.toObject();
                    if(obj2.contains("category_id"))
                    {
                        QJsonValue category = obj2.take("category_id");
                        if(category.isDouble())
                        {
                            cate = category.toInt();
                        }
                    }

                    if(obj2.contains("category_name"))
                    {
                        QJsonValue categoryname = obj2.take("category_name");
                        if(categoryname.isString())
                        {
                            name = categoryname.toString();
                            //                                        qDebug()<<name<<endl;
                        }
                    }
                    jsonData->cateMap[cate] = name;
                }
            }
        }
        //                    qDebug()<<"categoryNum  ==  "<<categoryNum<<endl;
        emit numIsOk(categoryNum);
    }
}

void JSONFUNC::getProducts(QJsonObject obj)
{
    if(obj.contains("products"))
    {
        QJsonValue pro = obj.take("products");
        if(pro.isArray())
        {
            QJsonArray str = pro.toArray();
            int size = str.size();
            QJsonValue categoryid ;

            int lnProductId;
            int relid;
            int cateid;
            int procate;
            int gracount;
            QString proname;
            QString venname;
            QString icourl;
            QString prourl;
            QString prodesc;
            QMap<int,int>::iterator it;
            int y = 0;

            for(int i = 0;i < size;i++)
            {
                QJsonValue value = str.at(i);

                if(value.isObject())
                {
                    QJsonObject obj2 = value.toObject();

                    if(obj2.contains("product_id"))
                    {
                        QJsonValue productid = obj2.take("product_id");
                        if(productid.isDouble())
                        {
                            lnProductId = productid.toInt();
                            //                                        qDebug()<<"productid : "<<lnProductId<<endl;
                        }
                    }

                    if(obj2.contains("release_id"))
                    {
                        QJsonValue releaseid = obj2.take("release_id");
                        if(releaseid.isDouble())
                        {
                            relid = releaseid.toInt();
                            //                                        qDebug()<<"releaseid : "<<relid<<endl;
                        }
                    }

                    if(obj2.contains("category_id"))
                    {
                        categoryid = obj2.take("category_id");
                        if(categoryid.isDouble())
                        {
                            cateid = categoryid.toInt();
                            //                                        qDebug()<<"categoryid : "<<cateid<<endl;
                            it = jsonData->classElementNumMap.find(cateid);
                            if(it != jsonData->classElementNumMap.end())
                            {
                                jsonData->classElementNumMap[cateid] = it.value()+1;
                            }
                            else
                            {
                                jsonData->classElementNumMap.insert(cateid,1);
                            }
                        }
                    }

                    if(obj2.contains("product_name"))
                    {
                        QJsonValue productname = obj2.take("product_name");
                        if(productname.isString())
                        {
                            proname = productname.toString();
                        }
                    }

                    if(obj2.contains("vendor_name"))
                    {
                        QJsonValue vendorname = obj2.take("vendor_name");
                        if(vendorname.isString())
                        {
                            venname = vendorname.toString();
                            //                                        qDebug()<<"vendorname : "<<venname<<endl;
                        }
                    }

                    if(obj2.contains("icon_url"))
                    {
                        QJsonValue iconurl = obj2.take("icon_url");
                        if(iconurl.isString())
                        {
                            icourl = iconurl.toString();
                            //                                        qDebug()<<"icon_url : "<<icourl<<endl;
                        }
                    }

                    if(obj2.contains("url"))
                    {
                        QJsonValue url = obj2.take("url");
                        if(url.isString())
                        {
                            prourl = url.toString();
                            //                                        qDebug()<<"url : "<<prourl<<endl;
                        }
                    }

                    if(obj2.contains("product_description"))
                    {
                        QJsonValue productdescription = obj2.take("product_description");
                        if(productdescription.isString())
                        {
                            prodesc = productdescription.toString();
                            //                                        qDebug()<<"productdescription : "<<prodesc<<endl;
                        }
                    }

                    if(obj2.contains("product_grade"))
                    {
                        QJsonValue productgrade = obj2.take("product_grade");
                        if(productgrade.isDouble())
                        {
                            procate = productgrade.toInt();
                            //                                        qDebug()<<"productgrade : "<<procate<<endl;
                        }
                    }

                    if(obj2.contains("grade_count"))
                    {
                        QJsonValue gradecount = obj2.take("grade_count");
                        if(gradecount.isDouble())
                        {
                            gracount = gradecount.toInt();
                            //                                        qDebug()<<"gradecount : "<<gracount<<endl;
                        }
                    }
                    //                                                                qDebug()<<"cateid : "<<cateid<<endl;
                    //                                                                qDebug()<<"icourl : "<<icourl<<endl;
                    //                                                                qDebug()<<"proname : "<<proname<<endl;
                     if(y<10)
                    {
                        icourl = QString("%1%2%3").arg("http://k2.jsqq.net/uploads/allimg/1705/7_170524143440_").arg(y+1).arg(".jpg");
                        y++;
                    }
                    else
                    {
                        icourl = QString("%1%2%3").arg("http://k2.jsqq.net/uploads/allimg/1705/7_170524143440_").arg(1).arg(".jpg");
                        y = 1;
                    }
                    jsonData->classStrMap.insert(lnProductId,CLASSSTRUCT(cateid,icourl,proname,0));
                }
            }
        }
        emit curlIsOk();
    }
}

void JSONFUNC::getRelease(QJsonObject obj)
{
    QString product = "releases";
    if(obj.contains(product))
    {
        QJsonValue pro = obj.take(product);
        if(pro.isArray())
        {
            QJsonArray str = pro.toArray();
            int size = str.size();

            int proid;
            int relid;
            double ver;
            double packsize;
            QString chaglog;
            QString downurl;
            QString icourl;
            QString name;
            UPDATESTRUCTMAP::iterator update;
            CLASSSTRUCTMAP::iterator classit;
            for(int i = 0;i < size;i++)
            {
                QJsonValue value = str.at(i);

                if(value.isObject())
                {
                    QJsonObject obj2 = value.toObject();

                    if(obj2.contains("product_id"))
                    {
                        QJsonValue productid = obj2.take("product_id");
                        if(productid.isDouble())
                        {
                            proid = productid.toInt();
                        }
                    }

                    if(obj2.contains("release_id"))
                    {
                        QJsonValue releaseid = obj2.take("release_id");
                        if(releaseid.isDouble())
                        {
                            relid = releaseid.toInt();
                        }
                    }

                    if(obj2.contains("version"))
                    {
                        QJsonValue version = obj2.take("version");
                        if(version.isDouble())
                        {
                            ver = version.toDouble();
                        }
                    }

                    if(obj2.contains("change_log"))
                    {
                        QJsonValue changelog = obj2.take("change_log");
                        if(changelog.isString())
                        {
                            chaglog = changelog.toString();
                        }
                    }

                    if(obj2.contains("package_size"))
                    {
                        QJsonValue packagesize = obj2.take("package_size");
                        if(packagesize.isString())
                        {
                            packsize = packagesize.toDouble();
                        }
                    }

                    if(obj2.contains("icon_url"))
                    {
                        QJsonValue iconurl = obj2.take("icon_url");
                        if(iconurl.isString())
                        {
                            icourl = iconurl.toString();
                        }
                    }

                    if(obj2.contains("download_url"))
                    {
                        QJsonValue downloadurl = obj2.take("download_url");
                        if(downloadurl.isString())
                        {
                            downurl = downloadurl.toString();
                        }
                    }

                    if(obj2.contains("icon_url"))
                    {
                        classit = jsonData->classStrMap.find(proid);
                        name = classit.value().btnName;
                    }
                    //                                                                qDebug()<<"cateid : "<<cateid<<endl;
                    //                                                                qDebug()<<"icourl : "<<icourl<<endl;
                    //                                                                qDebug()<<"proname : "<<proname<<endl;
                    //                                classStrMap.insert(lnProductId,CLASSSTRUCT(cateid,icourl,proname,0));
                }
            }
        }
    }
}



