#include "MainWindowu.h"

MainWindowu::MainWindowu(QWidget *parent) :
    QMainWindow(parent), state(false)
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
        ui.button->setText(QString("将軍様は滅びぬ．何度でも甦るさ！！"));
        state = false;
    }

    else
    {
        ui.jongil->setVisible(true);
        ui.button->setText(QString("スカッドさわやか"));
        state = true;
    }
}
