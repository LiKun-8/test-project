#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QObject>
#include <QWidget>
#include <qglobal.h>
class QLabel;
class QFrame;
class QVBoxLayout;
class QSpacerItem;
class QTableView;
class ShareData;

class SearchWidget : public QWidget
{
    Q_OBJECT
public:
    SearchWidget(QWidget *parent,ShareData *data);

signals:

public slots:
    void doSearch(QString key);
    void refreshPage(int);


private:
    QFrame *line;
    QLabel *lbInfo;
    QLabel *lbNoResult;
    QVBoxLayout *vly;
    QSpacerItem *space;
    QTableView *tbvResult;
    ShareData *shareData;


};

#endif // SEARCHWIDGET_H
