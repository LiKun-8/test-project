#ifndef CLASSWIDGETH
#define CLASSWIDGETH
#include <QMainWindow>
#include "element.h"
#include "classtop.h"
#include <QLabel>
#define MARGIN 32;
#define SPACING 192;
#include "../softthread.h"
#include <QWidget>
#include <QLayoutItem>
#include "jsonfunc.h"

class ClassWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClassWidget(QWidget *parent = 0);
    ~ClassWidget();
    QWidget *widget;
    void SetCategory(int cate);//设置分类标志
    void SetTopName(const CATEGORYMAP &cateMap);//设置分类项的名字
    void SetElementName(const CLASSSTRUCTMAP &classStructMap);//设置软件的名字
    void InitElement(const ELEMENTNUMBERMAP &classElementNumMap);//初始化软件对象
    void SetElementImage(const CLASSSTRUCTMAP &classStructMap);

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
    //分类线程
    SoftThread *softThread;
    //分类的标志
    int category;
    //空白widget
    QWidget *spaceWidget;

    JSONFUNC *jsonFunc;
    int index;
    QLayoutItem *child;
protected:
    //重写的窗口变化事件
    bool eventFilter(QObject *target, QEvent *event);

signals:
    void moreShow(int);

protected slots:
    void SendMoreShow(int i);
};

#endif // CLASSWIDGETH
