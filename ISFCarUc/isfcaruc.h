#ifndef ISFCARUC_H
#define ISFCARUC_H

#include "../HAL/i_isfcarhal.h"
#include "controller/speedcontroller.h"
#include "controller/steeringcontroller.h"
#include <string.h>


class ISFCarUc
{
public:
    ISFCarUc(I_ISFCarHAL *hal);
    void start(void);
    void stop(void);
private:
    I_ISFCarHAL *_isfCarHAL;
    bool _running;
    uint32_t _mainLoopTimeStamp;
    //uint16_t speedToPWM(uint16_t speed);
    uint16_t steeringAngleToPWM(uint16_t angle);

    SpeedController *_speedController;
    SteeringController *_steeringController;
    DATA_SET_UC_BRAIN_BOARD_t _dataToBrainBoardHost;
};

#endif // ISFCARUC_H
