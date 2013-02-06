#include "SoundProcessor.h"
#include <QtCore>
#include <QtGui>

SoundProcessor::SoundProcessor(QObject *parent) :
    QObject(parent), isSoundAvailable(false),
    isRunning(false), isReadable(false)
{
    image = new QImage(600, 300, QImage::Format_RGB32);
    image->fill(Qt::black);

    tm = new QTimer();
    tm->setInterval(33);
    QObject::connect(tm, SIGNAL(timeout()), this, SLOT(setReadable()));
}

void SoundProcessor::setReadable(){
    isReadable = false;
}

SoundProcessor::~SoundProcessor()
{
    delete image;
}

void SoundProcessor::start()
{
    isRunning = true;
}

void SoundProcessor::stop()
{
    isRunning = false;
}

void SoundProcessor::setAudioSource(QIODevice *d)
{
    if(d != NULL){
        sound = d;
        isSoundAvailable = true;
    } else {
        sound = NULL;
        isSoundAvailable = false;
    }
}

void SoundProcessor::processLoop()
{
    float soundData[600];
    while(isRunning){
        if(isReadable){
            sound->read((char *)soundData, 600*sizeof(float));

            image->fill(Qt::black);
            for(int i=0; i<600; ++i){
                int pos = 150*soundData[i] + 150;
                image->setPixel(i, pos, Qt::green);
            }

            emit imageUpdated(image);
        }
    }
}
