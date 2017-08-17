#ifndef DETAILWIDGET_H
#define DETAILWIDGET_H

#include <QObject>
#include <QWidget>
#include <qglobal.h>

class QQuickWidget;
class QLabel;
class QPushButton;
class QTextEdit;
class QHBoxLayout;
class QVBoxLayout;
class QFormLayout;
class QQmlEngine;
class QProgressBar;
class QGridLayout;
class QScrollArea;
class ShareData;
class QNetworkAccessManager;
class QNetworkReply;
class JSONFUNC;

class DetailWidget : public QWidget
{
    Q_OBJECT
public:
    DetailWidget(QWidget *parent,ShareData* shareData,JSONFUNC *jsonFunc);

    QString octetsToString( qint64 octets );

signals:

public slots:
    void refreshPage(int);
    void toPage(int);
    void replyFinished(QNetworkReply *reply);

private:
    void initialWidgets();
    void layoutWidgets();
    void getImage(QString headUrl);
    void initStar(double num);

private:
    QLabel *lbProductImg;
    QLabel *lbProductName;
    QLabel *lbComment;
    QLabel *lbCommentStar;
    QLabel *lbCommentMark;
    QLabel *lbProductVersion;
    QLabel *lbVersionNo;
    QLabel *lbProductSize;
    QLabel *lbSizeValue;
    QPushButton *btnState;
    QLabel *lbAppInfo;
    QLabel *lbAppInfoDetail;

    QLabel *lbUserComment;
    QLabel *lbUserCommMark;
    QLabel *lbUserCommStar;
    QLabel *lbTotalCommenters;
    qint32 totalCommenters;
    QLabel *lbStarLevel1;
    QLabel *lbStarLevel2;
    QLabel *lbStarLevel3;
    QLabel *lbStarLevel4;
    QLabel *lbStarLevel5;
    QProgressBar *pbStarLevel1;
    QProgressBar *pbStarLevel2;
    QProgressBar *pbStarLevel3;
    QProgressBar *pbStarLevel4;
    QProgressBar *pbStarLevel5;
    QLabel *lbLevel1Users;
    QLabel *lbLevel2Users;
    QLabel *lbLevel3Users;
    QLabel *lbLevel4Users;
    QLabel *lbLevel5Users;

    QLabel *lbmyMark;
    QLabel *lbmyStarLevel;
    QLabel *lbmyComment;
    QTextEdit *teCommContent;
    QPushButton *btnSubmit;
    QPushButton *btnCancel;

    QQuickWidget *userCommBoxer;
    QQuickWidget *imgBoxer;


    QHBoxLayout *hly1;
    QHBoxLayout *hly2;
    QHBoxLayout *hly3;
    QHBoxLayout *hly4;
    QHBoxLayout *hly5;
    QHBoxLayout *hly6;
    QHBoxLayout *hly7;
    QHBoxLayout *hly8;
    QHBoxLayout *hly9;
    QHBoxLayout *hly10;
    QHBoxLayout *hly11;
    QHBoxLayout *hly12;

    QVBoxLayout *vly1;
    QVBoxLayout *vly2;
    QVBoxLayout *vly3;
    QVBoxLayout *vly4;
    QVBoxLayout *vly5;
    QVBoxLayout *vly6;
    QVBoxLayout *vly;
    QGridLayout *gly;

    QQmlEngine *qmlEnginer;

    QString productName;
    QString productCommMark;
    QString productVersion;
    QString productSize;
    QString userCounts;

    QScrollArea *scrollArea;
    ShareData *shareData;
    JSONFUNC *jsonFunc;
    QNetworkAccessManager *imageManager;


};

#endif // DETAILWIDGET_H
