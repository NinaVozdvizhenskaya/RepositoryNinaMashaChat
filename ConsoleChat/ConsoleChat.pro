#-------------------------------------------------
#
# Project created by QtCreator 2015-09-12T18:38:07
#
#-------------------------------------------------

QT       += core
QT       += network
QT       -= gui
QT       += widgets
QT       +=
TARGET = QUdpSocket
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    messageheader.cpp \
    serverudp.cpp
FORMS    += mainwindow.ui

HEADERS += \
    messageheader.h \
    serverudp.h

QMAKE_CXXFLAGS += -std=c++11
