#include "TimerTestWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TimerTestWindow w;
    w.show();
    
    return a.exec();
}
