#include "mainwindow.h"
#include "ui_mainwindow.h"

uint32_t plotDataStep = 0;
TIME_MESSUREMENT_STUCT _timeISFRunMessure;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _continuousPlay = false;
    _currentTimems = 0;
    _lastImageUpdateTime = 0;

    _simuConController = new SimulationConnectionController();
    connect(_simuConController, SIGNAL(imageReceived(QImage)), this, SLOT(SimulationImageReceived(QImage)));
    connect(_simuConController, SIGNAL(dataReceived(QByteArray)), this, SLOT(SimulationDataReceived(QByteArray)));

    _brainBoardController = new BrainBoardController();
    connect(_brainBoardController, SIGNAL(dataReceived()), this, SLOT(BrainBoardDataReceived()));


    _connectedToSimulation = false;
    _connectedToBrainBoard = false;

    _isfCarHAL = new ISFCarHALx86();
    //connect(tempHal, SIGNAL(dataToBrainBoard(QByteArray data)), this, SLOT(halDataToBrainBoardHost(QByteArray data)));
    connect(_isfCarHAL, &ISFCarHALx86::sigDataToBrainBoard, this, &MainWindow::halDataToBrainBoardHost);
    connect(_isfCarHAL, &ISFCarHALx86::sigDebugLog, this, &MainWindow::halDebugLog);
    //_isfCarHAL = tempHal;
    //_isfCarThread = new ISFCarThread(_isfCarHAL);
    //_isfCarThread->run();

    //QThread thread;
    _isfCarThread = 0;
    _isfCarThread = new ISFCarThread(_isfCarHAL);
    _isfCarThread->start();
    //_isfCarThread->moveToThread(&thread);
    //thread.start();

    _currentSimulationState = SIMUSTATE_IDLE;
    this->simulationStateMachine(SIMSIGNAL_UNKNOWN);

    ui->graphicsViewSimulationView->setScene(&_simulationViewScene);
    _simuImagePixMap= new QGraphicsPixmapItem();
    _simulationViewScene.addItem(_simuImagePixMap);

    _timerWaitForISFRun.setInterval(2);
    connect(&_timerWaitForISFRun,&QTimer::timeout,this,&MainWindow::TimerWaitForISFRunFinished);


    //Plots
    ui->plotPWM->addGraph();
    ui->plotPWM->addGraph();
    ui->plotPWM->yAxis->setRange(900,2100);


    ui->plotSpeed->addGraph();
    ui->plotSpeed->addGraph();
    ui->plotSpeed->yAxis->setRange(-4200,4200);

    ui->plotSteeringAngle->addGraph();
    ui->plotSteeringAngle->addGraph();
    ui->plotSteeringAngle->yAxis->setRange(-22,22);
    //ui->plotPWM->yAxis->setRange(1000,2000);
    //ui->plotPWM->xAxis->setRange(0,10);
    //ui->plotPWM->
    updateGUIData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this," APP_NAME",
                                                                tr("Are you sure?\n"),
                                                                QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {

        _isfCarThread->stopISFCar();
        delete _isfCarThread;
        delete _isfCarHAL;
        delete _simuConController;
        delete _brainBoardController;

        event->accept();
    }
}


void MainWindow::updateGUIData(void)
{
    updateGUIDataLEDs();

    ui->labelSpeedHardware->setText(QString::number(this->_isfCarHAL->getCurrentSpeed()));
    ui->labelSteeringAngleHardware->setText(QString::number(this->_isfCarHAL->getCurrentSteeringAngle()));
    ui->labelSpeedHardwarePWM->setText((QString::number(this->_isfCarHAL->getMotorPWM())));
    ui->labelSteeringAngleHardwarePWM->setText((QString::number(this->_isfCarHAL->getSteeringAnglePWM())));
    ui->labelSimulationCurrentTime->setText(QString::number(this->_currentTimems));
}

void MainWindow::simulationStepDone(void)
{


    QCustomPlot *plotPWM = ui->plotPWM;
    if(plotDataStep>=100){
        plotPWM->graph(0)->removeData(plotDataStep-100);
        plotPWM->graph(1)->removeData(plotDataStep-100);
    }
    plotPWM->graph(0)->addData(plotDataStep,this->_isfCarHAL->getMotorPWM());
    plotPWM->graph(1)->addData(plotDataStep,this->_isfCarHAL->getSteeringAnglePWM());
    plotPWM->xAxis->rescale();
    plotPWM->replot();

    QCustomPlot *plotSpeed = ui->plotSpeed;
    if(plotDataStep>=100){
        plotSpeed->graph(0)->removeData(plotDataStep-100);
        plotSpeed->graph(1)->removeData(plotDataStep-100);
    }
    plotSpeed->graph(0)->addData(plotDataStep,this->_isfCarHAL->getCurrentSpeed());
    plotSpeed->graph(1)->addData(plotDataStep,this->_isfCarHAL->getDesiredSpeed());
    plotSpeed->xAxis->rescale();
    plotSpeed->replot();

    QCustomPlot *plotSteering = ui->plotSteeringAngle;
    if(plotDataStep>=100){
        plotSteering->graph(0)->removeData(plotDataStep-100);
        plotSteering->graph(1)->removeData(plotDataStep-100);
    }
    plotSteering->graph(0)->addData(plotDataStep,this->_isfCarHAL->getCurrentSteeringAngle());
    plotSteering->graph(1)->addData(plotDataStep,this->_isfCarHAL->getDesiredSteeringAngle());
    plotSteering->xAxis->rescale();
    plotSteering->replot();




    plotDataStep++;

    _dataToBrainBoardHost.speed_mms = this->_isfCarHAL->getCurrentSpeed();
    _dataToBrainBoardHost.speed_pwm = this->_isfCarHAL->getMotorPWM();
    _dataToBrainBoardHost.steering_angle_pwm = this->_isfCarHAL->getSteeringAnglePWM();
    _dataToBrainBoardHost.steering_angle = this->_isfCarHAL->getCurrentSteeringAngle();

    qDebug() << "ISFRun Duration:" << _timeISFRunMessure.diffMs;


    /*
    if(_connectedToSimulation == true && _connectedToBrainBoard == true)
    {
        QByteArray sendData;
        sendData.resize(sizeof(DATA_SET_UC_BRAIN_BOARD_t));
        memcpy(sendData.data(),&_dataToBrainBoardHost,sizeof(DATA_SET_UC_BRAIN_BOARD_t));
        _brainBoardController->sendDataToHost(sendData);
    }
    */

    updateGUIData();

    if(_continuousPlay==true)
        nextStep();
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

void MainWindow::halDataToBrainBoardHost(QByteArray data)
{
    if(_connectedToSimulation == true && _connectedToBrainBoard == true)
    {
        _brainBoardController->sendDataToHost(data);
    }
}

void MainWindow::halDebugLog(QString str)
{
    ui->labelDebugLog->append(str);
}

void MainWindow::on_pushButtonSimulationConnection_clicked()
{
    //_tcpSimulation = new TCPClientController(this,ui->lineEditSimulationIP->text(),ui->lineEditSimulationPort->text().toUInt());
    //connect(_tcpSimulation, SIGNAL(valueChanged(QByteArray)), this, SLOT(SimulationDataReceived(QByteArray)));

    if(_simuConController->connectToSimulation(ui->lineEditSimulationIP->text(),ui->lineEditSimulationPort->text().toUInt()))
    {
        _connectedToSimulation = true;

        _dataToSimulation.command = SIMUCOM_SEND_IMAGE;


        QByteArray sendData;

        sendData.resize(sizeof(DATA_SET_TO_SIMULATION_t));
        memcpy(sendData.data(),&_dataToSimulation,sizeof(DATA_SET_TO_SIMULATION_t));
        _simuConController->sendData(sendData);
    }

    //connect(ui->btnConnectSimulationCamera, SIGNAL(clicked()),this, SLOT(SimulationCameraClickedSlot()));
}


void MainWindow::on_pushButtonBrainBoardConnection_clicked()
{

    if(_brainBoardController->connectToCameraDest(ui->lineEditBrainBoardIP->text(),ui->lineEditBrainBoardPort->text().toUInt()))
    {
        if(_brainBoardController->connectToDataHost(ui->lineEditBrainBoardIP->text(),4747))
        {
            _connectedToBrainBoard = true;
        }
    }
    //_tcpBrainBoardImage = new TCPClientController(this,ui->lineEditBrainBoardIP->text(),ui->lineEditBrainBoardPort->text().toUInt());
    //connect(_tcpBrainBoardImage, SIGNAL(dataReceived(void)), this, SLOT(BrainBoardDataReceived(void)));

    //_tcpBrainBoardImage = new TCPClientController(this,ui->lineEditBrainBoardIP->text(),ui->lineEditBrainBoardPort->text().toUInt());
    //connect(_tcpBrainBoardImage, SIGNAL(valueChanged(QByteArray)), this, SLOT(BrainBoardDataReceived(QByteArray)));



}


void MainWindow::SimulationImageReceived(QImage img)
{
    _currentSimulationState = SIMUSTATE_IDLE;
    simulationStateMachine(SIMSIGNAL_UNKNOWN);

    QPixmap lpixmap = QPixmap::fromImage(img);
    _simuImagePixMap->setPixmap(lpixmap);

    //_simulationViewScene.addPixmap(QPixmap().fromImage(img));
    //_simulationViewScene.rem
    ui->graphicsViewSimulationView->show();
    //_simuConController->freeImage();
    simulationStepDone();
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
    _simuConController->sendData(sendData);
}
void MainWindow::SimulationDataReceived(QByteArray data)
{
}


/*
 * IDLE Wait for Step
 */
/*
 * Ne Step Button Pressed
 */
void MainWindow::on_pushButtonSimulationStepForward_clicked()
{
    nextStep();
}

void MainWindow::nextStep(void){
    if(_connectedToSimulation == true && _connectedToBrainBoard == true){ //Wenn zu beiden System verbunden wurde

        if(_currentTimems-_lastImageUpdateTime >= ui->labelSimulationImageUpdateTime->text().toUInt())
        {
            _currentSimulationState = SIMUSTATE_BRAINBOARD_SENDIMAGE;
            this->simulationStateMachine(SIMSIGNAL_UNKNOWN);
            _lastImageUpdateTime = _currentTimems;
            sendImageToBrainBoard();
        }
        else{
            _currentSimulationState = SIMUSTATE_BRAINBOARD_SENDIMAGE;
            this->simulationStateMachine(SIMSIGNAL_UNKNOWN);
            BrainBoardDataReceived();
        }

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
    this->simulationStateMachine(SIMSIGNAL_UNKNOWN);
    _brainBoardController->sendData(_simuConController->_simulationViewImageRAW);
}

/*
 * Receive Data(Speed, SteeringAngle) from BrainBoard
 */
void MainWindow::BrainBoardDataReceived()
//void MainWindow::BrainBoardDataReceived(QByteArray data)
{
    if(_currentSimulationState == SIMUSTATE_BRAINBOARD_SENDIMAGE)
    {
        _currentSimulationState = SIMUSTATE_BRAINBOARD_RECEIVED;
        this->simulationStateMachine(SIMSIGNAL_UNKNOWN);

        ui->labelSpeedFromBrainBoard->setText(QString::number(_brainBoardController->_dataFromBrainBoard.speed_mms));
        ui->labelSteeringAngleFromBrainBoard->setText(QString::number(_brainBoardController->_dataFromBrainBoard.steering_angle));

        manipulateX68HAL();

        this->simulationStateMachine(SIMSIGNAL_START_ISFRUN);
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
    _isfCarHAL->setDesiredSpeed(_brainBoardController->_dataFromBrainBoard.speed_mms);
    _isfCarHAL->setDesiredSteeringAngle(_brainBoardController->_dataFromBrainBoard.steering_angle);
    _isfCarHAL->addUsTime(ui->labelSimulationTimeStep->text().toUInt());
    _currentTimems = _isfCarHAL->getUsTime();
}


/*
 * Waitingtime for HAL ISFCar Calculation finished
 */
void MainWindow::TimerWaitForISFRunFinished(){
    _timerWaitForISFRun.stop();
    simulationStateMachine(SIMSIGNAL_ISFRUN_TIMER_FINISHED);
    /*
    if(_currentSimulationState == SIMUSTATE_WAIT_FOR_ISF_RUN){
        _dataToSimulation.command = SIMUCOM_UPDATE_DATA;
        _dataToSimulation.speed_mms = _isfCarHAL->getCurrentSpeed();
        _dataToSimulation.steering_angle = _isfCarHAL->getCurrentSteeringAngle();
        _dataToSimulation.timediff = ui->labelSimulationTimeStep->text().toUInt();
        _dataToSimulation.gpio_state = _isfCarHAL->getGPIOs();

        QByteArray sendData;

        sendData.resize(sizeof(DATA_SET_TO_SIMULATION_t));
        memcpy(sendData.data(),&_dataToSimulation,sizeof(DATA_SET_TO_SIMULATION_t));
        _simuConController->sendData(sendData);

        simulationStateMachine(SIMSIGNAL_ISFRUN_TIMER_FINISHED);
        //_currentSimulationState = SIMUSTATE_SIMULATION_UPDATE_DATA;
    }
    */
}


void MainWindow::on_pushButtonSimulationPlay_clicked()
{
    this->_continuousPlay = !this->_continuousPlay;
}

void MainWindow::on_cbRCOnOff_clicked(bool checked)
{
    this->_isfCarHAL->manipulatePWMInValid(checked);
}

void MainWindow::on_cbUserButton01_clicked(bool checked)
{
    if(checked==true)
    {
        this->_isfCarHAL->manipulateGPIOIn(GPIO_IN_USERBUTTON_01,GPIO_SET);
    }
    else
    {
        this->_isfCarHAL->manipulateGPIOIn(GPIO_IN_USERBUTTON_01,GPIO_RESET);
    }
}

void MainWindow::on_cbUserButton02_clicked(bool checked)
{
    if(checked==true)
    {
        this->_isfCarHAL->manipulateGPIOIn(GPIO_IN_USERBUTTON_02,GPIO_SET);
    }
    else
    {
        this->_isfCarHAL->manipulateGPIOIn(GPIO_IN_USERBUTTON_02,GPIO_RESET);
    }
}

void MainWindow::simulationStateMachine(SIMULATION_SIGNAL signal)
{
    if(_currentSimulationState == SIMUSTATE_SIMULATION_UPDATE_DATA)
    {

    }
    else if(_currentSimulationState == SIMUSTATE_IDLE)
    {

    }
    else if(_currentSimulationState == SIMUSTATE_BRAINBOARD_SENDIMAGE)
    {
    }
    else if(_currentSimulationState == SIMUSTATE_BRAINBOARD_RECEIVED)
    {
        if(signal == SIMSIGNAL_START_ISFRUN)
        {
            _timeISFRunMessure.lastTime.start();
        }
    }
    else if(_currentSimulationState == SIMUSTATE_WAIT_FOR_ISF_RUN)
    {
        if(signal == SIMSIGNAL_ISFRUN_TIMER_FINISHED)
        {
            _timeISFRunMessure.diffMs = _timeISFRunMessure.lastTime.elapsed();

            _dataToSimulation.command = SIMUCOM_UPDATE_DATA;
            _dataToSimulation.speed_mms = _isfCarHAL->getCurrentSpeed();
            _dataToSimulation.steering_angle = _isfCarHAL->getCurrentSteeringAngle();
            _dataToSimulation.timediff = ui->labelSimulationTimeStep->text().toUInt();
            _dataToSimulation.gpio_state = _isfCarHAL->getGPIOs();

            QByteArray sendData;

            sendData.resize(sizeof(DATA_SET_TO_SIMULATION_t));
            memcpy(sendData.data(),&_dataToSimulation,sizeof(DATA_SET_TO_SIMULATION_t));
            _simuConController->sendData(sendData);

            _currentSimulationState = SIMUSTATE_SIMULATION_UPDATE_DATA;
        }
    }

    //_currentSimulationState = state;
}

void MainWindow::on_sliderADC1_valueChanged(int value)
{
    ui->labelADC1Val->setText(QString::number(value)+ " mV");
    this->_isfCarHAL->manipulateADC(ADC_SRC::ADC_SRC_1, value);
}
