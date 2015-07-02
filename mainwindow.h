#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ISFCarUc/isfcaruc.h"
#include "HAL/i_isfcarhal.h"
#include "HAL/isfcarhalx86.h"
#include "Netzwerk/TCPClientController.h"
#include <QGraphicsScene>
#include "isfcarthread.h"
#include <QTimer>

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
    void BrainBoardDataReceived(QByteArray data);

    void on_pushButtonBrainBoardConnection_clicked();


    void TimerWaitForISFRunFinished();

private:
    Ui::MainWindow *ui;
    ISFCarHALx86 *_isfCarHAL;
    TCPClientController *_tcpSimulation;
    TCPClientController* _tcpBrainBoard;
    DATA_SET_BRAIN_BOARD_UC_t _dataFromBrainBoard;
    DATA_SET_TO_SIMULATION_t _dataToSimulation;

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
    QImage _simulationViewImage;
    QByteArray _simulationViewImageRAW;
};

#endif // MAINWINDOW_H
