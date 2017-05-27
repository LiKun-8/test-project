#-------------------------------------------------
#
# Project created by QtCreator 2017-05-25T13:59:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = simple-soft
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    element.cpp \
    topsort.cpp

HEADERS  += widget.h \
    element.h \
    topsort.h

FORMS    += widget.ui
