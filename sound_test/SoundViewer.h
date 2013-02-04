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
};

#endif // SOUNDVIEWER_H
