#-------------------------------------------------
#
# Project created by QtCreator 2015-09-12T13:31:46
#
#-------------------------------------------------

QT       += core
QT       += network
QT       -= gui

TARGET = QUdpSocket
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    myudp.cpp \
    datagramsheader.cpp

HEADERS += \
    myudp.h \
    datagramsheader.h
