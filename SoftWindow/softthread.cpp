#include "softthread.h"
#include <QDebug>

SoftThread::SoftThread()
{
    flag = 0;
    this->connect(this,SIGNAL(started()),this,SLOT(sta()));
}

void SoftThread::setElement(Element *e)
{
    element = new Element();
    element = e;
}

void SoftThread::run()
{
    //    process->kill();
//    qDebug()<<"error error"<<endl;
    arg<<"http://127.0.0.1:8888/products"<< "|"<< "jq"<< ".";
    process = new QProcess();
//    this->connect(process,SIGNAL(readyRead()),this,SLOT(readprocess()));
    process->start("curl",arg);
}

void SoftThread::readprocess()
{
    element[0].setBtnName("xxxxx");
    QByteArray xx = process->readAll();
    qDebug()<<"jsonobject : "<<xx<<endl;
    QJsonParseError jsonerror;
    QJsonDocument document = QJsonDocument::fromJson(xx,&jsonerror);

    if(jsonerror.error == QJsonParseError::NoError)
    {
        if(document.isObject())
        {
            QJsonObject obj = document.object();
            qDebug()<<"1"<<endl;

            //            QString categor = "Categories";
            //            if(obj.contains(categor))
            //            {
            //                qDebug()<<"2"<<endl;

            //                QJsonValue test = obj.take("Categories");
            //                if(test.isArray())
            //                {
            //                    qDebug()<<"test.type()"<<test.type()<<endl;
            //                    QJsonArray str = test.toArray();
            //                    int size = str.size();

            //                    for(int i = 0;i < size;i++ )
            //                    {
            //                        QJsonValue value = str.at(i);
            //                        if(value.isObject())
            //                        {
            //                            QJsonObject obj2 = value.toObject();
            //                            if(obj2.contains("categoryid"))
            //                            {
            //                                QJsonValue category = obj2.take("categoryid");
            //                                if(category.isDouble())
            //                                {
            //                                    int cate = category.toInt();
            //                                    qDebug()<<"Category : "<<cate<<endl;
            //                                }
            //                            }

            //                            if(obj2.contains("categoryname"))
            //                            {
            //                                QJsonValue categoryname = obj2.take("categoryname");
            //                                if(categoryname.isString())
            //                                {
            //                                    QString name = categoryname.toString();
            //                                    qDebug()<<"categoryname : "<<name<<endl;
            //                                }
            //                            }
            //                        }
            //                    }
            //                }
            //            }
            QString product = "products";
            if(obj.contains(product))
            {
                qDebug()<<"2"<<endl;
                QJsonValue pro = obj.take(product);
                if(pro.isArray())
                {
                    QJsonArray str = pro.toArray();
                    int size = str.size();
                    QJsonValue categoryid ;

                    for(int i = 0;i < size;i++)
                    {
                        QJsonValue value = str.at(i);
                        if(value.isObject())
                        {
                            QJsonObject obj2 = value.toObject();
                            if(obj2.contains("productid"))
                            {
                                QJsonValue category = obj2.take("productid");
                                if(category.isDouble())
                                {
                                    int cate = category.toInt();
                                    qDebug()<<"productid : "<<cate<<endl;
                                }
                            }

                            if(obj2.contains("releaseid"))
                            {
                                QJsonValue categoryname = obj2.take("releaseid");
                                if(categoryname.isDouble())
                                {
                                    int cate = categoryname.toInt();
                                    qDebug()<<"releaseid : "<<cate<<endl;
                                }
                            }

                            if(obj2.contains("categoryid"))
                            {
                                categoryid = obj2.take("categoryid");
                                if(categoryid.isDouble())
                                {
                                    int cate = categoryid.toInt();
                                    qDebug()<<"categoryid : "<<cate<<endl;
                                }
                            }

                            if(obj2.contains("productname"))
                            {
                                QJsonValue proname = obj2.take("productname");
                                if(proname.isString())
                                {
                                    QString name = proname.toString();
                                    qDebug()<<"productname : "<<name<<endl;
                                    //设置软件名
                                    if(categoryid == (element->category+5))
                                    {
                                        if(flag >= 15)
                                            break;
                                        element[flag].setBtnName(name);
                                        flag++;
                                    }

                                }
                            }

                            if(obj2.contains("vendorname"))
                            {
                                QJsonValue categoryname = obj2.take("vendorname");
                                if(categoryname.isString())
                                {
                                    QString name = categoryname.toString();
                                    qDebug()<<"vendorname : "<<name<<endl;
                                }
                            }

                            if(obj2.contains("iconurl"))
                            {
                                QJsonValue categoryname = obj2.take("iconurl");
                                if(categoryname.isString())
                                {
                                    QString name = categoryname.toString();
                                    qDebug()<<"iconurl : "<<name<<endl;
                                }
                            }

                            if(obj2.contains("url"))
                            {
                                QJsonValue categoryname = obj2.take("url");
                                if(categoryname.isString())
                                {
                                    QString name = categoryname.toString();
                                    qDebug()<<"url : "<<name<<endl;
                                }
                            }

                            if(obj2.contains("productdescription"))
                            {
                                QJsonValue categoryname = obj2.take("productdescription");
                                if(categoryname.isString())
                                {
                                    QString name = categoryname.toString();
                                    qDebug()<<"productdescription : "<<name<<endl;
                                }
                            }

                            if(obj2.contains("productgrade"))
                            {
                                QJsonValue category = obj2.take("productgrade");
                                if(category.isDouble())
                                {
                                    int cate = category.toInt();
                                    qDebug()<<"productgrade : "<<cate<<endl;
                                }
                            }

                            if(obj2.contains("gradecount"))
                            {
                                QJsonValue category = obj2.take("gradecount");
                                if(category.isDouble())
                                {
                                    int cate = category.toInt();
                                    qDebug()<<"gradecount : "<<cate<<endl;
                                }
                            }

                        }
                    }
                }
            }
        }
    }
}

void SoftThread::sta()
{
    qDebug()<<"sta sta sta"<<endl;
}
