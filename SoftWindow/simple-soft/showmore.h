#ifndef SHOWMOREH
#define SHOWMOREH

#include <QWidget>
#include "classwidget.h"
#include "classtop.h"
#include "jsonfunc.h"

class ShowMore : public QWidget
{
    Q_OBJECT

public:
    explicit ShowMore(QWidget *parent = 0);
    QWidget *moreWidget;
    void SetElementName(int category,const CLASSSTRUCTMAP &classStruct);
    void SetTopName(int category,const CATEGORYMAP &cateGoryMap);
    void SetElementNum(const ELEMENTNUMBERMAP &elementNum);
    void SetElementImage(int category,const CLASSSTRUCTMAP &classStructMap);

private:
    ClassTop *moreClassTop;
    QVBoxLayout *mainLayout;
    Element *moreElement;
    QGridLayout *eleLayout;
    QWidget  *spaceWidget;
    JSONFUNC *jsonFunc;

    bool eventFilter(QObject *watched, QEvent *event);
    int categoryFlag;
    int elementNumber;
};

#endif // SHOWMOREH
