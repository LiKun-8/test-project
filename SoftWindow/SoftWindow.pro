#-------------------------------------------------
#
# Project created by QtCreator 2017-05-24T14:55:47
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SoftWindow
TEMPLATE = app


SOURCES += main.cpp\
        softwindow.cpp \
    simple-soft/element.cpp \
    softthread.cpp \
    simple-soft/showmore.cpp \
    jsonfunc.cpp \
    simple-soft/classtop.cpp \
    simple-soft/custombutton.cpp \
    simple-soft/classwidget.cpp \
    sharedata.cpp

HEADERS  += softwindow.h \
    simple-soft/element.h \
    softthread.h \
    simple-soft/showmore.h \
    jsonfunc.h \
    simple-soft/classtop.h \
    simple-soft/custombutton.h \
    simple-soft/classwidget.h \
    sharedata.h

RESOURCES += \
    iamge.qrc
