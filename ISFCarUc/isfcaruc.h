#ifndef ISFCARUC_H
#define ISFCARUC_H

#include "../HAL/i_isfcarhal.h"
#include "controller/speedcontroller.h"


class ISFCarUc
{
public:
    ISFCarUc(I_ISFCarHAL *hal);
    void Start(void);
private:
    I_ISFCarHAL *_isfCarHAL;
    //uint16_t speedToPWM(uint16_t speed);
    uint16_t steeringAngleToPWM(uint16_t angle);

    SpeedController *_speedController;
    DATA_SET_UC_BRAIN_BOARD_t _dataToBrainBoardHost;
};

#endif // ISFCARUC_H
