#ifndef ISFCARTHREAD_H
#define ISFCARTHREAD_H

#include "HAL/i_isfcarhal.h"
#include "ISFCarUc/isfcaruc.h"
#include <QObject>
#include <QThread>


class ISFCarThread : public QThread
{
    Q_OBJECT
public:
    ISFCarThread(I_ISFCarHAL *hal);
    void stopISFCar();
private:
    ISFCarUc *_isfCarUc;
protected:
    void run();
};

#endif // ISFCARTHREAD_H
