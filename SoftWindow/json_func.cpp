#include "json_func.h"
#include <QDebug>
extern QMap<int,QString> cate_Map;
extern QMap<int,SORTSTRUCT> sort_Str_Map;
extern QMap<int,int> sort_Element_Num;

JSON_FUNC::JSON_FUNC()
{
    process = new QProcess;
    json_Flag = 0;
    category_Num = 0;
    connect(process,SIGNAL(readyRead()),this,SLOT(read_process()));
    connect(process,SIGNAL(readyReadStandardOutput()),this,SLOT(read_process()));
}

int JSON_FUNC::get_Category_Num()
{
    json_Flag = CATEGORIES;
    if(process->isOpen())
    {
        process->kill();
    }
    QStringList arg;
    arg.clear();
    process->kill();
    arg<<"http://127.0.0.1:8888/categories"<< "|"<< "jq"<< ".";
    process->start("curl",arg);
    //    process->waitForReadyRead(3);
    process->waitForFinished();
    return category_Num;
}

void JSON_FUNC::set_App_name()
{
//    qDebug()<<__FUNCTION__<<endl;
    json_Flag = PRODUCTS;
    QStringList arg;
    //    arg.clear();
    //    process->kill();
    arg<<"http://127.0.0.1:8888/products"<< "|"<< "jq"<< ".";
    process->start("curl",arg);
    //    process->execute("curl",arg);
    //    process->waitForFinished();
}


void JSON_FUNC::read_process()
{
//    qDebug()<<__FUNCTION__<<endl;
    QByteArray xx ;
    xx += process->readAll();
    //    qDebug()<<"xxxxxxxxxxxxxxxxx   ==== "<<xx<<endl;

    //    qDebug()<<"jsonobject : "<<xx<<endl;
    QJsonParseError json_error;
    QJsonDocument document = QJsonDocument::fromJson(xx,&json_error);

    if(json_error.error == QJsonParseError::NoError)
    {
        if(document.isObject())
        {
            QJsonObject obj = document.object();
            if(json_Flag == CATEGORIES)
            {
//                qDebug()<<"json_Flag == "<<json_Flag<<endl;

//                qDebug()<<"1"<<endl;

                QString categor = "Categories";
                if(obj.contains(categor))
                {
                    QJsonValue test = obj.take("Categories");
                    if(test.isArray())
                    {
//                        qDebug()<<"test.type()"<<test.type()<<endl;
                        QJsonArray str = test.toArray();
                        int size = str.size();
                        category_Num = size;

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
                                        //                                        qDebug()<<"Category : "<<cate<<endl;
                                    }
                                }

                                if(obj2.contains("category_name"))
                                {
                                    QJsonValue category_name = obj2.take("category_name");
                                    if(category_name.isString())
                                    {
                                        name = category_name.toString();
                                        //                                        qDebug()<<"category_name : "<<name<<endl;
                                    }
                                }
                                cate_Map[cate] = name;
                            }
                        }
                    }
                }
            }

            if(json_Flag == PRODUCTS)
            {
//                qDebug()<<"json_Flag == "<<json_Flag<<endl;
                QString product = "products";
                if(obj.contains(product))
                {
//                    qDebug()<<"2"<<endl;
                    QJsonValue pro = obj.take(product);
                    if(pro.isArray())
                    {
                        QJsonArray str = pro.toArray();
                        int size = str.size();
                        QJsonValue category_id ;

                        int pro_id;
                        int rel_id;
                        int cate_id;
                        int pro_cate;
                        int gra_count;
                        QString pro_name;
                        QString ven_name;
                        QString ico_url;
                        QString pro_url;
                        QString pro_desc;
                        QMap<int,int>::iterator it;
                        for(int i = 0;i < size;i++)
                        {
                            //                            if(i>15)
                            //                            {
                            //                                break;
                            //                            }
                            QJsonValue value = str.at(i);

                            if(value.isObject())
                            {
                                QJsonObject obj2 = value.toObject();

                                if(obj2.contains("product_id"))
                                {
                                    QJsonValue product_id = obj2.take("product_id");
                                    if(product_id.isDouble())
                                    {
                                        pro_id = product_id.toInt();
                                        //                                        qDebug()<<"product_id : "<<pro_id<<endl;
                                    }
                                }

                                if(obj2.contains("release_id"))
                                {
                                    QJsonValue release_id = obj2.take("release_id");
                                    if(release_id.isDouble())
                                    {
                                        rel_id = release_id.toInt();
                                        //                                        qDebug()<<"release_id : "<<rel_id<<endl;
                                    }
                                }

                                if(obj2.contains("category_id"))
                                {
                                    category_id = obj2.take("category_id");
                                    if(category_id.isDouble())
                                    {
                                        cate_id = category_id.toInt();
                                        //                                        qDebug()<<"category_id : "<<cate_id<<endl;
                                        it = sort_Element_Num.find(cate_id);
                                        if(it != sort_Element_Num.end())
                                        {
                                            sort_Element_Num[cate_id] = it.value()+1;
                                        }
                                        else
                                        {
                                            sort_Element_Num.insert(cate_id,1);
                                        }
                                    }
                                }

                                if(obj2.contains("product_name"))
                                {
                                    QJsonValue product_name = obj2.take("product_name");
                                    if(product_name.isString())
                                    {
                                        pro_name = product_name.toString();
                                        //                                        qDebug()<<"product_name : "<<pro_name<<endl;
                                        //设置软件名

                                    }
                                }

                                if(obj2.contains("vendor_name"))
                                {
                                    QJsonValue vendor_name = obj2.take("vendor_name");
                                    if(vendor_name.isString())
                                    {
                                        ven_name = vendor_name.toString();
                                        //                                        qDebug()<<"vendor_name : "<<ven_name<<endl;
                                    }
                                }

                                if(obj2.contains("icon_url"))
                                {
                                    QJsonValue icon_url = obj2.take("icon_url");
                                    if(icon_url.isString())
                                    {
                                        ico_url = icon_url.toString();
                                        //                                        qDebug()<<"icon_url : "<<ico_url<<endl;
                                    }
                                }

                                if(obj2.contains("url"))
                                {
                                    QJsonValue url = obj2.take("url");
                                    if(url.isString())
                                    {
                                        pro_url = url.toString();
                                        //                                        qDebug()<<"url : "<<pro_url<<endl;
                                    }
                                }

                                if(obj2.contains("product_description"))
                                {
                                    QJsonValue product_description = obj2.take("product_description");
                                    if(product_description.isString())
                                    {
                                        pro_desc = product_description.toString();
                                        //                                        qDebug()<<"product_description : "<<pro_desc<<endl;
                                    }
                                }

                                if(obj2.contains("product_grade"))
                                {
                                    QJsonValue product_grade = obj2.take("product_grade");
                                    if(product_grade.isDouble())
                                    {
                                        pro_cate = product_grade.toInt();
                                        //                                        qDebug()<<"product_grade : "<<pro_cate<<endl;
                                    }
                                }

                                if(obj2.contains("grade_count"))
                                {
                                    QJsonValue grade_count = obj2.take("grade_count");
                                    if(grade_count.isDouble())
                                    {
                                        gra_count = grade_count.toInt();
                                        //                                        qDebug()<<"grade_count : "<<gra_count<<endl;
                                    }
                                }
                                //                                qDebug()<<"cate_id : "<<cate_id<<endl;
                                //                                qDebug()<<"ico_url : "<<ico_url<<endl;
                                //                                qDebug()<<"pro_name : "<<pro_name<<endl;
                                sort_Str_Map.insert(pro_id,SORTSTRUCT(cate_id,ico_url,pro_name,0));
                            }
                            //                            SORTSTRUCT sortstruct(cate_id,ico_url,pro_name,0);
                            //                            sort_Str_Map.insert(pro_id,sortstruct);
                        }
                    }
                }
            }
        }
        emit curl_IsOk();
    }
    else
    {
        qDebug()<<"json is error!!!!!!!"<<endl;
    }
}

