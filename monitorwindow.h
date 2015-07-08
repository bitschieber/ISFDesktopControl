#ifndef MONITORWINDOW_H
#define MONITORWINDOW_H

#include <QMainWindow>
#include "network/tcpclientcontroller.h"
#include "hal/isfdata.h"

namespace Ui {
class MonitorWindow;
}

class MonitorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MonitorWindow(QWidget *parent = 0);
    ~MonitorWindow();

private slots:
    void on_pushButtonBrainBoardConnection_clicked();
    void BrainBoardDataReceived(QByteArray data);

private:
    Ui::MonitorWindow *ui;
    TCPClientController* _brainBoardClient;
    DATA_SET_MONITOR_t _dataSet;
};

#endif // MONITORWINDOW_H
