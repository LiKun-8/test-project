#ifndef CLASSPAGE_H
#define CLASSPAGE_H

#include <QWidget>
#include "classwidget.h"
#include <QScrollArea>
#include "morepage.h"

class ClassPage : public QWidget
{
    Q_OBJECT

public:
    explicit ClassPage(QWidget *parent = 0);
    ShareData *shareDaba;
    JSONFUNC *jsonFunc;//数据读取
    QScrollArea  *scrollClass;
    MorePage *moreClassWidget;

private:
    ClassWidget *classWidget;//分类对象
    QSpacerItem *pageClassSpacer;
    QVBoxLayout *vbClasslayout;
    QWidget *pageClassWidget;
    int cateNum;


signals:
    void setMore();

public slots:
    void setClassElementName();
    void createClassWindow(int catenum);
    void setMoreShow(int i);
};

#endif // CLASSPAGE_H