#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "isfcaruc/isfcaruc.h"
#include "hal/i_isfcarhal.h"
#include "hal/isfcarhalx86.h"
#include "network/tcpclientcontroller.h"
#include <QGraphicsScene>
#include "isfcarthread.h"
#include <QTimer>

#include "simulationconnectioncontroller.h"
#include "brainboardcontroller.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    enum SIMULATION_STATE{SIMUSTATE_IDLE, SIMUSTATE_REQUEST_SIMU_VIEW, SIMUSTATE_RECEIVED_SIMU_VIEW, SIMUSTATE_SIMULATION_UPDATE_DATA, SIMUSTATE_WAIT_FOR_ISF_RUN, SIMUSTATE_BRAINBOARD_SENDIMAGE, SIMUSTATE_BRAINBOARD_RECEIVED, SIMUSTATE_STEP_DONE};

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonSimulationStepForward_clicked();

    void on_pushButtonSimulationConnection_clicked();
    void SimulationDataReceived(QByteArray data);
    void SimulationImageReceived(void);
    //void BrainBoardDataReceived(QByteArray data);
    void BrainBoardDataReceived();
    void halDataToBrainBoardHost(QByteArray data);
    void halDebugLog(QString str);

    void on_pushButtonBrainBoardConnection_clicked();


    void TimerWaitForISFRunFinished();

    void on_pushButtonSimulationPlay_clicked();

    void on_cbRCOnOff_clicked(bool checked);

    void on_cbUserButton01_clicked(bool checked);

    void on_cbUserButton02_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    void closeEvent (QCloseEvent *event);
    ISFCarHALx86 *_isfCarHAL;
    uint32_t _currentTimems;
    uint32_t _lastImageUpdateTime;
    bool _continuousPlay;
    //TCPClientController *_tcpSimulation;
    //TCPClientController* _tcpBrainBoardData;
    //DATA_SET_BRAIN_BOARD_UC_t _dataFromBrainBoard;
    DATA_SET_TO_SIMULATION_t _dataToSimulation;
    DATA_SET_UC_BRAIN_BOARD_t _dataToBrainBoardHost;

    void simulationStepDone(void);
    void nextStep(void);
    void updateGUIData(void);
    void updateGUIDataLEDs(void);
    void getImageFromSimulation(void);

    QTimer _timerWaitForISFRun;
    QGraphicsScene _simulationViewScene;

    //Simulation
    void sendImageToBrainBoard(void);
    void manipulateX68HAL(void);


    ISFCarThread *_isfCarThread;
    SIMULATION_STATE _currentSimulationState;
    bool _connectedToSimulation;
    bool _connectedToBrainBoard;
    //QImage _simulationViewImage;
    //QByteArray _simulationViewImageRAW;

    SimulationConnectionController* _simuConController;
    BrainBoardController* _brainBoardController;
};

#endif // MAINWINDOW_H
