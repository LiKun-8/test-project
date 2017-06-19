#ifndef WIDGET_H
#define WIDGET_H
#include <QMainWindow>
#include "element.h"
#include "topsort.h"
#include <QLabel>
#define MARGIN 32;
#define SPACING 192;
#include "../softthread.h"


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
    void set_Category(int cate);
    void set_Top_Name();
    void set_Element_Name();

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

    SoftThread *softThread;

    int category;

protected:
    //重写的窗口变化事件
    bool eventFilter(QObject *target, QEvent *event);

signals:
    void more_Show(int);

protected slots:
    void send_More_Show(int i);
};

#endif // WIDGET_H
