TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.c


unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += fftw3
unix: PKGCONFIG += portaudio-2.0
