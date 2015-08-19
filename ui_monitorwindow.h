/********************************************************************************
** Form generated from reading UI file 'monitorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONITORWINDOW_H
#define UI_MONITORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MonitorWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QDockWidget *dockWidget_13;
    QWidget *dockWidgetContents_16;
    QFrame *frame_2;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QPushButton *pushButtonBrainBoardConnection;
    QLineEdit *lineEditBrainBoardIP;
    QLineEdit *lineEditBrainBoardPort;
    QDockWidget *dockWidget_14;
    QWidget *dockWidgetContents_17;
    QFrame *frame_5;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *labelSpeedHardware_2;
    QLabel *labelSteeringAngleHardware_2;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *labelSpeedHardwarePWM_2;
    QLabel *labelSteeringAngleHardwarePWM_2;
    QLabel *label_37;
    QLabel *labelMouseSensorDx_2;
    QLabel *labelMouseSensorDy_2;
    QFrame *frameLED8;
    QLabel *label_15;
    QLabel *label_12;
    QFrame *frameLED7;
    QFrame *frameLED1;
    QLabel *label_13;
    QFrame *frameLED4;
    QFrame *frameLED5;
    QLabel *label_9;
    QFrame *frameLED3;
    QFrame *frameLED6;
    QLabel *label_16;
    QLabel *label_14;
    QLabel *label_10;
    QLabel *label_11;
    QFrame *frameLED2;
    QDockWidget *dockWidget_7;
    QWidget *dockWidgetContents_10;
    QGridLayout *gridLayout_8;
    QCustomPlot *plotMouseSensor_BB;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents_18;
    QGridLayout *gridLayout_7;
    QCustomPlot *plotSpeed_BB;
    QDockWidget *dockWidget_15;
    QWidget *dockWidgetContents_19;
    QGridLayout *gridLayout_9;
    QCustomPlot *plotSteeringAngle_BB;
    QDockWidget *dockWidget_16;
    QWidget *dockWidgetContents_20;
    QGridLayout *gridLayout_10;
    QCustomPlot *plotPWM_BB;

    void setupUi(QMainWindow *MonitorWindow)
    {
        if (MonitorWindow->objectName().isEmpty())
            MonitorWindow->setObjectName(QStringLiteral("MonitorWindow"));
        MonitorWindow->resize(1244, 774);
        centralwidget = new QWidget(MonitorWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        MonitorWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MonitorWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1244, 21));
        MonitorWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MonitorWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MonitorWindow->setStatusBar(statusbar);
        dockWidget_13 = new QDockWidget(MonitorWindow);
        dockWidget_13->setObjectName(QStringLiteral("dockWidget_13"));
        dockWidgetContents_16 = new QWidget();
        dockWidgetContents_16->setObjectName(QStringLiteral("dockWidgetContents_16"));
        frame_2 = new QFrame(dockWidgetContents_16);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 0, 211, 111));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        label_20 = new QLabel(frame_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(10, 55, 47, 13));
        label_21 = new QLabel(frame_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(10, 30, 47, 13));
        label_22 = new QLabel(frame_2);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(10, 10, 61, 16));
        pushButtonBrainBoardConnection = new QPushButton(frame_2);
        pushButtonBrainBoardConnection->setObjectName(QStringLiteral("pushButtonBrainBoardConnection"));
        pushButtonBrainBoardConnection->setGeometry(QRect(130, 80, 75, 23));
        lineEditBrainBoardIP = new QLineEdit(frame_2);
        lineEditBrainBoardIP->setObjectName(QStringLiteral("lineEditBrainBoardIP"));
        lineEditBrainBoardIP->setGeometry(QRect(70, 25, 113, 20));
        lineEditBrainBoardPort = new QLineEdit(frame_2);
        lineEditBrainBoardPort->setObjectName(QStringLiteral("lineEditBrainBoardPort"));
        lineEditBrainBoardPort->setGeometry(QRect(70, 55, 113, 20));
        dockWidget_13->setWidget(dockWidgetContents_16);
        MonitorWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_13);
        dockWidget_14 = new QDockWidget(MonitorWindow);
        dockWidget_14->setObjectName(QStringLiteral("dockWidget_14"));
        dockWidgetContents_17 = new QWidget();
        dockWidgetContents_17->setObjectName(QStringLiteral("dockWidgetContents_17"));
        frame_5 = new QFrame(dockWidgetContents_17);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setGeometry(QRect(0, 0, 521, 151));
        frame_5->setFrameShape(QFrame::Box);
        frame_5->setFrameShadow(QFrame::Raised);
        label_32 = new QLabel(frame_5);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(10, 5, 111, 16));
        label_33 = new QLabel(frame_5);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(10, 40, 111, 16));
        label_34 = new QLabel(frame_5);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(10, 60, 111, 16));
        labelSpeedHardware_2 = new QLabel(frame_5);
        labelSpeedHardware_2->setObjectName(QStringLiteral("labelSpeedHardware_2"));
        labelSpeedHardware_2->setGeometry(QRect(120, 40, 61, 16));
        labelSpeedHardware_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelSteeringAngleHardware_2 = new QLabel(frame_5);
        labelSteeringAngleHardware_2->setObjectName(QStringLiteral("labelSteeringAngleHardware_2"));
        labelSteeringAngleHardware_2->setGeometry(QRect(120, 60, 61, 16));
        labelSteeringAngleHardware_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_35 = new QLabel(frame_5);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(240, 10, 50, 21));
        label_35->setMinimumSize(QSize(50, 0));
        label_35->setAlignment(Qt::AlignCenter);
        label_36 = new QLabel(frame_5);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(140, 10, 50, 16));
        label_36->setMinimumSize(QSize(50, 0));
        label_36->setAlignment(Qt::AlignCenter);
        labelSpeedHardwarePWM_2 = new QLabel(frame_5);
        labelSpeedHardwarePWM_2->setObjectName(QStringLiteral("labelSpeedHardwarePWM_2"));
        labelSpeedHardwarePWM_2->setGeometry(QRect(220, 40, 61, 16));
        labelSpeedHardwarePWM_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelSteeringAngleHardwarePWM_2 = new QLabel(frame_5);
        labelSteeringAngleHardwarePWM_2->setObjectName(QStringLiteral("labelSteeringAngleHardwarePWM_2"));
        labelSteeringAngleHardwarePWM_2->setGeometry(QRect(220, 60, 61, 16));
        labelSteeringAngleHardwarePWM_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_37 = new QLabel(frame_5);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(10, 110, 111, 16));
        labelMouseSensorDx_2 = new QLabel(frame_5);
        labelMouseSensorDx_2->setObjectName(QStringLiteral("labelMouseSensorDx_2"));
        labelMouseSensorDx_2->setGeometry(QRect(120, 110, 61, 16));
        labelMouseSensorDx_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelMouseSensorDy_2 = new QLabel(frame_5);
        labelMouseSensorDy_2->setObjectName(QStringLiteral("labelMouseSensorDy_2"));
        labelMouseSensorDy_2->setGeometry(QRect(220, 110, 61, 16));
        labelMouseSensorDy_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        frameLED8 = new QFrame(dockWidgetContents_17);
        frameLED8->setObjectName(QStringLiteral("frameLED8"));
        frameLED8->setGeometry(QRect(290, 180, 30, 30));
        frameLED8->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 127);"));
        frameLED8->setFrameShape(QFrame::StyledPanel);
        frameLED8->setFrameShadow(QFrame::Raised);
        label_15 = new QLabel(dockWidgetContents_17);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(210, 160, 30, 16));
        label_12 = new QLabel(dockWidgetContents_17);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(90, 160, 30, 16));
        frameLED7 = new QFrame(dockWidgetContents_17);
        frameLED7->setObjectName(QStringLiteral("frameLED7"));
        frameLED7->setGeometry(QRect(250, 180, 30, 30));
        frameLED7->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 127);"));
        frameLED7->setFrameShape(QFrame::StyledPanel);
        frameLED7->setFrameShadow(QFrame::Raised);
        frameLED1 = new QFrame(dockWidgetContents_17);
        frameLED1->setObjectName(QStringLiteral("frameLED1"));
        frameLED1->setGeometry(QRect(10, 180, 30, 30));
        frameLED1->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 127);"));
        frameLED1->setFrameShape(QFrame::StyledPanel);
        frameLED1->setFrameShadow(QFrame::Raised);
        label_13 = new QLabel(dockWidgetContents_17);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(290, 160, 30, 16));
        frameLED4 = new QFrame(dockWidgetContents_17);
        frameLED4->setObjectName(QStringLiteral("frameLED4"));
        frameLED4->setGeometry(QRect(130, 180, 30, 30));
        frameLED4->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 127);"));
        frameLED4->setFrameShape(QFrame::StyledPanel);
        frameLED4->setFrameShadow(QFrame::Raised);
        frameLED5 = new QFrame(dockWidgetContents_17);
        frameLED5->setObjectName(QStringLiteral("frameLED5"));
        frameLED5->setGeometry(QRect(170, 180, 30, 30));
        frameLED5->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 127);"));
        frameLED5->setFrameShape(QFrame::StyledPanel);
        frameLED5->setFrameShadow(QFrame::Raised);
        label_9 = new QLabel(dockWidgetContents_17);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 160, 30, 16));
        frameLED3 = new QFrame(dockWidgetContents_17);
        frameLED3->setObjectName(QStringLiteral("frameLED3"));
        frameLED3->setGeometry(QRect(90, 180, 30, 30));
        frameLED3->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 127);"));
        frameLED3->setFrameShape(QFrame::StyledPanel);
        frameLED3->setFrameShadow(QFrame::Raised);
        frameLED6 = new QFrame(dockWidgetContents_17);
        frameLED6->setObjectName(QStringLiteral("frameLED6"));
        frameLED6->setGeometry(QRect(210, 180, 30, 30));
        frameLED6->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 127);"));
        frameLED6->setFrameShape(QFrame::StyledPanel);
        frameLED6->setFrameShadow(QFrame::Raised);
        label_16 = new QLabel(dockWidgetContents_17);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(170, 160, 30, 16));
        label_14 = new QLabel(dockWidgetContents_17);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(250, 160, 30, 16));
        label_10 = new QLabel(dockWidgetContents_17);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(50, 160, 30, 16));
        label_11 = new QLabel(dockWidgetContents_17);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(130, 160, 30, 16));
        frameLED2 = new QFrame(dockWidgetContents_17);
        frameLED2->setObjectName(QStringLiteral("frameLED2"));
        frameLED2->setGeometry(QRect(50, 180, 30, 30));
        frameLED2->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 127);"));
        frameLED2->setFrameShape(QFrame::StyledPanel);
        frameLED2->setFrameShadow(QFrame::Raised);
        dockWidget_14->setWidget(dockWidgetContents_17);
        MonitorWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_14);
        dockWidget_7 = new QDockWidget(MonitorWindow);
        dockWidget_7->setObjectName(QStringLiteral("dockWidget_7"));
        dockWidgetContents_10 = new QWidget();
        dockWidgetContents_10->setObjectName(QStringLiteral("dockWidgetContents_10"));
        gridLayout_8 = new QGridLayout(dockWidgetContents_10);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        plotMouseSensor_BB = new QCustomPlot(dockWidgetContents_10);
        plotMouseSensor_BB->setObjectName(QStringLiteral("plotMouseSensor_BB"));
        plotMouseSensor_BB->setStyleSheet(QStringLiteral("background-color: rgb(255, 228, 229);"));

        gridLayout_8->addWidget(plotMouseSensor_BB, 0, 0, 1, 1);

        dockWidget_7->setWidget(dockWidgetContents_10);
        MonitorWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_7);
        dockWidget = new QDockWidget(MonitorWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidgetContents_18 = new QWidget();
        dockWidgetContents_18->setObjectName(QStringLiteral("dockWidgetContents_18"));
        gridLayout_7 = new QGridLayout(dockWidgetContents_18);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        plotSpeed_BB = new QCustomPlot(dockWidgetContents_18);
        plotSpeed_BB->setObjectName(QStringLiteral("plotSpeed_BB"));
        plotSpeed_BB->setStyleSheet(QStringLiteral("background-color: rgb(255, 228, 229);"));

        gridLayout_7->addWidget(plotSpeed_BB, 0, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents_18);
        MonitorWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget);
        dockWidget_15 = new QDockWidget(MonitorWindow);
        dockWidget_15->setObjectName(QStringLiteral("dockWidget_15"));
        dockWidgetContents_19 = new QWidget();
        dockWidgetContents_19->setObjectName(QStringLiteral("dockWidgetContents_19"));
        gridLayout_9 = new QGridLayout(dockWidgetContents_19);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        plotSteeringAngle_BB = new QCustomPlot(dockWidgetContents_19);
        plotSteeringAngle_BB->setObjectName(QStringLiteral("plotSteeringAngle_BB"));
        plotSteeringAngle_BB->setStyleSheet(QStringLiteral("background-color: rgb(255, 228, 229);"));

        gridLayout_9->addWidget(plotSteeringAngle_BB, 0, 0, 1, 1);

        dockWidget_15->setWidget(dockWidgetContents_19);
        MonitorWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_15);
        dockWidget_16 = new QDockWidget(MonitorWindow);
        dockWidget_16->setObjectName(QStringLiteral("dockWidget_16"));
        dockWidgetContents_20 = new QWidget();
        dockWidgetContents_20->setObjectName(QStringLiteral("dockWidgetContents_20"));
        gridLayout_10 = new QGridLayout(dockWidgetContents_20);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        plotPWM_BB = new QCustomPlot(dockWidgetContents_20);
        plotPWM_BB->setObjectName(QStringLiteral("plotPWM_BB"));
        plotPWM_BB->setStyleSheet(QStringLiteral("background-color: rgb(255, 228, 229);"));

        gridLayout_10->addWidget(plotPWM_BB, 0, 0, 1, 1);

        dockWidget_16->setWidget(dockWidgetContents_20);
        MonitorWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_16);

        retranslateUi(MonitorWindow);

        QMetaObject::connectSlotsByName(MonitorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MonitorWindow)
    {
        MonitorWindow->setWindowTitle(QApplication::translate("MonitorWindow", "ISFCar Monitor", 0));
        label_20->setText(QApplication::translate("MonitorWindow", "Port:", 0));
        label_21->setText(QApplication::translate("MonitorWindow", "IP:", 0));
        label_22->setText(QApplication::translate("MonitorWindow", "BrainBoard", 0));
        pushButtonBrainBoardConnection->setText(QApplication::translate("MonitorWindow", "undefined", 0));
        lineEditBrainBoardIP->setText(QApplication::translate("MonitorWindow", "10.0.0.39", 0));
        lineEditBrainBoardPort->setText(QApplication::translate("MonitorWindow", "4442", 0));
        label_32->setText(QApplication::translate("MonitorWindow", "Data From Hardware", 0));
        label_33->setText(QApplication::translate("MonitorWindow", "Speed (mm/s):", 0));
        label_34->setText(QApplication::translate("MonitorWindow", "SteeringAngle (deg):", 0));
        labelSpeedHardware_2->setText(QApplication::translate("MonitorWindow", "undefined", 0));
        labelSteeringAngleHardware_2->setText(QApplication::translate("MonitorWindow", "undefined", 0));
        label_35->setText(QApplication::translate("MonitorWindow", "PWM", 0));
        label_36->setText(QApplication::translate("MonitorWindow", "Value", 0));
        labelSpeedHardwarePWM_2->setText(QApplication::translate("MonitorWindow", "undefined", 0));
        labelSteeringAngleHardwarePWM_2->setText(QApplication::translate("MonitorWindow", "undefined", 0));
        label_37->setText(QApplication::translate("MonitorWindow", "MouseSensor", 0));
        labelMouseSensorDx_2->setText(QApplication::translate("MonitorWindow", "undefined", 0));
        labelMouseSensorDy_2->setText(QApplication::translate("MonitorWindow", "undefined", 0));
        label_15->setText(QApplication::translate("MonitorWindow", "LED 6", 0));
        label_12->setText(QApplication::translate("MonitorWindow", "LED 3", 0));
        label_13->setText(QApplication::translate("MonitorWindow", "LED 8", 0));
        label_9->setText(QApplication::translate("MonitorWindow", "LED 1", 0));
        label_16->setText(QApplication::translate("MonitorWindow", "LED 5", 0));
        label_14->setText(QApplication::translate("MonitorWindow", "LED 7", 0));
        label_10->setText(QApplication::translate("MonitorWindow", "LED 2", 0));
        label_11->setText(QApplication::translate("MonitorWindow", "LED 4", 0));
        dockWidget_7->setWindowTitle(QApplication::translate("MonitorWindow", "Mouse-Sensor (mm)", 0));
        dockWidget->setWindowTitle(QApplication::translate("MonitorWindow", "Spped (mm/s)", 0));
        dockWidget_15->setWindowTitle(QApplication::translate("MonitorWindow", "Steering-Angle (deg)", 0));
        dockWidget_16->setWindowTitle(QApplication::translate("MonitorWindow", "PWM (ms)", 0));
    } // retranslateUi

};

namespace Ui {
    class MonitorWindow: public Ui_MonitorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONITORWINDOW_H
