#ifndef ELEMENTH
#define ELEMENTH
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include "custombutton.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPixmap>
#include <QPaintEvent>

class Element:public QObject
{
    Q_OBJECT

public:
    Element();
    ~Element();

    QWidget *baseWidget;
    void Init();//初始化布局
    void SetBtnImage(QString imagePath);//设置应用图标
    void SetBtnName(QString name);//设置应用名字
    void SetBtnStart();//设置应用评分
    void SetBtnStatus(QString status);//设置应用状态
    void SetButton(bool);
    int category;//应用的分类
    void Setcategory(int cate);//设置应用分类

private slots:
    void BtnStatusSlot();
    void ReplyFinished(QNetworkReply *reply);

private:
    QPushButton *btnImage;
    QPushButton *btnName;
    QPushButton *btnstar;
    CustomButton *btnStatus;//自定义的按钮
    QVBoxLayout *vbLayout;
    QHBoxLayout *hbLayout;

    QNetworkAccessManager *m_ImageManager;
    QPixmap *m_ImagePix;

protected:
//    void paintEvent(QPaintEvent *event);
    bool eventFilter(QObject *target, QEvent *event);
    int m_Flag;
    QString m_ImagePath;
};

#endif // ELEMENTH

