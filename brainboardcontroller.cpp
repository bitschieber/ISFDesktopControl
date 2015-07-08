#include "brainboardcontroller.h"

BrainBoardController::BrainBoardController()
{

}

bool BrainBoardController::connectToCameraDest(QString ip, uint port)
{
    _tcpBrainBoardImage = new TCPClientController(this,ip,port);
    connect(_tcpBrainBoardImage, SIGNAL(valueChanged(QByteArray)), this, SLOT(BrainBoardDataReceived(QByteArray)));

    return true;
}

bool BrainBoardController::connectToDataHost(QString ip, uint port)
{
    _tcpBrainBoardDataHost = new TCPClientController(this,ip,port);
    connect(_tcpBrainBoardDataHost, SIGNAL(valueChanged(QByteArray)), this, SLOT(BrainBoardDataReceivedHost(QByteArray)));

    return true;
}

void BrainBoardController::sendData(QByteArray data){
    _tcpBrainBoardImage->sendData(data);
}

void BrainBoardController::sendDataToHost(QByteArray data){
    _tcpBrainBoardDataHost->sendData(data);
}

void BrainBoardController::BrainBoardDataReceived(QByteArray data)
{
    int i = 0;
    //memcpy(&_dataFromBrainBoard,data,sizeof(DATA_SET_BRAIN_BOARD_UC_t));
    //emit dataReceived();
}

void BrainBoardController::BrainBoardDataReceivedHost(QByteArray data)
{
    memcpy(&_dataFromBrainBoard,data,sizeof(DATA_SET_BRAIN_BOARD_UC_t));
    //_simulationViewImage = QImage::fromData(data,"JPEG");//the second param is format name
    //emit dataHostReceived();

    dataReceived();
}

