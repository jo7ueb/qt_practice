#ifndef TESTOBJECT_H
#define TESTOBJECT_H

#include <QObject>

class TestObject : public QObject
{
    Q_OBJECT

public:
    explicit TestObject(QObject *parent = 0);
    
signals:
    void updateMessage(QString s);

public slots:
    void loop();
    
};

#endif // TESTOBJECT_H
