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

    //Simulation Data
    QImage _simulationViewImage;
    QByteArray _simulationViewImageRAW;
private slots:
    void SimulationDataReceived(QByteArray data);
signals:
    void imageReceived(void);
private:
    TCPClientController *_tcpSimulation;
};

#endif // SIMULATIONCONNECTIONCONTROLLER_H
