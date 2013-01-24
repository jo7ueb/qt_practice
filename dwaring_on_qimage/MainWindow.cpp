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
    QImage image(400, 200, QImage::Format_RGB32);
    image.fill(Qt::darkBlue);

    // paint text
    QPainter painter(&image);
    painter.setPen(Qt::white);
    painter.drawText(0, 10, "Text drawing test"); // y position is for baseline!!
    painter.fillRect(20, 20, 50, 50, Qt::yellow);

    // show label
    QPixmap pmap = QPixmap::fromImage(image);
    ui->label->setPixmap(pmap);

    // save image file
    image.save("test_image.png");
}

MainWindow::~MainWindow()
{
    delete ui;
}
