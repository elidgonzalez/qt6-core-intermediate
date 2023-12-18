/*
    What
    QObjects can not be copied

    Why
    The memory address is the objects identity

    How
    Simple functions

*/
#include <QCoreApplication>
#include <QDebug>

void testPointer(QObject *obj)
{
    qInfo() << obj;
}

void testAddress(QObject &obj)
{
    qInfo() << &obj;
}

// Not allowed
// void testCopy(QObject obj)
// {
//     qInfo() << &obj;
// }

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject person;
    person.setObjectName("Eli");
    testPointer(&person);
    testAddress(person);
    // testCopy(person); // Not allowed
    return a.exec();
}
