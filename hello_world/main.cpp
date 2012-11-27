#include <QApplication>
#include "NewWorld.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NewWorld w;
    w.show();
    
    return a.exec();
}
