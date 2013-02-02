#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    ui.setupUi(this);
}

// slots
void MainWindow::message_A(const QString &s)
{
    ui.text_a->setPlainText(s);
}

void MainWindow::message_B(const QString &s)
{
    ui.text_b->setPlainText(s);
}

void MainWindow::update_status(const QString &s)
{
    ui.statusBar->showMessage(s);
}

void MainWindow::on_button_a_clicked()
{
    emit button_a_pushed();
}

void MainWindow::on_button_b_clicked()
{
    emit button_b_pushed();
}
