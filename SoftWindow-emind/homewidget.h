#ifndef HOMEWIDGET_H
#define HOMEWIDGET_H

#include <QObject>
#include <qglobal.h>
#include <QWidget>

class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QLabel;
class QFrame;
class QQuickWidget;
class QQmlEngine;
class QScrollArea;
class RecommendWidget;
class ShareData;

class HomeWidget : public QWidget
{
    Q_OBJECT
public:
    HomeWidget(QWidget *parent,ShareData *data);
    ~HomeWidget();

signals:
    void toDetailPage(int);

public slots:
    void refreshPage(int);

private:
    QHBoxLayout *hlyPicture;
    QVBoxLayout *vly;
    QLabel *lbHots;
    QFrame *line1;
    QFrame *line2;
    QHBoxLayout *hly1;
    QQuickWidget *imgBox;
    QQmlEngine *qmlEngine;
    QScrollArea *scrollArea;
    RecommendWidget *recommWidget;
};

#endif // HOMEWIDGET_H
