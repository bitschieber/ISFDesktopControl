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
    hal/isfcarhalx86.cpp \
    hal/i_isfcarhal.cpp \
    ISFCarUc/isfcaruc.cpp \
    isfcarthread.cpp \
    hal/hardware/motor/imotor.cpp \
    hal/hardware/motor/motorxtec1.cpp \
    hal/hardware/steering/isteering.cpp \
    hal/hardware/steering/steeringtrf417.cpp \
    ISFCarUc/controller/speedcontroller.cpp \
    ISFCarUc/controller/PIDController.cpp \
    simulationconnectioncontroller.cpp \
    brainboardcontroller.cpp

HEADERS  += mainwindow.h \
        qcustomplot.h \
    startwindow.h \
    Netzwerk/TCPClientController.h \
    Netzwerk/TCPServerController.h \
    hal/i_isfcarhal.h \
    hal/isfcarhalx86.h \
    ISFCarUc/isfcaruc.h \
    hal/isfdata.h \
    isfcarthread.h \
    hal/hardware/motor/imotor.h \
    hal/hardware/motor/motorxtec1.h \
    hal/hardware/steering/isteering.h \
    hal/hardware/steering/steeringtrf417.h \
    ISFCarUc/controller/speedcontroller.h \
    ISFCarUc/controller/PIDController.h \
    simulationconnectioncontroller.h \
    brainboardcontroller.h

FORMS    += mainwindow.ui \
    startwindow.ui
