#ifndef NEWWORLD_H
#define NEWWORLD_H

#include <QMainWindow>

namespace Ui {
class NewWorld;
}

class NewWorld : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit NewWorld(QWidget *parent = 0);
    ~NewWorld();
    
private:
    Ui::NewWorld *ui;
};

#endif // NEWWORLD_H
