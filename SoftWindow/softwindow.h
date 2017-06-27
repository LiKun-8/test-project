#ifndef SOFTWINDOWH
#define SOFTWINDOWH

#include <QMainWindow>
#include <QStackedWidget>
#include <QLineEdit>
#include <QScrollArea>
#include "simple-soft/classwidget.h"
#include "simple-soft/showmore.h"

#define HOMEPAGE 0
#define CLASSPAGE 1
#define UPDATEPAGE 2
#define MANAGERPAGE 3
#define MOREPAGE 4

class SoftWindow : public QWidget
{
    Q_OBJECT

public:
    SoftWindow(QWidget *parent = 0);
    ~SoftWindow();
    void SetCurrentPage(int page);
    void InitMainWindow();

    ShareData *shareDaba;

protected slots:
    void OnBtnHome();
    void OnBtnClass();
    void OnBtnUpdate();
    void OnBtnManager();
    void SetMoreShow(int i);
    void SetClassElementName();

    void CreateClassWindow(int catenum);
    void CreateMorewindow();

private:

    int historyPage;
    int nowPage;
    int cateNum;
    QPushButton *btnReturn;
    QPushButton *btnNext;
    QPushButton *btnRefresh;
    QPushButton *btnHome;
    QPushButton *btnSort;
    QPushButton *btnUpdate;
    QPushButton *btnManager;

    QStackedWidget *stwwindow;
    ClassWidget *classWidget;//分类对象

    QLabel *label1;
    QLabel *label3;
    QLabel *label4;

    QLineEdit *lineSearch;
    QScrollArea  *scrollClass;
    QScrollArea  *scrollMore;
    QGridLayout *mainLayout;
    QVBoxLayout *vbLayout;
    QHBoxLayout *hbLayout;
    QVBoxLayout *vbClasslayout;
    QVBoxLayout *vbClasslayoutMore;

    QSpacerItem *leftSpace;
    QSpacerItem *rightSpace;

    QWidget *pageHome;
    QWidget *pageClass;
    QWidget *pageUpdate;
    QWidget *pageManager;
    QWidget *pageClassWidget;
    QWidget *pageMoreWidget;
    QWidget *pageMore;
    QSpacerItem *pageClassSpacer;
    QSpacerItem *pageMoreSpacer;

    JSONFUNC *jsonFunc;//数据读取
    ShowMore *moreClassWidget;

//    void CreateClassWindow();
//    void CreateMorewindow();
    bool event(QEvent *event);
};

#endif // SOFTWINDOWH
