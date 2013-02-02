#include "TestObject.h"
#include <unistd.h>
#include <QThread>
#include <iostream>

TestObject::TestObject(QObject *parent) :
    QObject(parent)
{
    count_dat = 0;
}

void TestObject::loop()
{
    while(1)
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
