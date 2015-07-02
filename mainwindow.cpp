#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _connectedToSimulation = false;
    _connectedToBrainBoard = false;

    _isfCarHAL = new ISFCarHALx86();
    //_isfCarThread = new ISFCarThread(_isfCarHAL);
    //_isfCarThread->run();

    //QThread thread;
    _isfCarThread = new ISFCarThread(_isfCarHAL);
    _isfCarThread->start();
    //_isfCarThread->moveToThread(&thread);
    //thread.start();

    _currentSimulationState = SIMUSTATE_IDLE;

    ui->graphicsViewSimulationView->setScene(&_simulationViewScene);

    _timerWaitForISFRun.setInterval(2);
    connect(&_timerWaitForISFRun,&QTimer::timeout,this,&MainWindow::TimerWaitForISFRunFinished);

    updateGUIData();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::updateGUIData(void)
{
    updateGUIDataLEDs();
}

/*updateGUIDataLEDs
 * LEDs je nach GPIO Zustand anzeigen
 *
 * */
void MainWindow::updateGUIDataLEDs(void)
{
    if(this->_isfCarHAL->getGPIOState(GPIO_PIN01) == GPIO_SET){
        ui->frameLED1->setStyleSheet("background-color:yellow;");
    }
    else{
        ui->frameLED1->setStyleSheet("background-color:gray;");
    }

    if(this->_isfCarHAL->getGPIOState(GPIO_PIN02) == GPIO_SET){
        ui->frameLED2->setStyleSheet("background-color:yellow;");
    }
    else{
        ui->frameLED2->setStyleSheet("background-color:gray;");
    }

    if(this->_isfCarHAL->getGPIOState(GPIO_PIN03) == GPIO_SET){
        ui->frameLED3->setStyleSheet("background-color:yellow;");
    }
    else{
        ui->frameLED3->setStyleSheet("background-color:gray;");
    }

    if(this->_isfCarHAL->getGPIOState(GPIO_PIN04) == GPIO_SET){
        ui->frameLED4->setStyleSheet("background-color:yellow;");
    }
    else{
        ui->frameLED4->setStyleSheet("background-color:gray;");
    }

    if(this->_isfCarHAL->getGPIOState(GPIO_PIN05) == GPIO_SET){
        ui->frameLED5->setStyleSheet("background-color:yellow;");
    }
    else{
        ui->frameLED5->setStyleSheet("background-color:gray;");
    }

    if(this->_isfCarHAL->getGPIOState(GPIO_PIN06) == GPIO_SET){
        ui->frameLED6->setStyleSheet("background-color:yellow;");
    }
    else{
        ui->frameLED6->setStyleSheet("background-color:gray;");
    }

    if(this->_isfCarHAL->getGPIOState(GPIO_PIN07) == GPIO_SET){
        ui->frameLED7->setStyleSheet("background-color:yellow;");
    }
    else{
        ui->frameLED7->setStyleSheet("background-color:gray;");
    }

    if(this->_isfCarHAL->getGPIOState(GPIO_PIN08) == GPIO_SET){
        ui->frameLED8->setStyleSheet("background-color:yellow;");
    }
    else{
        ui->frameLED8->setStyleSheet("background-color:gray;");
    }
}



void MainWindow::on_pushButtonSimulationConnection_clicked()
{
    _tcpSimulation = new TCPClientController(this,ui->lineEditSimulationIP->text(),ui->lineEditSimulationPort->text().toUInt());
    connect(_tcpSimulation, SIGNAL(valueChanged(QByteArray)), this, SLOT(SimulationDataReceived(QByteArray)));

    _connectedToSimulation = true;

    _dataToSimulation.command = SIMUCOM_SEND_IMAGE;


    QByteArray sendData;

    sendData.resize(sizeof(DATA_SET_TO_SIMULATION_t));
    memcpy(sendData.data(),&_dataToSimulation,sizeof(DATA_SET_TO_SIMULATION_t));
    _tcpSimulation->sendData(sendData);

    //connect(ui->btnConnectSimulationCamera, SIGNAL(clicked()),this, SLOT(SimulationCameraClickedSlot()));
}


void MainWindow::on_pushButtonBrainBoardConnection_clicked()
{
    _tcpBrainBoard = new TCPClientController(this,ui->lineEditBrainBoardIP->text(),ui->lineEditBrainBoardPort->text().toUInt());
    connect(_tcpBrainBoard, SIGNAL(valueChanged(QByteArray)), this, SLOT(BrainBoardDataReceived(QByteArray)));

    _connectedToBrainBoard = true;

}

/*Simulation Steps
 *
 * */


/*
 * Request Image From Simulation
 */
void MainWindow::getImageFromSimulation(void)
{
    _dataToSimulation.command = SIMUCOM_SEND_IMAGE;
    QByteArray sendData;

    sendData.resize(sizeof(DATA_SET_TO_SIMULATION_t));
    memcpy(sendData.data(),&_dataToSimulation,sizeof(DATA_SET_TO_SIMULATION_t));
    _tcpSimulation->sendData(sendData);
}
void MainWindow::SimulationDataReceived(QByteArray data)
{
    if(data.length()>1000){
        _simulationViewImageRAW = data;
        _simulationViewImage = QImage::fromData(_simulationViewImageRAW,"JPEG");//the second param is format name
        _currentSimulationState = SIMUSTATE_IDLE;
        _simulationViewScene.addPixmap(QPixmap().fromImage(_simulationViewImage));
        ui->graphicsViewSimulationView->show();
    }
    else{
            getImageFromSimulation();
    }
}


/*
 * IDLE Wait for Step
 */
/*
 * Ne Step Button Pressed
 */
void MainWindow::on_pushButtonSimulationStepForward_clicked()
{
    if(_connectedToSimulation == true && _connectedToBrainBoard == true){ //Wenn zu beiden System verbunden wurde
        sendImageToBrainBoard();
    }
    else if(_connectedToSimulation == false){//Wenn die Verbidnung zur Simulation nicht besteht
        return;
    }
    else{//Wenn die Verbindung zum BrainBoard nicht besteht
        return;
    }
}

/*
 * Send Image to BrainBaord
 */
void MainWindow::sendImageToBrainBoard(void)
{
    _currentSimulationState = SIMUSTATE_BRAINBOARD_SENDIMAGE;
    _tcpBrainBoard->sendData(_simulationViewImageRAW);
}

/*
 * Receive Data(Speed, SteeringAngle) from BrainBoard
 */
void MainWindow::BrainBoardDataReceived(QByteArray data)
{
    memcpy(&_dataFromBrainBoard,data,sizeof(DATA_SET_BRAIN_BOARD_UC_t));
    //_simulationViewImage = QImage::fromData(data,"JPEG");//the second param is format name
    if(_currentSimulationState == SIMUSTATE_BRAINBOARD_SENDIMAGE)
    {
        _currentSimulationState = SIMUSTATE_BRAINBOARD_RECEIVED;

        ui->labelSpeedFromBrainBoard->setText(QString::number(_dataFromBrainBoard.speed_mms));
        ui->labelSteeringAngleFromBrainBoard->setText(QString::number(_dataFromBrainBoard.steering_angle));

        manipulateX68HAL();

        _currentSimulationState = SIMUSTATE_WAIT_FOR_ISF_RUN;
        _timerWaitForISFRun.start();

    }
    else{
        //Error
    }
}

/*
 * Send Image to BrainBaord
 */
void MainWindow::manipulateX68HAL(void)
{
    _isfCarHAL->setDesiredSpeed(_dataFromBrainBoard.speed_mms);
    _isfCarHAL->setDesiredSteeringAngle(_dataFromBrainBoard.steering_angle);
    _isfCarHAL->addUsTime(ui->labelSimulationTimeStep->text().toUInt());
}


/*
 * Waitingtime for HAL ISFCar Calculation finished
 */
void MainWindow::TimerWaitForISFRunFinished(){
    _timerWaitForISFRun.stop();

    if(_currentSimulationState == SIMUSTATE_WAIT_FOR_ISF_RUN){
        _dataToSimulation.command = SIMUCOM_UPDATE_DATA;
        _dataToSimulation.speed_mms = _isfCarHAL->getCurrentSpeed();
        _dataToSimulation.steering_angle = _isfCarHAL->getCurrentSteeringAngle();
        _dataToSimulation.timediff = ui->labelSimulationTimeStep->text().toUInt();
        QByteArray sendData;

        sendData.resize(sizeof(DATA_SET_TO_SIMULATION_t));
        memcpy(sendData.data(),&_dataToSimulation,sizeof(DATA_SET_TO_SIMULATION_t));
        _tcpSimulation->sendData(sendData);

        _currentSimulationState = SIMUSTATE_SIMULATION_UPDATE_DATA;
    }
}

