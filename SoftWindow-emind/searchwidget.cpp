#include "searchwidget.h"
#include <QSpacerItem>
#include <QVBoxLayout>
#include <QLabel>
#include <QFrame>
#include <QTableView>
#include "sharedata.h"
SearchWidget::SearchWidget(QWidget *parent,ShareData* data) : QWidget(parent)
{
    line = new QFrame(this);
    lbInfo = new QLabel(this);
    vly = new QVBoxLayout;
    space = new QSpacerItem(32,5,QSizePolicy::Maximum,QSizePolicy::Fixed);

    lbNoResult = new QLabel(this);
    tbvResult = new QTableView(this);

    vly->addItem(space);
    vly->addWidget(lbInfo);
    vly->addWidget(line);
    vly->addWidget(lbNoResult);
    vly->addWidget(tbvResult);
    setLayout(vly);

    shareData = data;
}

void SearchWidget::doSearch(QString keyText)
{

    for( auto item = shareData->classStrMap.begin(); item.value().proName.contains(keyText); item++)
    {

    }

//    lbInfo->setText(tr("Applications Contains %1").arg(key));
}

void SearchWidget::refreshPage(int)
{

}
