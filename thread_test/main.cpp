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
    QObject::connect(&w, SIGNAL(button_a_pushed()), &objA, SLOT(resetCount()));
    QObject::connect(&w, SIGNAL(button_b_pushed()), &objB, SLOT(resetCount()));
    w.show();

    // connect signals
    QThread threadA, threadB;
    objA.moveToThread(&threadA);
    objB.moveToThread(&threadB);
    threadA.start();
    threadB.start();

    // loop() method never return, event loop will be blocked.
    // we cannot handle signals connected to TestObject!
    QMetaObject::invokeMethod(&objA, "loop");
    QMetaObject::invokeMethod(&objB, "loop");

    a.exec();

    threadA.quit();
    threadB.quit();

}
