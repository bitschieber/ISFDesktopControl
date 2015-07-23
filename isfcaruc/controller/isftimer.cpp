#include "isftimer.h"

ISFTimer::ISFTimer(I_ISFCarHAL* hal, uint32_t us)
{
    this->_isfHal = hal;
    this->_us = us;
    this->_lastUs = _isfHal->getUsTime();
}

bool ISFTimer::isElapsed(void)
{
    if(_isfHal->getUsTime()-this->_lastUs >= this->_us){
        this->_lastUs = _isfHal->getUsTime();
        return true;
    }

    return false;
}

