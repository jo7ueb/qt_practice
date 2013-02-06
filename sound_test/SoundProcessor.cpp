#include "SoundProcessor.h"
#include <QtCore>
#include <QtGui>
#include <QtConcurrentRun>
#include <iostream>

SoundProcessor::SoundProcessor(QObject *parent) :
    QObject(parent), isSoundAvailable(false),
    isRunning(false), isReadable(false)
{
    image = new QImage(600, 300, QImage::Format_RGB32);
    image->fill(Qt::black);
    emit imageUpdated(image);

    tm = new QTimer();
    tm->start(33);
    QObject::connect(tm, SIGNAL(timeout()), this, SLOT(setReadable()));

}

void SoundProcessor::setReadable(){
    if(isRunning)
        isReadable = true;
}

SoundProcessor::~SoundProcessor()
{
    delete image;
}

void SoundProcessor::start()
{
    isRunning = true;
    emit imageUpdated(image);
    QtConcurrent::run(this, &SoundProcessor::processLoop);
}

void SoundProcessor::stop()
{
    isRunning = false;
}

void SoundProcessor::setAudioSource(QIODevice *d)
{
    if(d != NULL){
        sound = d;
        sound->open(QIODevice::ReadOnly);
        isSoundAvailable = true;
    } else {
        sound = NULL;
        isSoundAvailable = false;
    }
}

void SoundProcessor::processLoop()
{
    std::cout <<"processLoop() started"<<std::endl;
    float soundData[600];
    while(isRunning){
        if(isReadable){
            sound->read((char *)soundData, 600*sizeof(float));

            image->fill(Qt::black);
            for(int i=0; i<600; ++i){
                int pos = 150*soundData[i] + 150;
                image->setPixel(i, 150, qRgb(200, 200, 200));
                image->setPixel(i, pos, qRgb(0, 255, 0));
            }

            emit imageUpdated(image);
            isReadable = false;
        }
    }
    std::cout << "processLoop() terminated"<<std::endl;
}
