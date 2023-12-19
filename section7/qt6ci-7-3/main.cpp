/*

  What
  Creating groups

  Why
  We want the settings in logical groups

  How
  beginGroup / endGroup

 */

#include <QCoreApplication>
#include <QDebug>
#include <QSettings>

void saveAge(QSettings *settings, QString group, QString name, int age)
{
    settings->beginGroup(group);
    settings->setValue(name, age);
    settings->endGroup();
}

int getAge(QSettings *settings, QString group, QString name)
{
    settings->beginGroup(group);
    if (!settings->contains(name))
    {
        qWarning() << "Does not contain" << name << "in" << group;
        settings->endGroup();
        return 0;
    }
    bool ok;
    int value = settings->value(name).toInt(&ok);
    settings->endGroup();
    if (!ok)
    {
        qWarning() << "Could not convert to int";
        return 0;
    }
    return value;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("Eli");
    QCoreApplication::setOrganizationDomain("test.com");
    QCoreApplication::setApplicationName("Tester");

    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    saveAge(&settings,"people","Bryan",44);
    saveAge(&settings,"beer","twoheart",1);
    saveAge(&settings,"beer","Bryan",11);

    qInfo() << "TwoHeart" << getAge(&settings,"beer","twoheart");
    qInfo() << "Bryan (people)" << getAge(&settings,"people","Bryan");
    qInfo() << "Bryan (beer)" << getAge(&settings,"beer","Bryan");


    return a.exec();
}
