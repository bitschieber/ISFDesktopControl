#ifndef TCPSERVERCONTROLLER_H
#define TCPSERVERCONTROLLER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
//#include "isfdata.h"
#include <cstdint>

class TCPServerController : public QObject
{
    Q_OBJECT
public:
    explicit TCPServerController(QObject *parent = 0);
    void sendData(QByteArray data);
    //DATA_SET_MONITOR_t dataSetInput;
    //DATA_SET_MONITOR_t dataSetOutput;
    
signals:
    
public slots:
    void newConnection();
    void readyRead();

private:
    QTcpServer *server;
    QTcpSocket *socket;
    //char _outbutBuffer[sizeof(DATA_SET_MONITOR_t)];
    //QByteArray _inputData;
    
};

#endif // TCPSERVERCONTROLLER_H
