#include "monitorwindow.h"
#include "ui_monitorwindow.h"
#include <QDebug>

MonitorWindow::MonitorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MonitorWindow)
{
    ui->setupUi(this);
    ui->plotSpeed_BB->addGraph();
    ui->plotSpeed_BB->yAxis->setRange(0, 4000);
    ui->plotSpeed_BB->xAxis->setLabel("tick");
    ui->plotSpeed_BB->yAxis->setLabel("time (ms)");
    ui->plotSpeed_BB->legend->setVisible(true);
    ui->plotSpeed_BB->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft);


    ui->plotSteeringAngle_BB->addGraph();
    ui->plotSteeringAngle_BB->yAxis->setRange(-20, 20);
    ui->plotSteeringAngle_BB->xAxis->setLabel("tick");
    ui->plotSteeringAngle_BB->yAxis->setLabel("time (ms)");
    ui->plotSteeringAngle_BB->legend->setVisible(true);
    ui->plotSteeringAngle_BB->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft);

    ui->plotMouseSensor_BB->addGraph();
    ui->plotMouseSensor_BB->addGraph();
    ui->plotMouseSensor_BB->yAxis->setRange(0, 200);
    ui->plotMouseSensor_BB->xAxis->setLabel("tick");
    ui->plotMouseSensor_BB->yAxis->setLabel("time (ms)");
    ui->plotMouseSensor_BB->legend->setVisible(true);
    ui->plotMouseSensor_BB->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft);


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
    memcpy(&_dataSet,data,sizeof(DATA_SET_BRAIN_BOARD_UC_t));

    if(_dataSet.start_sequence == START_SEQUNCE && _dataSet.end_sequence==END_SEQUNCE)
    {
        ui->labelSpeedHardware_2->setText(QString::number(_dataSet.speed_mms));

        int count = ui->plotSpeed_BB->graph(0)->data()->count();
            ui->plotSpeed_BB->graph(0)->addData(count, _dataSet.speed_mms);
            ui->plotSpeed_BB->xAxis->setRangeLower(std::max(0, count-200));
            ui->plotSpeed_BB->xAxis->setRangeUpper(count);
            ui->plotSpeed_BB->replot();



        ui->labelSteeringAngleHardware_2->setText(QString::number(_dataSet.steering_angle));
        count = ui->plotSteeringAngle_BB->graph(0)->data()->count();
                ui->plotSteeringAngle_BB->graph(0)->addData(count, _dataSet.steering_angle);
                ui->plotSteeringAngle_BB->xAxis->setRangeLower(std::max(0, count-200));
                ui->plotSteeringAngle_BB->xAxis->setRangeUpper(count);
                ui->plotSteeringAngle_BB->replot();

                /*
        ui->labelMouseSensorDx_2->setText(QString::number(_dataSet.mouse_sensor_dx));
        ui->labelMouseSensorDy_2->setText(QString::number(_dataSet.mouse_sensor_dy));
        count = ui->plotMouseSensor_BB->graph(0)->data()->count();
                ui->plotMouseSensor_BB->graph(0)->addData(count, _dataSet.mouse_sensor_dx);
                ui->plotMouseSensor_BB->graph(1)->addData(count, _dataSet.mouse_sensor_dy);
                ui->plotMouseSensor_BB->xAxis->setRangeLower(std::max(0, count-200));
                ui->plotMouseSensor_BB->xAxis->setRangeUpper(count);
                ui->plotMouseSensor_BB->replot();
*/
        updateGUIDataLEDs(_dataSet.gpio_state);
    }
    else
    {
        qDebug() << "Error" ;
    }
}

/*updateGUIDataLEDs
 * LEDs je nach GPIO Zustand anzeigen
 *
 * */
void MonitorWindow::updateGUIDataLEDs(uint32_t gpio_state)
{


    if(((gpio_state >> 0) & 1)==1)
    {
        ui->frameLED1->setStyleSheet("background-color:yellow;");
    }
    else{
        ui->frameLED1->setStyleSheet("background-color:gray;");
    }

    if(((gpio_state >> 1) & 1)==1){
        ui->frameLED2->setStyleSheet("background-color:yellow;");
    }
    else{
        ui->frameLED2->setStyleSheet("background-color:gray;");
    }

    if(((gpio_state >> 2) & 1)==1){
        ui->frameLED3->setStyleSheet("background-color:yellow;");
    }
    else{
        ui->frameLED3->setStyleSheet("background-color:gray;");
    }

    if(((gpio_state >> 3) & 1)==1){
        ui->frameLED4->setStyleSheet("background-color:yellow;");
    }
    else{
        ui->frameLED4->setStyleSheet("background-color:gray;");
    }

    if(((gpio_state >> 4) & 1)==1){
        ui->frameLED5->setStyleSheet("background-color:yellow;");
    }
    else{
        ui->frameLED5->setStyleSheet("background-color:gray;");
    }

    if(((gpio_state >>5) & 1)==1){
        ui->frameLED6->setStyleSheet("background-color:yellow;");
    }
    else{
        ui->frameLED6->setStyleSheet("background-color:gray;");
    }

    if(((gpio_state >> 6) & 1)==1){
        ui->frameLED7->setStyleSheet("background-color:yellow;");
    }
    else{
        ui->frameLED7->setStyleSheet("background-color:gray;");
    }

    if(((gpio_state >> 7) & 1)==1){
        ui->frameLED8->setStyleSheet("background-color:yellow;");
    }
    else{
        ui->frameLED8->setStyleSheet("background-color:gray;");
    }
}

