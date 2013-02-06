#include "SoundViewer.h"

SoundViewer::SoundViewer(QWidget *parent) :
    QDialog(parent)
{
    ui.setupUi(this);
}

void SoundViewer::updateImage(QImage *i)
{
    ui.label->setPixmap(QPixmap::fromImage(*i));
    ui.label->show();
}

void SoundViewer::on_startButton_clicked()
{
    emit startButton();
}

void SoundViewer::on_stopButton_clicked()
{
    emit stopButton();

}
