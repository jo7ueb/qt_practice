#ifndef INTERFACE_H
#define INTERFACE_H

#include "ui_Interface.h"

class Interface : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Interface(QWidget *parent = 0);
    
private:
    Ui::Interface ui;
};

#endif // INTERFACE_H
