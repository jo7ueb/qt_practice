#include "MainWindowu.h"

MainWindowu::MainWindowu(QWidget *parent) :
    QMainWindow(parent)
{
    ui.setupUi(this);
    this->toggleJongIl();
    QObject::connect(ui.button, SIGNAL(clicked(bool)), this, SLOT(toggleJongIl()));
}

void MainWindowu::toggleJongIl()
{
    if(state)
    {
        ui.jongil->setVisible(false);
        ui.button->setText(QString("将軍様万歳！"));
        state = false;
    }

    else
    {
        ui.jongil->setVisible(true);
        ui.button->setText(QString("将軍様をポア"));
        state = true;
    }
}
