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
    network/tcpclientcontroller.cpp \
    network/tcpservercontroller.cpp \
    hal/isfcarhalx86.cpp \
    hal/i_isfcarhal.cpp \
    isfcaruc/isfcaruc.cpp \
    isfcarthread.cpp \
    hal/hardware/motor/imotor.cpp \
    hal/hardware/motor/motorxtec1.cpp \
    hal/hardware/steering/isteering.cpp \
    hal/hardware/steering/steeringtrf417.cpp \
    isfcaruc/controller/speedcontroller.cpp \
    isfcaruc/controller/pidcontroller.cpp \
    simulationconnectioncontroller.cpp \
    brainboardcontroller.cpp \
    isfcaruc/controller/steeringcontroller.cpp

HEADERS  += mainwindow.h \
        qcustomplot.h \
    startwindow.h \
    hal/i_isfcarhal.h \
    hal/isfcarhalx86.h \
    isfcaruc/isfcaruc.h \
    hal/isfdata.h \
    isfcarthread.h \
    hal/hardware/motor/imotor.h \
    hal/hardware/motor/motorxtec1.h \
    hal/hardware/steering/isteering.h \
    hal/hardware/steering/steeringtrf417.h \
    isfcaruc/controller/speedcontroller.h \
    simulationconnectioncontroller.h \
    brainboardcontroller.h \
    isfcaruc/controller/steeringcontroller.h \
    isfcaruc/controller/pidcontroller.h \
    network/tcpclientcontroller.h \
    network/tcpservercontroller.h

FORMS    += mainwindow.ui \
    startwindow.ui
