#include "softthread.h"
#include <QDebug>

SoftThread::SoftThread()
{
    flag = 0;
    this->connect(this,SIGNAL(started()),this,SLOT(sta()));
}

void SoftThread::set_Element(Element *e)
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
//    this->connect(process,SIGNAL(readyRead()),this,SLOT(read_process()));
    process->start("curl",arg);
}

void SoftThread::read_process()
{
    element[0].set_BtnName("xxxxx");
    QByteArray xx = process->readAll();
    qDebug()<<"jsonobject : "<<xx<<endl;
    QJsonParseError json_error;
    QJsonDocument document = QJsonDocument::fromJson(xx,&json_error);

    if(json_error.error == QJsonParseError::NoError)
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
            //                            if(obj2.contains("category_id"))
            //                            {
            //                                QJsonValue category = obj2.take("category_id");
            //                                if(category.isDouble())
            //                                {
            //                                    int cate = category.toInt();
            //                                    qDebug()<<"Category : "<<cate<<endl;
            //                                }
            //                            }

            //                            if(obj2.contains("category_name"))
            //                            {
            //                                QJsonValue category_name = obj2.take("category_name");
            //                                if(category_name.isString())
            //                                {
            //                                    QString name = category_name.toString();
            //                                    qDebug()<<"category_name : "<<name<<endl;
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
                    QJsonValue category_id ;

                    for(int i = 0;i < size;i++)
                    {
                        QJsonValue value = str.at(i);
                        if(value.isObject())
                        {
                            QJsonObject obj2 = value.toObject();
                            if(obj2.contains("product_id"))
                            {
                                QJsonValue category = obj2.take("product_id");
                                if(category.isDouble())
                                {
                                    int cate = category.toInt();
                                    qDebug()<<"product_id : "<<cate<<endl;
                                }
                            }

                            if(obj2.contains("release_id"))
                            {
                                QJsonValue category_name = obj2.take("release_id");
                                if(category_name.isDouble())
                                {
                                    int cate = category_name.toInt();
                                    qDebug()<<"release_id : "<<cate<<endl;
                                }
                            }

                            if(obj2.contains("category_id"))
                            {
                                category_id = obj2.take("category_id");
                                if(category_id.isDouble())
                                {
                                    int cate = category_id.toInt();
                                    qDebug()<<"category_id : "<<cate<<endl;
                                }
                            }

                            if(obj2.contains("product_name"))
                            {
                                QJsonValue pro_name = obj2.take("product_name");
                                if(pro_name.isString())
                                {
                                    QString name = pro_name.toString();
                                    qDebug()<<"product_name : "<<name<<endl;
                                    //设置软件名
                                    if(category_id == (element->category+5))
                                    {
                                        if(flag >= 15)
                                            break;
                                        element[flag].set_BtnName(name);
                                        flag++;
                                    }

                                }
                            }

                            if(obj2.contains("vendor_name"))
                            {
                                QJsonValue category_name = obj2.take("vendor_name");
                                if(category_name.isString())
                                {
                                    QString name = category_name.toString();
                                    qDebug()<<"vendor_name : "<<name<<endl;
                                }
                            }

                            if(obj2.contains("icon_url"))
                            {
                                QJsonValue category_name = obj2.take("icon_url");
                                if(category_name.isString())
                                {
                                    QString name = category_name.toString();
                                    qDebug()<<"icon_url : "<<name<<endl;
                                }
                            }

                            if(obj2.contains("url"))
                            {
                                QJsonValue category_name = obj2.take("url");
                                if(category_name.isString())
                                {
                                    QString name = category_name.toString();
                                    qDebug()<<"url : "<<name<<endl;
                                }
                            }

                            if(obj2.contains("product_description"))
                            {
                                QJsonValue category_name = obj2.take("product_description");
                                if(category_name.isString())
                                {
                                    QString name = category_name.toString();
                                    qDebug()<<"product_description : "<<name<<endl;
                                }
                            }

                            if(obj2.contains("product_grade"))
                            {
                                QJsonValue category = obj2.take("product_grade");
                                if(category.isDouble())
                                {
                                    int cate = category.toInt();
                                    qDebug()<<"product_grade : "<<cate<<endl;
                                }
                            }

                            if(obj2.contains("grade_count"))
                            {
                                QJsonValue category = obj2.take("grade_count");
                                if(category.isDouble())
                                {
                                    int cate = category.toInt();
                                    qDebug()<<"grade_count : "<<cate<<endl;
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
