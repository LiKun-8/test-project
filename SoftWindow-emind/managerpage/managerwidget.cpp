 #include "managerwidget.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <Details>

ManagerWidget::ManagerWidget(QWidget *parent, QString urlstr, QString namestr, QString verstr, QString sizestr) : QWidget(parent),appName(namestr),headUrl(urlstr),appVersion(verstr)

{    
    hbLayout = new QHBoxLayout();
    hbLayout->setMargin(0);
    vbLayout = new QVBoxLayout();
    vbLayout->setMargin(0);

    headButton = new QPushButton();
    headButton->setFlat(true);
    getImage(urlstr);

    nameButton = new QPushButton();
    nameButton->setFlat(true);
    nameButton->setMaximumWidth(120);
    nameButton->setStyleSheet("text-align: left;");
    nameButton->setText(namestr);

    verLabel = new QLabel();
    verLabel->setText(verstr);

    sizeLabel = new QLabel();
    sizeLabel->setText(sizestr);

    uninsButton = new QPushButton();
    uninsButton->setText(tr("Uninstall"));
    uninsButton->setFixedSize(80,32);

    managerButton = new QPushButton();
    managerButton->setText(tr("Open"));
    managerButton->setFixedSize(80,32);

    hbLayout->addWidget(headButton);
    hbLayout->addSpacing(5);
    hbLayout->addLayout(vbLayout);
    hbLayout->addStretch();
    hbLayout->addWidget(uninsButton);
    hbLayout->addWidget(managerButton);

    vbLayout->addStretch();
    vbLayout->addWidget(nameButton);
    vbLayout->addSpacing(3);
    vbLayout->addWidget(verLabel);
    vbLayout->addSpacing(0);
    vbLayout->addWidget(sizeLabel);
    vbLayout->addStretch();

    setLayout(hbLayout);
}

QPushButton * ManagerWidget::getButton(int num)
{
    switch (num)
    {
    case UNINSBUTTON:
        return uninsButton;
    case MANAGERBUTTON:
        return managerButton;
    case NAMEBUTTON:
        return nameButton;
    case HEADBUTTON:
        return headButton;
    default:
        return NULL;
    }
}

void ManagerWidget::setManagerButton(QString manastr)
{
    managerButton->setText(manastr);
}

void ManagerWidget::getImage(QString headUrl)
{
    imageManager = new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl(headUrl));
    connect(imageManager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));
    imageManager->get(request);
}

void ManagerWidget::resolveNameToId(QString packName)
{
    PackageKit::Transaction *transaction = PackageKit::Daemon::resolve(packName,
//                                                                       PackageKit::Transaction::FilterNone);
                                                                       PackageKit::Transaction::FilterArch);
    connect(transaction,
            SIGNAL(package(PackageKit::Transaction::Info,QString,QString)),
            SLOT(resetPackId(PackageKit::Transaction::Info,QString,QString)));

}

void ManagerWidget::removePackage(QString pacId)
{
    PackageKit::Transaction *uninstallTransaction = PackageKit::Daemon::removePackage(pacId);
        connect(uninstallTransaction,
                SIGNAL(finished(PackageKit::Transaction::Exit, uint)),
                SLOT(removeFinished(PackageKit::Transaction::Exit, uint)));
}

void ManagerWidget::setInstallSize(QString pacId)
{
    detailTransaction = PackageKit::Daemon::getDetails(pacId);
    connect(detailTransaction,
            SIGNAL(details(const PackageKit::Details &)),
            this,
            SLOT(onGetDetails(const PackageKit::Details &)));
}

void ManagerWidget::onGetDetails(const PackageKit::Details &value)
{
    double size = (double)value.size();
    QString insSize = transPackSize(size);
    QString sizeStr = "Size : " + insSize;
    sizeLabel->setText(sizeStr);
}

void ManagerWidget::onInstallSuccess()
{
    emit appInstallSuccess(appName);
}

void ManagerWidget::onInstallFailure()
{
    emit appInstallFailure(appName);
}

QString ManagerWidget::transPackSize(const double &size)
{
    double packSize = size;
    static QStringList measures;
    if (measures.isEmpty())
        measures << QCoreApplication::translate("QInstaller", "B")
                 << QCoreApplication::translate("QInstaller", "K")
                 << QCoreApplication::translate("QInstaller", "M")
                 << QCoreApplication::translate("QInstaller", "G")
                 << QCoreApplication::translate("QInstaller", "T");
    QStringListIterator it(measures);
    QString measure(it.next());
    while (packSize >= 1024.0 && it.hasNext()) {
        measure = it.next();
        packSize /= 1024.0;
    }
    return QString::fromLatin1("%1%2").arg(packSize, 0, 'f', 1).arg(measure);
}

void ManagerWidget::removeFinished(PackageKit::Transaction::Exit status, uint runtime)
{
  qDebug() << "packageFinished() status: " << status << endl;
  qDebug() << "packageFinished() on of seconds: " << runtime << endl;
  if (status == PackageKit::Transaction::Exit::ExitSuccess)
  {
    qDebug() << "Package remove" << pkgId <<  "success! ^_^";
    emit pacRmvSuccess(pkgId);
  }
  else
  {
      qDebug() << "Package remove Failure! ~_~";
  }
}

void ManagerWidget::resetPackId(PackageKit::Transaction::Info, QString packageID, QString summar)
{
    qDebug() << "The new package is: " << packageID << summar;
    pkgId = packageID;
    emit resetPackageIdSuccess(packageID);
}

void ManagerWidget::replyFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(bytes);
        headButton->setIcon(pixmap);
        headButton->setIconSize(QSize(64,64));

    }
}

QLabel *ManagerWidget::getLabel()
{
    return sizeLabel;
}

QString ManagerWidget::getPkgId()
{
    return pkgId;
}

void ManagerWidget::setPkgId(QString packId)
{
    pkgId = packId;
}

QString ManagerWidget::getAppName()
{
    return appName;
}

QString ManagerWidget::getHeadUrl()
{
    return headUrl;
}

QString ManagerWidget::getVersion()
{
    return appVersion;
}

void ManagerWidget::setFlag(int flag)
{
    insUpFlag = flag;
}

int ManagerWidget::getFlag()
{
    return insUpFlag;
}

void ManagerWidget::setReleaseId(int relid)
{
    releaseId = relid;
}

int ManagerWidget::getReleaseId()
{
    return releaseId;
}

void ManagerWidget::setExeFile(QString exefile)
{
    exeFile = exefile;
}

QString ManagerWidget::getExeFile()
{
    return exeFile;
}



