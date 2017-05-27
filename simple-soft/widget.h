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

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    Element *tt;
    Top_Sort *topsort;
    QGridLayout *main_Layout;
    QVector<QWidget *> demo_Element;

    QVBoxLayout *vb_Layout;
    QSpacerItem *spacer;
protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // WIDGET_H
