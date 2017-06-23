#ifndef WIDGETH
#define WIDGETH
#include <QMainWindow>
#include "element.h"
#include "topsort.h"
#include <QLabel>
#define MARGIN 32;
#define SPACING 192;
#include "../softthread.h"
#include <QWidget>
#include <QLayoutItem>


class SortWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SortWidget(QWidget *parent = 0);
    ~SortWidget();
    QWidget *widget;
    void setCategory(const int& cate);//设置分类标志
    void setTopName();//设置分类项的名字
    void setElementName();//设置软件的名字
    void initElement();//初始化软件对象

private:
    //每一个软件项`
    Element *tt;
    //每个分类项的顶部
    TopSort *topsort;
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

    int index;
    QLayoutItem *child;
protected:
    //重写的窗口变化事件
    bool eventFilter(QObject *target, QEvent *event);

signals:
    void moreShow(int);

protected slots:
    void sendMoreShow(int i);
};

#endif // WIDGETH
