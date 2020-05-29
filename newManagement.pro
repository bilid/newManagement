#-------------------------------------------------
#
# Project created by QtCreator 2020-05-26T08:48:58
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = newManagement
TEMPLATE = app


SOURCES += main.cpp\
        loader.cpp \
    mypushbutton.cpp \
    connectionpool.cpp \
    mainsence.cpp \
    system.cpp \
    systempage.cpp \
    vavle.cpp \
    myscrollarea.cpp \
    vavlepage.cpp

HEADERS  += loader.h \
    mypushbutton.h \
    connectionpool.h \
    mainsence.h \
    system.h \
    systempage.h \
    vavle.h \
    myscrollarea.h \
    vavlepage.h

FORMS    += loader.ui

RESOURCES += \
    res.qrc
