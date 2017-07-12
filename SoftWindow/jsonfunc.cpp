#include "jsonfunc.h"
#include "qreplytimeout.h"
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

void JSONFUNC::getUpdateRelease(int array,int size)
{
    int a[5] = {101,28,55,66,44};
    QByteArray dataArr;
    //    dataArr.append("[");
    //    for(int i = 0;i<2;i++)
    //    {
    //        if(i == 0)
    //            dataArr.append(a[i]);
    //        else
    //        {
    //            dataArr.append(',');
    //            dataArr.append(a[i]);
    //        }
    //    }
    //    dataArr.append("]");

    QString dataStr = "[";
    for(int i=0;i<5;i++)
    {
        if(i == 0)
            dataStr += QString::number(a[i]);
        else
        {
            dataStr += (",");
            dataStr += QString::number(a[i]);
        }
    }
    dataStr += "]";

    dataArr = dataStr.toLatin1();
    //    qDebug()<<"dataArr == "<<dataArr<<endl;

    QString baseUrl = "http://127.0.0.1:8888/releases";
    QUrl url(baseUrl);
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setUrl(url);

    jsonFlag = RELEASE;
    manager->post(request,dataArr);
}

//设置软件名字
void JSONFUNC::setAppname()
{
    jsonFlag = PRODUCTS;
    manager->get(QNetworkRequest(QUrl("http://127.0.0.1:8888/products")));
}

void JSONFUNC::getRecommend()
{
    jsonFlag = RECOMMEND;
    manager->get(QNetworkRequest(QUrl("http://127.0.0.1:8888/recommend")));
}

void JSONFUNC::getScreenImage()
{
    jsonFlag = SCRIMAGE;
//    manager->get();
}

void JSONFUNC::jsonAnalysis(QNetworkReply *reply)
{
    QByteArray dataRead;
    dataRead = reply->readAll();

    QReplyTimeout *pTimeout = new QReplyTimeout(reply, 1000);
    // 超时进一步处理
    connect(pTimeout, &QReplyTimeout::timeout, [=]() {
        qDebug() << "Timeout";
    });

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
            else if(jsonFlag == PRODUCTS)
            {
                getProducts(obj);
            }
            else if(jsonFlag == RELEASE)
            {
                getUpdateRelease(obj);
            }
            else if(jsonFlag == RECOMMEND)
            {
                getRecommend(obj);
            }
            else if(jsonFlag == SCRIMAGE)
            {
                getScreenImage(obj);
            }
        }
    }
    else {
        qDebug()<<"json is error"<<endl;
    }
    reply->deleteLater();
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

                    if(obj2.contains("ID"))
                    {
                        QJsonValue category = obj2.take("ID");
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
        emit categoryIsOk(categoryNum);
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

            int lnProductId = 0;
            int relid = 0;
            int cateid = 0;
            int procate = 0;
            int gracount = 0;
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

                    if(obj2.contains("ID"))
                    {
                        QJsonValue productid = obj2.take("ID");
                        if(productid.isDouble())
                        {
                            lnProductId = productid.toInt();
                            //                                        qDebug()<<"productid : "<<lnProductId<<endl;
                        }
                    }

                    if(obj2.contains("release_ID"))
                    {
                        QJsonValue releaseid = obj2.take("release_ID");
                        if(releaseid.isDouble())
                        {
                            relid = releaseid.toInt();
                            //                                        qDebug()<<"releaseid : "<<relid<<endl;
                        }
                    }

                    if(obj2.contains("category_ID"))
                    {
                        categoryid = obj2.take("category_ID");
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
                        qDebug()<<gracount<<endl;
                        if(gradecount.isDouble())
                        {
                            gracount = gradecount.toInt();
                        }
                        if(gracount >5 || gracount <0)
                        {
                            gracount = 0;
                            qDebug()<<"gradecount star  is error !"<<endl;
                        }
                    }
//                    qDebug()<<"cateid : "<<cateid<<endl;
//                    qDebug()<<"icourl : "<<gracount<<endl;
//                    qDebug()<<"proname : "<<prodesc<<endl;
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
                    jsonData->classStrMap.insert(lnProductId,CLASSSTRUCT(cateid,icourl,proname,0,prodesc));
                }
            }
        }
        emit productIsOk();
    }
}

void JSONFUNC::getUpdateRelease(QJsonObject obj)
{    
    qDebug()<<__FUNCTION__;
    if(obj.contains("releases"))
    {
        QJsonValue test = obj.take("releases");
        if(test.isArray())
        {
            QJsonArray str = test.toArray();

            for(int i = 0;i < str.size();i++ )
            {
                QJsonValue value = str.at(i);
                int proid = 0;
                //                int relid = 0;
                QString ver;
                double packsize = 0;
                QString chaglog;
                QString downurl;
                QString icourl;

                if(value.isObject())
                {
                    QJsonObject obj2 = value.toObject();

                    if(obj2.contains("product_ID"))
                    {
                        QJsonValue productid = obj2.take("product_ID");
                        if(productid.isDouble())
                        {
                            proid = productid.toInt();
                        }
                    }

                    //                    if(obj2.contains("ID"))
                    //                    {
                    //                        QJsonValue releaseid = obj2.take("ID");
                    //                        if(releaseid.isDouble())
                    //                        {
                    //                            relid = releaseid.toInt();
                    //                        }
                    //                    }

                    if(obj2.contains("version"))
                    {
                        QJsonValue version = obj2.take("version");
                        if(version.isString())
                        {
                            ver = version.toString();
                        }
                    }

                    if(obj2.contains("changelog"))
                    {
                        QJsonValue changelog = obj2.take("changelog");
                        if(changelog.isString())
                        {
                            chaglog = changelog.toString();
                        }
                    }

                    if(obj2.contains("package_size"))
                    {
                        QJsonValue packagesize = obj2.take("package_size");
                        if(packagesize.isDouble())
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

                    //                                qDebug()<<"relid : "<<relid<<endl;
                    //                    qDebug()<<"proid : "<<proid<<endl;
                    //                    qDebug()<<"chaglog : "<<chaglog<<endl;
                    //                    qDebug()<<"packsize : "<<packsize<<endl;
                    //                    qDebug()<<"icourl : "<<icourl<<endl;
                    //                    qDebug()<<"downurl : "<<downurl<<endl;
                    //                    qDebug()<<"ver : "<<ver<<endl;
                    jsonData->updateStrMap.insert(proid,UPDATESTRUCT(proid,ver,icourl,chaglog,downurl,packsize));
                }
            }
            emit updateIsOk();
        }
    }
}

void JSONFUNC::getRecommend(QJsonObject obj)
{
    if(obj.contains("Recommend"))
    {
        QJsonValue test = obj.take("Recommend");
        if(test.isArray())
        {
            QJsonArray str = test.toArray();
            int size = str.size();

            for(int i = 0;i < size;i++ )
            {
                QJsonValue value = str.at(i);

                if(value.isObject())
                {
                    int id = 0;
                    int priority = 0;
                    QJsonObject obj2 = value.toObject();

                    if(obj2.contains("ID"))
                    {
                        QJsonValue num = obj2.take("ID");
                        if(num.isDouble())
                        {
                            id = num.toInt();
                        }
                    }

                    if(obj2.contains("priority"))
                    {
                        QJsonValue pri = obj2.take("priority");
                        if(pri.isDouble())
                        {
                            priority = pri.toInt();
                        }
                    }
                    jsonData->recommendMap[id] = priority;
                }
            }
        }
        //                    qDebug()<<"recommendMap  ==  "<<id<<endl;
        emit recommendIsOk();
    }
}

void JSONFUNC::getScreenImage(QJsonObject obj)
{
    if(obj.contains("ScreenImage"))
    {
        QJsonValue test = obj.take("ScreenImage");
        if(test.isArray())
        {
            QJsonArray str = test.toArray();
            int size = str.size();

            for(int i = 0;i < size;i++ )
            {
                QJsonValue value = str.at(i);

                if(value.isObject())
                {
                    int id = 0;
                    int proId = 0;
                    int relId = 0;
                    QString imageUrl;
                    QJsonObject obj2 = value.toObject();

                    if(obj2.contains("ID"))
                    {
                        QJsonValue num = obj2.take("ID");
                        if(num.isDouble())
                        {
                            id = num.toInt();
                        }
                    }

                    if(obj2.contains("product_ID"))
                    {
                        QJsonValue num = obj2.take("product_ID");
                        if(num.isDouble())
                        {
                            proId = num.toInt();
                        }
                    }

                    if(obj2.contains("release_ID"))
                    {
                        QJsonValue num = obj2.take("release_ID");
                        if(num.isDouble())
                        {
                            relId = num.toInt();
                        }
                    }

                    if(obj2.contains("image_url"))
                    {
                        QJsonValue url = obj2.take("image_url");
                        if(url.isString())
                        {
                            imageUrl = url.toString();
                        }
                    }
                    jsonData->screenImageMap.insert(proId,SCREENIMAGE(id,relId,imageUrl));
                }
            }
        }
    }
}
