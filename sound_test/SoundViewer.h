#ifndef SOUNDVIEWER_H
#define SOUNDVIEWER_H

#include "ui_SoundViewer.h"

class SoundViewer : public QDialog
{
    Q_OBJECT
    
public:
    explicit SoundViewer(QWidget *parent = 0);
    
private:
    Ui::SoundViewer ui;

public slots:
    void updateImage(QImage *i);

signals:
    void startButton();
    void stopButton();

private slots:
    void on_startButton_clicked();
    void on_stopButton_clicked();
};

#endif // SOUNDVIEWER_H
