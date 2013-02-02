#include <QtGui/QApplication>
#include <QThread>
#include <QtCore>
#include "MainWindow.h"
#include "TestObject.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    TestObject objA, objB;

    QObject::connect(&objA, SIGNAL(updateMessage(QString)), &w, SLOT(message_A(QString)));
    QObject::connect(&objB, SIGNAL(updateMessage(QString)), &w, SLOT(message_B(QString)));

    w.show();

    // connect signals
    QThread threadA, threadB;
    objA.moveToThread(&threadA);
    objB.moveToThread(&threadB);
    threadA.start();
    threadB.start();

    if(!QMetaObject::invokeMethod(&objA, "loop"))
        w.update_status("Failed to invoke objA.loop()");

    a.exec();

    threadA.quit();
    threadB.quit();

}
