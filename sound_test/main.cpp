#include <QtGui/QApplication>
#include <QtMultimedia/QtMultimedia>
#include "SoundViewer.h"
#include "SoundProcessor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SoundViewer w;
    SoundProcessor p;

    QAudioFormat f;
    f.setSampleRate(18000);
    f.setSampleType(QAudioFormat::Float);
    f.setChannelCount(1);

    QAudioInput *audio = new QAudioInput(f);
    QIODevice *dev = audio->start();
    p.setAudioSource(dev);

    QObject::connect(&w, SIGNAL(startButton()), &p, SLOT(start()));
    QObject::connect(&w, SIGNAL(stopButton()), &p, SLOT(stop()));
    QObject::connect(&p, SIGNAL(imageUpdated(QImage*)), &w, SLOT(updateImage(QImage*)));

    w.show();
    
    delete audio;
    return a.exec();
}
