/**
 ******************************************************************************
 ** ファイル名 : ControlManager.h
 ** クラス名   : ControlManager
 **
 ** 概要 : 制御を管理するクラス
 ******************************************************************************
 **/
#ifndef CONTROL_CONTROL_MANAGER_H
#define CONTROL_CONTROL_MANAGER_H

#include "GyroSensor.h"
#include "BalancerCpp.h"
#include "MotorControl.h"
#include "TailControl.h"
#include "PID.h"

using namespace ev3api;

class ControlManager
{
private:
    GyroSensor* gyroSensor;
    Balancer* balancer;
    MotorControl* mc;
    TailControl* tc;
    PID* motorPid;
    int targetRgb = 284; /* 目標RGB値 */

public:
    ControlManager();
    void gyroInit();
    void tailInit();
    void wheelInit();
    void balancerInit();
    void running(int forward, int turn, int tailAngle);
    void runningL(int forward, int turn, int tailAngle, int totalRgb);
    void runningR(int forward, int turn, int tailAngle, int totalRgb);
    void noBalanceRun(int forward, int turn, int tailAngle, int totalRgb);
    void stop();
    void setPID(float kp, float ki, float kd);
    void setTargetRgb(int targetRgb);
    void setGyroOffset(int gyroOffset);
    float getKRGB(int tailAngle);
    //int getAngle();
    int getAnglerVelocity();
};
#endif  // CONTROL_CONTROL_MANAGER_H
