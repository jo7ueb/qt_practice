#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->button->setText("Test text");

    // prepare picture
    QImage image(400, 300, QImage::Format_RGB32);
    image.fill(QColor::fromRgb(255, 255, 255));

    // paint text
    QPainter painter(&image);
    painter.drawText(0, 0, "Text drawing test");

    // show label
    QPixmap pmap = QPixmap::fromImage(image);
    ui->label->setPixmap(pmap);
}

MainWindow::~MainWindow()
{
    delete ui;
}
