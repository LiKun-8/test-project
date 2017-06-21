#ifndef SHOWMORE_H
#define SHOWMORE_H

#include <QWidget>
#include "../simple-soft/sortwidget.h"
#include "../simple-soft/topsort.h"

class ShowMore : public QWidget
{
    Q_OBJECT
public:
    explicit ShowMore(QWidget *parent = 0);
    QWidget *more_Widget;
    void set_Element_Name(int category);
    void set_Top_Name(int category);
private:
    Top_Sort *more_TopSort;
    QVBoxLayout *mainLayout;
    Element *more_Element;
    QGridLayout *ele_Layout;
    bool eventFilter(QObject *watched, QEvent *event);
    QWidget  *space_Widget;
    int category_Flag;
};

#endif // SHOWMORE_H
