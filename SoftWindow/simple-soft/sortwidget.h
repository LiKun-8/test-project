#ifndef WIDGET_H
#define WIDGET_H
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
    void set_Category(int cate);//设置分类标志
    void set_Top_Name();//设置分类项的名字
    void set_Element_Name();//设置软件的名字
    void init_Element();//初始化软件对象

private:
    //每一个软件项`
    Element *tt;
    //每个分类项的顶部
    Top_Sort *topsort;
    //软件项布局
    QGridLayout *grid_Layout;
    //软件项的列表
    QVector<QWidget *> demo_Element;
    //主布局
    QVBoxLayout *main_Layout;
    //弹簧布局
    QSpacerItem *spacer;
    //分类线程
    SoftThread *softThread;
    //分类的标志
    int category;
    //空白widget
    QWidget *space_Widget;

    int index;
    QLayoutItem *child;
protected:
    //重写的窗口变化事件
    bool eventFilter(QObject *target, QEvent *event);

signals:
    void more_Show(int);

protected slots:
    void send_More_Show(int i);
};

#endif // WIDGET_H
