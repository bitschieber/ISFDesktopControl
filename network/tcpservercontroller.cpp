#include "tcpservercontroller.h"

TCPServerController::TCPServerController(QObject *parent) : QObject(parent){
//TCPServerController::TCPServerController(quint16 port){
    server = new QTcpServer(this);
    socket = 0;

    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any, 25002))
    //if(!server->listen(QHostAddress::Any, port))
    //if(!server->listen("192.168.178.80", 25000))
    {
        qDebug() << "Server could not start!";
    }
    else
    {
        qDebug() << "Server started!";
    }
}

void TCPServerController::newConnection()
{
    qDebug() << "New client connected!";
    socket = server->nextPendingConnection();
    connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));

    //socket->write("hello client");
    //socket->flush();

    //socket->waitForBytesWritten(3000);

    //socket->close();
}

void TCPServerController::readyRead()
{
    QByteArray data = socket->readAll();

    /*
    //console->putData(data);
    for(int i = 0; i<data.count();i++){
        _inputData.append(data.at(i));
    }

    int i = sizeof(DATA_SET_MONITOR_t);

    if(_inputData.count()>=sizeof(DATA_SET_MONITOR_t)){
        //_inputBufferWritePos = _inputBufferWritePos-sizeof(DATA_SET_MONITOR_t);

        memcpy(&dataSetInput,_inputData.data(),sizeof(DATA_SET_MONITOR_t));

        //QString my_formatted_string = QString("Lenkwinkeln:%1, Speed:%2").arg(QString::number(dataSetInput.lenkwinkel),QString::number(dataSetInput.speed));
        _inputData.remove(0,sizeof(DATA_SET_MONITOR_t));


        //console->putData(my_formatted_string.toLocal8Bit());
    }
    */

    /*
    //qDebug() << "reading...";
    DATA_SET_MONITOR_t dataSet;
    // read the data from the socket
    int size = sizeof(DATA_SET_MONITOR_t);
    QByteArray data =  socket->readAll();
    if(data.count()>=sizeof(DATA_SET_MONITOR_t)){
        memcpy(&dataSet,data.data(),sizeof(DATA_SET_MONITOR_t));

        //memcpy(&data2,&dataSet,sizeof(DATA_SET_MONITOR_t));
    }
    */
}

void TCPServerController::sendData(QByteArray data){
    if(socket!=0){
        //memcpy(_outbutBuffer,&data,data.length());
        socket->write(data,data.length());
    }
}
