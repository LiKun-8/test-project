#ifndef CLASSWIDGETH
#define CLASSWIDGETH
#include <QMainWindow>
#include <QLayoutItem>
#include <QLabel>
#include <QVector>
#include <QDebug>
#include "element.h"
#include "classtop.h"
#include "classwidget.h"
#include "jsonfunc.h"

#define MARGIN 32;
#define SPACING 192;

class ClassWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClassWidget(QWidget *parent = 0);
    ~ClassWidget();
    QWidget *widget;
    void setCategory(int cate);//设置分类标志
    void setTopName(const CATEGORYMAP &cateMap);//设置分类项的名字
    void setElementName(const CLASSSTRUCTMAP &classStructMap);//设置软件的名字
    void initElement(const ELEMENTNUMBERMAP &classElementNumMap);//初始化软件对象
    void setElementImage(const CLASSSTRUCTMAP &classStructMap);

private:
    //每一个软件项`
    Element *tt;
    //每个分类项的顶部
    ClassTop *classtop;
    //软件项布局
    QGridLayout *gridLayout;
    //软件项的列表
    QVector<QWidget *> demoElement;
    //主布局
    QVBoxLayout *mainLayout;
    //弹簧布局
    QSpacerItem *spacer;
    //分类的标志
    int category;
    //空白widget
    QWidget *spaceWidget;
    int spaceWidgetNum;

protected:
    //重写的窗口变化事件
    bool eventFilter(QObject *target, QEvent *event);

signals:
    void moreShow(int);

protected slots:
    void sendMoreShow(int i);
};

#endif // CLASSWIDGETH
