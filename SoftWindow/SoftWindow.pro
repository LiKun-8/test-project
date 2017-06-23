#-------------------------------------------------
#
# Project created by QtCreator 2017-05-24T14:55:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SoftWindow
TEMPLATE = app


SOURCES += main.cpp\
        softwindow.cpp \
    simple-soft/element.cpp \
    simple-soft/sortwidget.cpp \
    simple-soft/topsort.cpp \
    simple-soft/mybutton.cpp \
    softthread.cpp \
    simple-soft/showmore.cpp \
    jsonfunc.cpp

HEADERS  += softwindow.h \
    simple-soft/element.h \
    simple-soft/sortwidget.h \
    simple-soft/topsort.h \
    simple-soft/mybutton.h \
    softthread.h \
    simple-soft/showmore.h \
    jsonfunc.h

RESOURCES += \
    iamge.qrc
