#ifndef SOFTWINDOW_H
#define SOFTWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QStackedWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QSpacerItem>
#include <QWidget>
#include <QLineEdit>
#include "simple-soft/sortwidget.h"
#include <QScrollArea>
#include "softthread.h"
#include "json_func.h"

#include <QStringList>
#include <QByteArray>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QMap>


#define HOME_PAGE 0
#define SOFT_PAGE 1
#define UPDATE_PAGE 2
#define MANAGER_PAGE 3

class SoftWindow : public QWidget
{
    Q_OBJECT

public:
    SoftWindow(QWidget *parent = 0);
    ~SoftWindow();
    void Set_Current_Page(int page);
    void init_Window();
    void create_Soft_Window();


protected slots:
    void On_Btn_Home();
    void On_Btn_Sort();
    void On_Btn_Update();
    void On_Btn_Manager();
//    void read_process();
    void set_More_Show(int i);
    void test_set_name();

private:

    int history_Page;
    int now_Page;
    int cate_num;
    QPushButton *btn_Return;
    QPushButton *btn_Next;
    QPushButton *btn_Refresh;
    QPushButton *btn_Home;
    QPushButton *btn_Sort;
    QPushButton *btn_Update;
    QPushButton *btn_Manager;

    QStackedWidget *stw_window;

    SortWidget *sortWidget;//分类对象

    QLabel *label1;
    QLabel *label3;
    QLabel *label4;

    QLineEdit *line_Search;
    QScrollArea  *scroll;
    QGridLayout *main_Layout;
    QVBoxLayout *vb_Layout;
    QHBoxLayout *hb_Layout;
    QVBoxLayout *vb_Sort_layout;

    QSpacerItem *left_Space;
    QSpacerItem *right_Space;

    QWidget *page_Home;
    QWidget *page_Sort;
    QWidget *page_Update;
    QWidget *page_Manager;
    QWidget *page_Sort_Widget;
    QSpacerItem *page_Sort_Spacer;

    SoftThread *softThread; //分类的线程
    JSON_FUNC *jsonFunc;//数据读取

//    void resizeEvent(QResizeEvent *);
//    void changeEvent(QEvent *event);
    bool event(QEvent *event);
};

#endif // SOFTWINDOW_H
