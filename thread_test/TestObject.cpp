#include "TestObject.h"
#include <unistd.h>
#include <QThread>
#include <iostream>

TestObject::TestObject(QObject *parent) :
    QObject(parent)
{
    count_dat = 0;
    cont_flag = true;
}

void TestObject::loop()
{
    // This code doesn't help!
    // QThread::yieldCurrentThread();

    while(cont_flag)
    {
        emit updateMessage(QString::number(count_dat++));
        sleep(1);
    }
}

void TestObject::resetCount()
{
    count_dat = 0;
    emit updateMessage(QString::number(count_dat));
}

void TestObject::stop()
{
    cont_flag = false;
}
