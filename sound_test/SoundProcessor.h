#ifndef SOUNDPROCESSOR_H
#define SOUNDPROCESSOR_H

#include <QObject>
#include <QtCore>
#include <QTimer>

class SoundProcessor : public QObject
{
    Q_OBJECT
public:
    explicit SoundProcessor(QObject *parent = 0);
    ~SoundProcessor();
    
signals:
    void imageUpdated(QImage *i);
    void started();
    void stopped();

public slots:
    void start();
    void stop();
    void setAudioSource(QIODevice *d);

private slots:
    void setReadable();

private:
    void processLoop();
    QImage *image;
    QIODevice *sound;
    QTimer *tm;
    volatile bool isSoundAvailable, isRunning, isReadable;
    
};

#endif // SOUNDPROCESSOR_H
