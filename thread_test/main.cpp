#include <QtGui/QApplication>
#include <QThread>
#include <QtConcurrentRun>
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

    // execute loop() as a new thread using QtConcurrent::run()
    QFuture<void> f1 = QtConcurrent::run(&objA, &TestObject::loop);
    QFuture<void> f2 = QtConcurrent::run(&objB, &TestObject::loop);

    a.exec();

    // stop loop() and wait for termination
    objA.stop();
    objB.stop();
    f1.waitForFinished();
    f2.waitForFinished();
}
