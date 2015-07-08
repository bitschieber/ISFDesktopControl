#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include "monitorwindow.h"

namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

private slots:
    void on_pushButtonSimulationMode_clicked();

    void on_pushButtonMonitorMode_clicked();

private:
    Ui::StartWindow *ui;
    MainWindow *mMyNewWindow; // Be sure to destroy you window somewhere
    MonitorWindow *_monitorWindow; // Be sure to destroy you window somewhere
};

#endif // STARTWINDOW_H
