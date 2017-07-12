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
    simple-soft/showmore.cpp \
    jsonfunc.cpp \
    simple-soft/classtop.cpp \
    simple-soft/custombutton.cpp \
    simple-soft/classwidget.cpp \
    simple-soft/classpage.cpp \
    simple-soft/morepage.cpp \
    simple-soft/recommendwidget.cpp

HEADERS  += softwindow.h \
    simple-soft/element.h \
    simple-soft/showmore.h \
    jsonfunc.h \
    simple-soft/classtop.h \
    simple-soft/custombutton.h \
    simple-soft/classwidget.h \
    sharedata.h \
    simple-soft/classpage.h \
    simple-soft/morepage.h \
    qreplytimeout.h \
    simple-soft/recommendwidget.h

RESOURCES += \
    iamge.qrc
