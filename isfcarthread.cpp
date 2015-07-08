#include "isfcarthread.h"

ISFCarThread::ISFCarThread(I_ISFCarHAL *hal)
{
    _isfCarUc = new ISFCarUc(hal);
}

void ISFCarThread::run()
{
    _isfCarUc->start();
}

void ISFCarThread::stopISFCar()
{
    _isfCarUc->stop();
    while(this->isFinished()!=true)
    {

    }
}
