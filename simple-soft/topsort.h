#ifndef TOPSORT_H
#define TOPSORT_H
#include <QPushButton>
#include <QLabel>
#include <QSpacerItem>
#include <QHBoxLayout>
#include <QWidget>

class Top_Sort
{
public:
    Top_Sort();
    ~Top_Sort();
    QWidget *widget;
    void set_Btn_Data();
    void set_Label_Data();
private:
    QPushButton *btn_Top;
    QLabel *label_Top;
    QLabel *line_Top;
    QSpacerItem *spacer_Top;
    QHBoxLayout *hb_Top_Layout;
    QVBoxLayout *vb_Top_Layout;
};

#endif // TOPSORT_H

