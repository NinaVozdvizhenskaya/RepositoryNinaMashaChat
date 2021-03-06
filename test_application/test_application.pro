#-------------------------------------------------
#
# Project created by QtCreator 2015-09-12T13:31:46
#
#-------------------------------------------------

QT       += core
QT       += network
QT       += gui
QT += widgets

TARGET = QUdpSocket
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
TARGET = btchat


SOURCES += \    
    main.cpp \
    serverudp.cpp \
   clientudp.cpp \
    messageheader.cpp \
    autorizationwindows.cpp \
    udpview.cpp

HEADERS += \
    serverudp.h \
   clientudp.h \
    messageheader.h \
    autorizationwindows.h \
    udpview.h

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

FORMS += \
    autorizationwindows.ui \
    udpview.ui
