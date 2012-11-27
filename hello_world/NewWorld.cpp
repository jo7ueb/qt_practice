#include "NewWorld.h"
#include "ui_NewWorld.h"
#include "AboutDialog.h"
#include "ui_AboutDialog.h"

NewWorld::NewWorld(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewWorld)
{
    ui->setupUi(this);
}

NewWorld::~NewWorld()
{
    delete ui;
}

void NewWorld::on_button_dialog_clicked()
{
    AboutDialog *dg = new AboutDialog();
    dg->exec();
    delete dg;
}
