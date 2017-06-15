#ifndef TOPSORT_H
#define TOPSORT_H
#include <QPushButton>
#include <QLabel>
#include <QSpacerItem>
#include <QHBoxLayout>
#include <QWidget>
#include <QObject>

class Top_Sort:public QObject
{
    Q_OBJECT

public:
    Top_Sort();
    ~Top_Sort();
    //布局窗口
    QWidget *widget;
    //设置更多按钮文本
    void set_Btn_Data();
    //设置软件项名称
    void set_Label_Data();
    int category;
    void set_category(int cate);

private:
    //更多按钮
    QPushButton *btn_Top;
    //软件项名称
    QLabel *label_Top;
    //横线
    QLabel *line_Top;
    //弹簧布局
    QSpacerItem *spacer_Top;
    //布局
    QHBoxLayout *hb_Top_Layout;
    QVBoxLayout *vb_Top_Layout;

signals:
    void show_All(int i);

protected slots:
    void send_Slot_Btn();
};

#endif // TOPSORT_H

