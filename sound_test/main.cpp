#include <QtGui/QApplication>
#include "SoundViewer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SoundViewer w;
    w.show();
    
    return a.exec();
}
