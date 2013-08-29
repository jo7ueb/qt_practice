#include "TimerTestWindow.h"
#include "TimerModule.h"
#include <QApplication>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TimerTestWindow w;
    TimerModule m;

    //QThread t;
    //m.moveToThread(&t);
    //t.start();

    QObject::connect(&w, SIGNAL(startPushed()), &m, SLOT(start()));
    QObject::connect(&w, SIGNAL(stopPushed()), &m, SLOT(stop()));
    QObject::connect(&m, SIGNAL(notifyMessage(QString)), &w, SLOT(updateWorkerMsg(QString)));
    QObject::connect(&m, SIGNAL(notifyThreadID(int)), &w, SLOT(updateWorkerID(int)));

    w.show();
    
    return a.exec();
}
