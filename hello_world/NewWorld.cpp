#include "NewWorld.h"
#include "ui_NewWorld.h"

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
