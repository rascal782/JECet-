/**
 ******************************************************************************
 ** ファイル名 : MotorControl.h
 ** クラス名   : MotorControl
 **
 ** 概要 : 走行制御を行うクラス
 ******************************************************************************
 **/
#ifndef CONTROL_MOTOR_CONTROL_H
#define CONTROL_MOTOR_CONTROL_H

#include "Motor.h"

using namespace ev3api;

class MotorControl
{
private:
    Motor* XMotor;
    Motor* YMotor;

public:
    MotorControl();
    void init();
    int32_t getXMotorAngle();
    int32_t getYMotorAngle();
    void setPWM(int8_t pwmL, int8_t pwmR);
    void stop();
    void setNoBalanceRun(int forward, int turn);

};
#endif  // CONTROL_MOTOR_CONTROL_H
