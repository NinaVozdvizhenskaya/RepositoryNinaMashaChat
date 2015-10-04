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


SOURCES += \    
    main.cpp \
    serverudp.cpp \
    clientudp.cpp \
    messageheader.cpp

HEADERS += \
    serverudp.h \
    clientudp.h \
    messageheader.h

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11
