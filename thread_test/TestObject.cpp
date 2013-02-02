#include "TestObject.h"
#include <unistd.h>

TestObject::TestObject(QObject *parent) :
    QObject(parent)
{
}

void TestObject::loop()
{
    while(1)
    {
        int i=0;
        sleep(1);
        emit updateMessage(QString::number(i++));
    }
}
