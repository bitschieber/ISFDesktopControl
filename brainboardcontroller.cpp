#include "brainboardcontroller.h"


QByteArray buffer;

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
    int i = data.length();

    buffer.resize(data.length()+4);
    memcpy(buffer.data(),&i,4);
    memcpy(buffer.data()+4,data.data(),data.length());

    /*
    QDataStream out(buffer.data_ptr());
    out << int(0); // placeholder for info about bytes for the binary data
    out << data; // binary representation of image (as PNG file)

    out.device()->seek(0); // go back to start
    out << buffer.size(); // info about bytes for the size value (int) and binary image data (image)
    */
    /*
    if (_pSocket->write(buffer) < buffer.size()) {
    qWarning("transmit error!");
    }
    */

    _tcpBrainBoardImage->sendData(buffer);
}

void BrainBoardController::sendDataToHost(QByteArray data){
    _tcpBrainBoardDataHost->sendData(data);
}

void BrainBoardController::BrainBoardDataReceived(QByteArray data)
{
    //int i = 0;
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

