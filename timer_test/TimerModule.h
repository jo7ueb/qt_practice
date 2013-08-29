#ifndef TIMERMODULE_H
#define TIMERMODULE_H

#include <QObject>
#include <QTimer>
#include <QTime>
#include <QThread>

class TimerModule : public QObject
{
    Q_OBJECT
public:
    explicit TimerModule(QObject *parent = 0);
    ~TimerModule();
    
signals:
    void notifyThreadID(int id);
    void notifyMessage(QString str);
    
public slots:
    void start();
    void stop();
    
private slots:
    void worker();

private:
    QTimer *m_timer;
    QThread *m_thread;
    QTime *m_time;

};

#endif // TIMERMODULE_H
