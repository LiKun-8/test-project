#-------------------------------------------------
#
# Project created by QtCreator 2017-07-31T14:02:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = system-monitor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cpu-monitor.cpp \
    memory-monitor.cpp \
    net-monitor.cpp

HEADERS  += mainwindow.h \
    cpu-monitor.h \
    memory-monitor.h \
    net-monitor.h
