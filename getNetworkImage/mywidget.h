#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QPushButton>
#include <QGridLayout>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPixmap>
#include <QPaintEvent>

class MyWidget:public QWidget
{
    Q_OBJECT

public:
    MyWidget();
    void GetImage(QString imagePath);

private:
    QPushButton *m_ImageBtn;
    QNetworkAccessManager *m_ImageManager;
    QPixmap *m_ImagePix;
    QString m_ImagePath;
    int m_Flag;

protected slots:
    void ReplyFinished(QNetworkReply *reply);
    void paintEvent(QPaintEvent *event);
};

#endif // MYWIDGET_H
