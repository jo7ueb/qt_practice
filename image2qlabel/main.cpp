#include <QtGui/QApplication>
#include <QTextCodec>
#include "MainWindowu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // utf-8な文字列をQStringが受け付けるようにする。
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
    // utf-8な文字列をtr()が受け付けるようにする。
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));

    MainWindowu w;
    w.show();
    
    return a.exec();
}
