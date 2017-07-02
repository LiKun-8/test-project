#ifndef SOFTWINDOWH
#define SOFTWINDOWH

#include <QMainWindow>
#include <QStackedWidget>
#include <QLineEdit>
#include "sharedata.h"
#include "simple-soft/classpage.h"

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
    void setCurrentPage(int page);
    void initMainWindow();


protected slots:
    void onBtnHome();
    void onBtnClass();
    void onBtnUpdate();
    void onBtnManager();
    void onBtnMore();

private:

    int historyPage;
    int nowPage;
    QPushButton *btnReturn;
    QPushButton *btnNext;
    QPushButton *btnRefresh;
    QPushButton *btnHome;
    QPushButton *btnSort;
    QPushButton *btnUpdate;
    QPushButton *btnManager;

    QStackedWidget *stwwindow;


    QLabel *label1;
    QLabel *label3;
    QLabel *label4;

    QLineEdit *lineSearch;

    QGridLayout *mainLayout;
    QVBoxLayout *vbLayout;
    QHBoxLayout *hbLayout;


    QSpacerItem *leftSpace;
    QSpacerItem *rightSpace;

    QWidget *pageHome;
    ClassPage *pageClass;
    QWidget *pageUpdate;
    QWidget *pageManager;

    bool event(QEvent *event);
};

#endif // SOFTWINDOWH
