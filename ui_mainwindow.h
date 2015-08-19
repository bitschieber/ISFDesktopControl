/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidgetPlotSteering;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_2;
    QCustomPlot *plotSteeringAngle;
    QDockWidget *dockWidgetPlotSpeed_2;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout;
    QCustomPlot *plotSpeed;
    QDockWidget *dockWidgetPlotPWM;
    QWidget *dockWidgetContents_3;
    QGridLayout *gridLayout_4;
    QCustomPlot *plotPWM;
    QDockWidget *dockWidgetSimulationControl;
    QWidget *dockWidgetContents_4;
    QPushButton *pushButtonSimulationStepForward;
    QPushButton *pushButtonSimulationReset;
    QLabel *label;
    QLabel *label_2;
    QLabel *labelSimulationCurrentTime;
    QPushButton *pushButtonSimulationPlay;
    QLabel *label_3;
    QLineEdit *labelSimulationTimeStep;
    QLineEdit *labelSimulationImageUpdateTime;
    QDockWidget *dockWidgetHardwareIO;
    QWidget *dockWidgetContents_12;
    QLabel *label_9;
    QFrame *frameLED1;
    QFrame *frameLED2;
    QLabel *label_10;
    QFrame *frameLED3;
    QLabel *label_11;
    QLabel *label_12;
    QFrame *frameLED4;
    QFrame *frameLED5;
    QLabel *label_13;
    QFrame *frameLED7;
    QLabel *label_14;
    QLabel *label_15;
    QFrame *frameLED8;
    QLabel *label_16;
    QFrame *frameLED6;
    QCheckBox *cbRCOnOff;
    QCheckBox *cbUserButton01;
    QCheckBox *cbUserButton02;
    QSlider *sliderADC1;
    QLabel *label_31;
    QLabel *labelADC1Val;
    QDockWidget *dockWidgetConnection;
    QWidget *dockWidgetContents_7;
    QScrollArea *scrollAreaConnectionSettings;
    QWidget *scrollAreaWidgetContents;
    QFrame *frame;
    QLabel *label_18;
    QLabel *label_17;
    QLabel *label_19;
    QPushButton *pushButtonSimulationConnection;
    QLineEdit *lineEditSimulationIP;
    QLineEdit *lineEditSimulationPort;
    QFrame *frame_2;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QPushButton *pushButtonBrainBoardConnection;
    QLineEdit *lineEditBrainBoardIP;
    QLineEdit *lineEditBrainBoardPort;
    QDockWidget *dockWidgetTrace;
    QWidget *dockWidgetContents_8;
    QGridLayout *gridLayout_5;
    QTextBrowser *labelDebugLog;
    QDockWidget *dockWidgetSimulationView;
    QWidget *dockWidgetContents_16;
    QGridLayout *gridLayout_14;
    QGraphicsView *graphicsViewSimulationView;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_17;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QFrame *frame_3;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *labelSpeedFromBrainBoard;
    QLabel *labelSteeringAngleFromBrainBoard;
    QWidget *tab_2;
    QFrame *frame_4;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *labelSpeedHardware;
    QLabel *labelSteeringAngleHardware;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *labelSpeedHardwarePWM;
    QLabel *labelSteeringAngleHardwarePWM;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 768);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidgetPlotSteering = new QDockWidget(MainWindow);
        dockWidgetPlotSteering->setObjectName(QStringLiteral("dockWidgetPlotSteering"));
        dockWidgetPlotSteering->setMinimumSize(QSize(320, 100));
        dockWidgetPlotSteering->setStyleSheet(QStringLiteral("background-color: rgb(220, 236, 255);"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        gridLayout_2 = new QGridLayout(dockWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        plotSteeringAngle = new QCustomPlot(dockWidgetContents);
        plotSteeringAngle->setObjectName(QStringLiteral("plotSteeringAngle"));
        plotSteeringAngle->setStyleSheet(QStringLiteral("background-color: rgb(255, 228, 229);"));

        gridLayout_2->addWidget(plotSteeringAngle, 0, 0, 1, 1);

        dockWidgetPlotSteering->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidgetPlotSteering);
        dockWidgetPlotSpeed_2 = new QDockWidget(MainWindow);
        dockWidgetPlotSpeed_2->setObjectName(QStringLiteral("dockWidgetPlotSpeed_2"));
        dockWidgetPlotSpeed_2->setMinimumSize(QSize(76, 100));
        dockWidgetPlotSpeed_2->setStyleSheet(QStringLiteral("background-color: rgb(220, 236, 255);"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        gridLayout = new QGridLayout(dockWidgetContents_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        plotSpeed = new QCustomPlot(dockWidgetContents_2);
        plotSpeed->setObjectName(QStringLiteral("plotSpeed"));
        plotSpeed->setStyleSheet(QStringLiteral("background-color: rgb(255, 228, 229);"));

        gridLayout->addWidget(plotSpeed, 0, 0, 1, 1);

        dockWidgetPlotSpeed_2->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidgetPlotSpeed_2);
        dockWidgetPlotPWM = new QDockWidget(MainWindow);
        dockWidgetPlotPWM->setObjectName(QStringLiteral("dockWidgetPlotPWM"));
        dockWidgetPlotPWM->setMinimumSize(QSize(76, 100));
        dockWidgetPlotPWM->setStyleSheet(QStringLiteral("background-color: rgb(220, 236, 255);"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        gridLayout_4 = new QGridLayout(dockWidgetContents_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        plotPWM = new QCustomPlot(dockWidgetContents_3);
        plotPWM->setObjectName(QStringLiteral("plotPWM"));
        plotPWM->setStyleSheet(QStringLiteral("background-color: rgb(255, 228, 229);"));

        gridLayout_4->addWidget(plotPWM, 0, 0, 1, 1);

        dockWidgetPlotPWM->setWidget(dockWidgetContents_3);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidgetPlotPWM);
        dockWidgetSimulationControl = new QDockWidget(MainWindow);
        dockWidgetSimulationControl->setObjectName(QStringLiteral("dockWidgetSimulationControl"));
        dockWidgetSimulationControl->setMinimumSize(QSize(290, 150));
        dockWidgetSimulationControl->setStyleSheet(QStringLiteral("background-color: rgb(220, 236, 255);"));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        pushButtonSimulationStepForward = new QPushButton(dockWidgetContents_4);
        pushButtonSimulationStepForward->setObjectName(QStringLiteral("pushButtonSimulationStepForward"));
        pushButtonSimulationStepForward->setGeometry(QRect(300, 20, 60, 23));
        pushButtonSimulationReset = new QPushButton(dockWidgetContents_4);
        pushButtonSimulationReset->setObjectName(QStringLiteral("pushButtonSimulationReset"));
        pushButtonSimulationReset->setGeometry(QRect(80, 20, 60, 23));
        label = new QLabel(dockWidgetContents_4);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 70, 100, 16));
        label_2 = new QLabel(dockWidgetContents_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(150, 20, 81, 16));
        labelSimulationCurrentTime = new QLabel(dockWidgetContents_4);
        labelSimulationCurrentTime->setObjectName(QStringLiteral("labelSimulationCurrentTime"));
        labelSimulationCurrentTime->setGeometry(QRect(140, 70, 81, 16));
        labelSimulationCurrentTime->setLayoutDirection(Qt::LeftToRight);
        labelSimulationCurrentTime->setFrameShape(QFrame::Box);
        labelSimulationCurrentTime->setTextFormat(Qt::AutoText);
        labelSimulationCurrentTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButtonSimulationPlay = new QPushButton(dockWidgetContents_4);
        pushButtonSimulationPlay->setObjectName(QStringLiteral("pushButtonSimulationPlay"));
        pushButtonSimulationPlay->setGeometry(QRect(10, 20, 60, 23));
        label_3 = new QLabel(dockWidgetContents_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(150, 50, 91, 16));
        labelSimulationTimeStep = new QLineEdit(dockWidgetContents_4);
        labelSimulationTimeStep->setObjectName(QStringLiteral("labelSimulationTimeStep"));
        labelSimulationTimeStep->setGeometry(QRect(250, 20, 41, 20));
        labelSimulationImageUpdateTime = new QLineEdit(dockWidgetContents_4);
        labelSimulationImageUpdateTime->setObjectName(QStringLiteral("labelSimulationImageUpdateTime"));
        labelSimulationImageUpdateTime->setGeometry(QRect(250, 50, 41, 20));
        dockWidgetSimulationControl->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetSimulationControl);
        dockWidgetHardwareIO = new QDockWidget(MainWindow);
        dockWidgetHardwareIO->setObjectName(QStringLiteral("dockWidgetHardwareIO"));
        dockWidgetHardwareIO->setMinimumSize(QSize(520, 100));
        dockWidgetHardwareIO->setStyleSheet(QStringLiteral("background-color: rgb(220, 236, 255);"));
        dockWidgetContents_12 = new QWidget();
        dockWidgetContents_12->setObjectName(QStringLiteral("dockWidgetContents_12"));
        label_9 = new QLabel(dockWidgetContents_12);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(125, 10, 41, 16));
        frameLED1 = new QFrame(dockWidgetContents_12);
        frameLED1->setObjectName(QStringLiteral("frameLED1"));
        frameLED1->setGeometry(QRect(130, 30, 30, 30));
        frameLED1->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 127);"));
        frameLED1->setFrameShape(QFrame::StyledPanel);
        frameLED1->setFrameShadow(QFrame::Raised);
        frameLED2 = new QFrame(dockWidgetContents_12);
        frameLED2->setObjectName(QStringLiteral("frameLED2"));
        frameLED2->setGeometry(QRect(180, 30, 30, 30));
        frameLED2->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 127);"));
        frameLED2->setFrameShape(QFrame::StyledPanel);
        frameLED2->setFrameShadow(QFrame::Raised);
        label_10 = new QLabel(dockWidgetContents_12);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(175, 10, 41, 16));
        frameLED3 = new QFrame(dockWidgetContents_12);
        frameLED3->setObjectName(QStringLiteral("frameLED3"));
        frameLED3->setGeometry(QRect(230, 30, 30, 30));
        frameLED3->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 127);"));
        frameLED3->setFrameShape(QFrame::StyledPanel);
        frameLED3->setFrameShadow(QFrame::Raised);
        label_11 = new QLabel(dockWidgetContents_12);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(275, 10, 41, 16));
        label_12 = new QLabel(dockWidgetContents_12);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(225, 10, 41, 16));
        frameLED4 = new QFrame(dockWidgetContents_12);
        frameLED4->setObjectName(QStringLiteral("frameLED4"));
        frameLED4->setGeometry(QRect(280, 30, 30, 30));
        frameLED4->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 127);"));
        frameLED4->setFrameShape(QFrame::StyledPanel);
        frameLED4->setFrameShadow(QFrame::Raised);
        frameLED5 = new QFrame(dockWidgetContents_12);
        frameLED5->setObjectName(QStringLiteral("frameLED5"));
        frameLED5->setGeometry(QRect(330, 30, 30, 30));
        frameLED5->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 127);"));
        frameLED5->setFrameShape(QFrame::StyledPanel);
        frameLED5->setFrameShadow(QFrame::Raised);
        label_13 = new QLabel(dockWidgetContents_12);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(475, 10, 41, 16));
        frameLED7 = new QFrame(dockWidgetContents_12);
        frameLED7->setObjectName(QStringLiteral("frameLED7"));
        frameLED7->setGeometry(QRect(430, 30, 30, 30));
        frameLED7->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 127);"));
        frameLED7->setFrameShape(QFrame::StyledPanel);
        frameLED7->setFrameShadow(QFrame::Raised);
        label_14 = new QLabel(dockWidgetContents_12);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(425, 10, 41, 16));
        label_15 = new QLabel(dockWidgetContents_12);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(375, 10, 41, 16));
        frameLED8 = new QFrame(dockWidgetContents_12);
        frameLED8->setObjectName(QStringLiteral("frameLED8"));
        frameLED8->setGeometry(QRect(480, 30, 30, 30));
        frameLED8->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 127);"));
        frameLED8->setFrameShape(QFrame::StyledPanel);
        frameLED8->setFrameShadow(QFrame::Raised);
        label_16 = new QLabel(dockWidgetContents_12);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(325, 10, 41, 16));
        frameLED6 = new QFrame(dockWidgetContents_12);
        frameLED6->setObjectName(QStringLiteral("frameLED6"));
        frameLED6->setGeometry(QRect(380, 30, 30, 30));
        frameLED6->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 127);"));
        frameLED6->setFrameShape(QFrame::StyledPanel);
        frameLED6->setFrameShadow(QFrame::Raised);
        cbRCOnOff = new QCheckBox(dockWidgetContents_12);
        cbRCOnOff->setObjectName(QStringLiteral("cbRCOnOff"));
        cbRCOnOff->setGeometry(QRect(10, 10, 91, 17));
        cbUserButton01 = new QCheckBox(dockWidgetContents_12);
        cbUserButton01->setObjectName(QStringLiteral("cbUserButton01"));
        cbUserButton01->setGeometry(QRect(10, 40, 91, 17));
        cbUserButton02 = new QCheckBox(dockWidgetContents_12);
        cbUserButton02->setObjectName(QStringLiteral("cbUserButton02"));
        cbUserButton02->setGeometry(QRect(10, 60, 91, 17));
        sliderADC1 = new QSlider(dockWidgetContents_12);
        sliderADC1->setObjectName(QStringLiteral("sliderADC1"));
        sliderADC1->setGeometry(QRect(270, 70, 160, 22));
        sliderADC1->setMaximum(3500);
        sliderADC1->setSingleStep(50);
        sliderADC1->setValue(3500);
        sliderADC1->setOrientation(Qt::Horizontal);
        label_31 = new QLabel(dockWidgetContents_12);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(200, 70, 61, 20));
        labelADC1Val = new QLabel(dockWidgetContents_12);
        labelADC1Val->setObjectName(QStringLiteral("labelADC1Val"));
        labelADC1Val->setGeometry(QRect(440, 70, 61, 20));
        dockWidgetHardwareIO->setWidget(dockWidgetContents_12);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidgetHardwareIO);
        dockWidgetConnection = new QDockWidget(MainWindow);
        dockWidgetConnection->setObjectName(QStringLiteral("dockWidgetConnection"));
        dockWidgetConnection->setMinimumSize(QSize(480, 150));
        dockWidgetConnection->setStyleSheet(QStringLiteral("background-color: rgb(220, 236, 255);"));
        dockWidgetContents_7 = new QWidget();
        dockWidgetContents_7->setObjectName(QStringLiteral("dockWidgetContents_7"));
        scrollAreaConnectionSettings = new QScrollArea(dockWidgetContents_7);
        scrollAreaConnectionSettings->setObjectName(QStringLiteral("scrollAreaConnectionSettings"));
        scrollAreaConnectionSettings->setGeometry(QRect(9, 9, 461, 131));
        scrollAreaConnectionSettings->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 459, 129));
        frame = new QFrame(scrollAreaWidgetContents);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 0, 211, 111));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        label_18 = new QLabel(frame);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(10, 55, 47, 13));
        label_17 = new QLabel(frame);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 30, 47, 13));
        label_19 = new QLabel(frame);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(10, 10, 47, 13));
        pushButtonSimulationConnection = new QPushButton(frame);
        pushButtonSimulationConnection->setObjectName(QStringLiteral("pushButtonSimulationConnection"));
        pushButtonSimulationConnection->setGeometry(QRect(130, 80, 75, 23));
        lineEditSimulationIP = new QLineEdit(frame);
        lineEditSimulationIP->setObjectName(QStringLiteral("lineEditSimulationIP"));
        lineEditSimulationIP->setGeometry(QRect(70, 25, 113, 20));
        lineEditSimulationPort = new QLineEdit(frame);
        lineEditSimulationPort->setObjectName(QStringLiteral("lineEditSimulationPort"));
        lineEditSimulationPort->setGeometry(QRect(70, 55, 113, 20));
        frame_2 = new QFrame(scrollAreaWidgetContents);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(240, 0, 211, 111));
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
        label_22->setGeometry(QRect(10, 10, 47, 13));
        pushButtonBrainBoardConnection = new QPushButton(frame_2);
        pushButtonBrainBoardConnection->setObjectName(QStringLiteral("pushButtonBrainBoardConnection"));
        pushButtonBrainBoardConnection->setGeometry(QRect(130, 80, 75, 23));
        lineEditBrainBoardIP = new QLineEdit(frame_2);
        lineEditBrainBoardIP->setObjectName(QStringLiteral("lineEditBrainBoardIP"));
        lineEditBrainBoardIP->setGeometry(QRect(70, 25, 113, 20));
        lineEditBrainBoardPort = new QLineEdit(frame_2);
        lineEditBrainBoardPort->setObjectName(QStringLiteral("lineEditBrainBoardPort"));
        lineEditBrainBoardPort->setGeometry(QRect(70, 55, 113, 20));
        scrollAreaConnectionSettings->setWidget(scrollAreaWidgetContents);
        dockWidgetConnection->setWidget(dockWidgetContents_7);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetConnection);
        dockWidgetTrace = new QDockWidget(MainWindow);
        dockWidgetTrace->setObjectName(QStringLiteral("dockWidgetTrace"));
        dockWidgetTrace->setStyleSheet(QStringLiteral("background-color: rgb(220, 236, 255);"));
        dockWidgetContents_8 = new QWidget();
        dockWidgetContents_8->setObjectName(QStringLiteral("dockWidgetContents_8"));
        gridLayout_5 = new QGridLayout(dockWidgetContents_8);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        labelDebugLog = new QTextBrowser(dockWidgetContents_8);
        labelDebugLog->setObjectName(QStringLiteral("labelDebugLog"));

        gridLayout_5->addWidget(labelDebugLog, 0, 0, 1, 1);

        dockWidgetTrace->setWidget(dockWidgetContents_8);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetTrace);
        dockWidgetSimulationView = new QDockWidget(MainWindow);
        dockWidgetSimulationView->setObjectName(QStringLiteral("dockWidgetSimulationView"));
        dockWidgetSimulationView->setMinimumSize(QSize(338, 280));
        dockWidgetSimulationView->setStyleSheet(QStringLiteral("background-color: rgb(220, 236, 255);"));
        dockWidgetContents_16 = new QWidget();
        dockWidgetContents_16->setObjectName(QStringLiteral("dockWidgetContents_16"));
        gridLayout_14 = new QGridLayout(dockWidgetContents_16);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        graphicsViewSimulationView = new QGraphicsView(dockWidgetContents_16);
        graphicsViewSimulationView->setObjectName(QStringLiteral("graphicsViewSimulationView"));
        graphicsViewSimulationView->setMinimumSize(QSize(320, 240));
        graphicsViewSimulationView->setAutoFillBackground(true);
        graphicsViewSimulationView->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_14->addWidget(graphicsViewSimulationView, 0, 0, 1, 1);

        dockWidgetSimulationView->setWidget(dockWidgetContents_16);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetSimulationView);
        dockWidget_2 = new QDockWidget(MainWindow);
        dockWidget_2->setObjectName(QStringLiteral("dockWidget_2"));
        dockWidget_2->setMinimumSize(QSize(145, 130));
        dockWidget_2->setStyleSheet(QStringLiteral("background-color: rgb(220, 236, 255);"));
        dockWidgetContents_17 = new QWidget();
        dockWidgetContents_17->setObjectName(QStringLiteral("dockWidgetContents_17"));
        gridLayout_3 = new QGridLayout(dockWidgetContents_17);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tabWidget = new QTabWidget(dockWidgetContents_17);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        frame_3 = new QFrame(tab);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(10, 10, 191, 91));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        label_23 = new QLabel(frame_3);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(10, 5, 111, 16));
        label_24 = new QLabel(frame_3);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(10, 40, 111, 16));
        label_25 = new QLabel(frame_3);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(10, 60, 111, 16));
        labelSpeedFromBrainBoard = new QLabel(frame_3);
        labelSpeedFromBrainBoard->setObjectName(QStringLiteral("labelSpeedFromBrainBoard"));
        labelSpeedFromBrainBoard->setGeometry(QRect(120, 40, 61, 16));
        labelSpeedFromBrainBoard->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelSteeringAngleFromBrainBoard = new QLabel(frame_3);
        labelSteeringAngleFromBrainBoard->setObjectName(QStringLiteral("labelSteeringAngleFromBrainBoard"));
        labelSteeringAngleFromBrainBoard->setGeometry(QRect(120, 60, 61, 16));
        labelSteeringAngleFromBrainBoard->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        frame_4 = new QFrame(tab_2);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(0, 10, 381, 91));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Raised);
        label_26 = new QLabel(frame_4);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(10, 5, 111, 16));
        label_27 = new QLabel(frame_4);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(10, 40, 111, 16));
        label_28 = new QLabel(frame_4);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(10, 60, 111, 16));
        labelSpeedHardware = new QLabel(frame_4);
        labelSpeedHardware->setObjectName(QStringLiteral("labelSpeedHardware"));
        labelSpeedHardware->setGeometry(QRect(120, 40, 61, 16));
        labelSpeedHardware->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelSteeringAngleHardware = new QLabel(frame_4);
        labelSteeringAngleHardware->setObjectName(QStringLiteral("labelSteeringAngleHardware"));
        labelSteeringAngleHardware->setGeometry(QRect(120, 60, 61, 16));
        labelSteeringAngleHardware->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_29 = new QLabel(frame_4);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(240, 10, 50, 21));
        label_29->setMinimumSize(QSize(50, 0));
        label_29->setAlignment(Qt::AlignCenter);
        label_30 = new QLabel(frame_4);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(140, 10, 50, 16));
        label_30->setMinimumSize(QSize(50, 0));
        label_30->setAlignment(Qt::AlignCenter);
        labelSpeedHardwarePWM = new QLabel(frame_4);
        labelSpeedHardwarePWM->setObjectName(QStringLiteral("labelSpeedHardwarePWM"));
        labelSpeedHardwarePWM->setGeometry(QRect(220, 40, 61, 16));
        labelSpeedHardwarePWM->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelSteeringAngleHardwarePWM = new QLabel(frame_4);
        labelSteeringAngleHardwarePWM->setObjectName(QStringLiteral("labelSteeringAngleHardwarePWM"));
        labelSteeringAngleHardwarePWM->setGeometry(QRect(220, 60, 61, 16));
        labelSteeringAngleHardwarePWM->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tabWidget->addTab(tab_2, QString());

        gridLayout_3->addWidget(tabWidget, 0, 0, 1, 1);

        dockWidget_2->setWidget(dockWidgetContents_17);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_2);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        dockWidgetPlotSteering->setWindowTitle(QApplication::translate("MainWindow", "Plot Steering", 0));
        dockWidgetPlotSpeed_2->setWindowTitle(QApplication::translate("MainWindow", "PlotSpeed", 0));
        dockWidgetPlotPWM->setWindowTitle(QApplication::translate("MainWindow", "PlotPWM", 0));
        dockWidgetSimulationControl->setWindowTitle(QApplication::translate("MainWindow", "Simulation Control", 0));
        pushButtonSimulationStepForward->setText(QApplication::translate("MainWindow", "1 Step", 0));
        pushButtonSimulationReset->setText(QApplication::translate("MainWindow", "Reset", 0));
        label->setText(QApplication::translate("MainWindow", "Current-Time (ms):", 0));
        label_2->setText(QApplication::translate("MainWindow", "Time-Step (ms):", 0));
        labelSimulationCurrentTime->setText(QApplication::translate("MainWindow", "undefined", 0));
        pushButtonSimulationPlay->setText(QApplication::translate("MainWindow", "Play", 0));
        label_3->setText(QApplication::translate("MainWindow", "ImageUpdate (ms):", 0));
        labelSimulationTimeStep->setText(QApplication::translate("MainWindow", "5", 0));
        labelSimulationImageUpdateTime->setText(QApplication::translate("MainWindow", "20", 0));
        dockWidgetHardwareIO->setWindowTitle(QApplication::translate("MainWindow", "HardwareIO", 0));
        label_9->setText(QApplication::translate("MainWindow", "GPIO_1", 0));
        label_10->setText(QApplication::translate("MainWindow", "GPIO_2", 0));
        label_11->setText(QApplication::translate("MainWindow", "GPIO_4", 0));
        label_12->setText(QApplication::translate("MainWindow", "GPIO_3", 0));
        label_13->setText(QApplication::translate("MainWindow", "GPIO_8", 0));
        label_14->setText(QApplication::translate("MainWindow", "GPIO_7", 0));
        label_15->setText(QApplication::translate("MainWindow", "GPIO_6", 0));
        label_16->setText(QApplication::translate("MainWindow", "GPIO_5", 0));
        cbRCOnOff->setText(QApplication::translate("MainWindow", "RC-On/Off", 0));
        cbUserButton01->setText(QApplication::translate("MainWindow", "User Button 01", 0));
        cbUserButton02->setText(QApplication::translate("MainWindow", "User Button 02", 0));
        label_31->setText(QApplication::translate("MainWindow", "ADC_1 (mV)", 0));
        labelADC1Val->setText(QApplication::translate("MainWindow", "3500 mV", 0));
        dockWidgetConnection->setWindowTitle(QApplication::translate("MainWindow", "Connection Settings", 0));
        label_18->setText(QApplication::translate("MainWindow", "Port:", 0));
        label_17->setText(QApplication::translate("MainWindow", "IP:", 0));
        label_19->setText(QApplication::translate("MainWindow", "Simulation", 0));
        pushButtonSimulationConnection->setText(QApplication::translate("MainWindow", "undefined", 0));
        lineEditSimulationIP->setText(QApplication::translate("MainWindow", "127.0.0.1", 0));
        lineEditSimulationPort->setText(QApplication::translate("MainWindow", "4545", 0));
        label_20->setText(QApplication::translate("MainWindow", "Port:", 0));
        label_21->setText(QApplication::translate("MainWindow", "IP:", 0));
        label_22->setText(QApplication::translate("MainWindow", "BrainBoard", 0));
        pushButtonBrainBoardConnection->setText(QApplication::translate("MainWindow", "undefined", 0));
        lineEditBrainBoardIP->setText(QApplication::translate("MainWindow", "127.0.0.1", 0));
        lineEditBrainBoardPort->setText(QApplication::translate("MainWindow", "4646", 0));
        dockWidgetTrace->setWindowTitle(QApplication::translate("MainWindow", "Trace", 0));
        dockWidgetSimulationView->setWindowTitle(QApplication::translate("MainWindow", "SimulationView", 0));
        label_23->setText(QApplication::translate("MainWindow", "Data From BrainBoard", 0));
        label_24->setText(QApplication::translate("MainWindow", "Speed (mm/s):", 0));
        label_25->setText(QApplication::translate("MainWindow", "SteeringAngle (deg):", 0));
        labelSpeedFromBrainBoard->setText(QApplication::translate("MainWindow", "undefined", 0));
        labelSteeringAngleFromBrainBoard->setText(QApplication::translate("MainWindow", "undefined", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Data-BrainBoard", 0));
        label_26->setText(QApplication::translate("MainWindow", "Data From Hardware", 0));
        label_27->setText(QApplication::translate("MainWindow", "Speed (mm/s):", 0));
        label_28->setText(QApplication::translate("MainWindow", "SteeringAngle (deg):", 0));
        labelSpeedHardware->setText(QApplication::translate("MainWindow", "undefined", 0));
        labelSteeringAngleHardware->setText(QApplication::translate("MainWindow", "undefined", 0));
        label_29->setText(QApplication::translate("MainWindow", "PWM", 0));
        label_30->setText(QApplication::translate("MainWindow", "Value", 0));
        labelSpeedHardwarePWM->setText(QApplication::translate("MainWindow", "undefined", 0));
        labelSteeringAngleHardwarePWM->setText(QApplication::translate("MainWindow", "undefined", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Data-Hardware", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
