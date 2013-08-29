#include "TimerModule.h"
#include <QTime>

static const int TIMER_MSEC = 500;
static int serial = 0;

TimerModule::TimerModule(QObject *parent) :
    QObject(parent)
{
    m_timer = new QTimer();
    m_thread = new QThread();

    this->moveToThread(m_thread);
    m_timer->moveToThread(m_thread);
    m_thread->start();

    connect(m_timer, SIGNAL(timeout()), SLOT(worker()));

    m_time = new QTime;
    m_time->start();
}

TimerModule::~TimerModule()
{
    m_thread->terminate();
    m_thread->wait();

    delete m_timer;
    delete m_thread;
    delete m_time;
}

void TimerModule::start()
{
    m_timer->start(TIMER_MSEC);
    serial = 0;
    emit notifyMessage("Timer  started.");
}

void TimerModule::stop()
{
    m_timer->stop();
    emit notifyMessage("Timer stopped.");
}

void TimerModule::worker()
{
    int diff_msec;
    QTime currentTime;

    currentTime = QTime::currentTime();
    diff_msec = m_time->elapsed();
    QString timestr = currentTime.toString("HH:mm:ss.zzz diff: ");

    emit notifyMessage(timestr + QString::number(diff_msec) + " " + QString::number(serial++));
    emit notifyThreadID((int)QThread::currentThreadId());

    m_time->restart();

    /* it blocks execution of worker but not interrupt
     * GUI when this module is runnning on another thread.
     */
    //for(;;);
}
