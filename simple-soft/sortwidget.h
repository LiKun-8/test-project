#ifndef WIDGET_H
#define WIDGET_H
#include <QMainWindow>
#include "element.h"
#include "topsort.h"
#include <QLabel>
#define MARGIN 32;
#define SPACING 192;

namespace Ui {
class Widget;
}

class SortWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SortWidget(QWidget *parent = 0);
    ~SortWidget();
    QWidget *widget;

private:
    //每一个软件项
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
protected:
    //重写的窗口变化事件
    void resizeEvent(QResizeEvent *event);
};

#endif // WIDGET_H
