#include "monitorwindow.h"
#include "ui_monitorwindow.h"

MonitorWindow::MonitorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MonitorWindow)
{
    ui->setupUi(this);
}

MonitorWindow::~MonitorWindow()
{
    delete ui;
}

void MonitorWindow::on_pushButtonBrainBoardConnection_clicked()
{
    _brainBoardClient = new TCPClientController(this,ui->lineEditBrainBoardIP->text(),ui->lineEditBrainBoardPort->text().toUInt());
    connect(_brainBoardClient, SIGNAL(valueChanged(QByteArray)), this, SLOT(BrainBoardDataReceived(QByteArray)));
}

void MonitorWindow::BrainBoardDataReceived(QByteArray data)
{
    memcpy(&_dataSet,data,sizeof(DATA_SET_MONITOR_t));
}
