#ifndef SIMULATIONCONNECTIONCONTROLLER_H
#define SIMULATIONCONNECTIONCONTROLLER_H

#include <QObject>
#include "network/tcpclientcontroller.h"
#include "hal/isfdata.h"

class SimulationConnectionController : public QObject
{
    Q_OBJECT

public:
    SimulationConnectionController();
    bool connectToSimulation(QString ip, uint port);
    void sendData(QByteArray data);
    bool isConnected();

    //Simulation Data
    QImage _simulationViewImage;
    QImage* _simulationViewImage2;
    QByteArray _simulationViewImageRAW;
private slots:
    void SimulationDataReceived(QByteArray data);
signals:
    void imageReceived(QImage img);
    void dataReceived(QByteArray data);
private:
    TCPClientController *_tcpSimulation;
    //QByteArray _holeImagePacket;
};

#endif // SIMULATIONCONNECTIONCONTROLLER_H
