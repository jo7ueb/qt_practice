#ifndef TIMERTESTWINDOW_H
#define TIMERTESTWINDOW_H

#include <QMainWindow>

namespace Ui {
class TimerTestWindow;
}

class TimerTestWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit TimerTestWindow(QWidget *parent = 0);
    ~TimerTestWindow();

public slots:
    void updateWorkerID(const int id);
    void updateWorkerMsg(const QString msg);

signals:
    void startPushed();
    void stopPushed();
    
private slots:
    void on_button_startworker_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::TimerTestWindow *ui;
};

#endif // TIMERTESTWINDOW_H
