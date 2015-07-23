#ifndef ISFTIMER_H
#define ISFTIMER_H

#include "../../hal/i_isfcarhal.h"

class ISFTimer
{
public:
    ISFTimer(I_ISFCarHAL* hal, uint32_t us);
    bool isElapsed(void);
 private:
    I_ISFCarHAL* _isfHal;
    uint32_t  _us;
    uint32_t  _lastUs;
};

#endif // ISFTIMER_H
