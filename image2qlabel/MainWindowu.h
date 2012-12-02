#ifndef MAINWINDOWU_H
#define MAINWINDOWU_H

#include "ui_MainWindowu.h"

class MainWindowu : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindowu(QWidget *parent = 0);

public slots:
    void toggleJongIl();

private:
    Ui::MainWindowu ui;
    bool state;


};

#endif // MAINWINDOWU_H
