#include <QCoreApplication>
#include <QList>
#include <QtMultimedia>
#include <iostream>
#include <stdio.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // list of available audio devices
    QList<QAudioDeviceInfo> input_devs = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
    QList<QAudioDeviceInfo> output_devs = QAudioDeviceInfo::availableDevices(QAudio::AudioOutput);
    int nr_inputs = input_devs.size();
    int nr_outputs = output_devs.size();

    // display # of devices
    std::cout<<"# of inputs: "<<nr_inputs<<std::endl;
    std::cout<<"# of outputs: "<<nr_outputs<<std::endl;
    
    // display list of input devices
    std::cout << std::endl << std::endl << "Input Devices" << std::endl;
    for(int i=0; i<nr_inputs; ++i)
    {
        std::cout << i << ": " << input_devs[i].deviceName().toStdString() << std::endl;
    }

    // display list of output devices
    std::cout << std::endl << std::endl << "Output Devices" << std::endl;
    for(int i=0; i<nr_outputs; ++i)
    {
        std::cout << i << ": " << output_devs[i].deviceName().toStdString() << std::endl;
    }

    return a.exec();
}
