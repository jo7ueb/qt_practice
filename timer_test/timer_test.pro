#-------------------------------------------------
#
# Project created by QtCreator 2013-08-08T19:48:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = timer_test
TEMPLATE = app


SOURCES += main.cpp\
        TimerTestWindow.cpp \
    TimerModule.cpp

HEADERS  += TimerTestWindow.h \
    TimerModule.h

FORMS    += TimerTestWindow.ui
