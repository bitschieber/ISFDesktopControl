#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
}

StartWindow::~StartWindow()
{
    delete ui;
}


void StartWindow::on_pushButtonSimulationMode_clicked()
{
    mMyNewWindow = new MainWindow();
    mMyNewWindow->show();
}

void StartWindow::on_pushButtonMonitorMode_clicked()
{
    _monitorWindow = new MonitorWindow();
    _monitorWindow->show();
}
