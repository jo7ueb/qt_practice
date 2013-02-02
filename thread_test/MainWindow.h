#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    
private:
    Ui::MainWindow ui;

public slots:
    void message_A(const QString &s);
    void message_B(const QString &s);
    void update_status(const QString &s);

signals:
    void button_a_pushed();
    void button_b_pushed();

};

#endif // MAINWINDOW_H
