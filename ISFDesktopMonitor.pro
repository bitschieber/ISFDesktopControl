#-------------------------------------------------
#
# Project created by QtCreator 2015-06-26T14:33:22
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG+= C++11

TARGET = ISFDesktopMonitor
TEMPLATE = app


SOURCES += main.cpp\
        qcustomplot.cpp \
        mainwindow.cpp \
    startwindow.cpp \
    Netzwerk/TCPClientController.cpp \
    Netzwerk/TCPServerController.cpp \
    HAL/isfcarhalx86.cpp \
    HAL/i_isfcarhal.cpp \
    ISFCarUc/isfcaruc.cpp \
    isfcarthread.cpp

HEADERS  += mainwindow.h \
        qcustomplot.h \
    startwindow.h \
    Netzwerk/TCPClientController.h \
    Netzwerk/TCPServerController.h \
    HAL/i_isfcarhal.h \
    HAL/isfcarhalx86.h \
    ISFCarUc/isfcaruc.h \
    HAL/isfdata.h \
    isfcarthread.h

FORMS    += mainwindow.ui \
    startwindow.ui
