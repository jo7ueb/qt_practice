#include<QThread>
#include "TimerTestWindow.h"
#include "ui_TimerTestWindow.h"

TimerTestWindow::TimerTestWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TimerTestWindow)
{
    ui->setupUi(this);
    ui->text_mainid->setText(QString::number( (int)QThread::currentThreadId()) );
    ui->text_workerid->setText("Worker not ready.");
}

TimerTestWindow::~TimerTestWindow()
{
    delete ui;
}

void TimerTestWindow::updateWorkerID(const Qt::HANDLE id)
{
    ui->text_workerid->setText(QString::number( (int)id ));
}

void TimerTestWindow::updateWorkerMsg(const QString msg)
{
    ui->text_workermsg->setText(msg);
}

void TimerTestWindow::on_button_startworker_clicked()
{
    emit startPushed();
}

void TimerTestWindow::on_pushButton_2_clicked()
{
    emit stopPushed();
}
