#ifndef BRAINBOARDCONTROLLER_H
#define BRAINBOARDCONTROLLER_H

#include <QObject>;
#include "network/tcpclientcontroller.h"
#include "hal/isfdata.h"

class BrainBoardController : public QObject
{
    Q_OBJECT
public:
    BrainBoardController();
    bool connectToCameraDest(QString ip, uint port);
    bool connectToDataHost(QString ip, uint port);
    void sendData(QByteArray data);
    void sendDataToHost(QByteArray data);
    DATA_SET_BRAIN_BOARD_UC_t _dataFromBrainBoard;
private slots:
    void BrainBoardDataReceived(QByteArray data);
    void BrainBoardDataReceivedHost(QByteArray data);
signals:
    void dataReceived();
    void dataHostReceived();
private:
    TCPClientController* _tcpBrainBoardImage;
    TCPClientController* _tcpBrainBoardDataHost;
};

#endif // BRAINBOARDCONTROLLER_H
