#-------------------------------------------------
#
# Project created by QtCreator 2015-04-28T08:50:14
#
#-------------------------------------------------

QT       += core gui
QT       += core network
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KitchenMinder4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    serialPorts.cpp \
    mythread.cpp \
    variables.cpp

HEADERS  += mainwindow.h \
    serialPorts.h \
    variables.h \
    mythread.h

FORMS    += mainwindow.ui
include(qextserialport/src/qextserialport.pri )
