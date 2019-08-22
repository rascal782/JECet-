/**
 ******************************************************************************
 ** ファイル名 : MotorControl.cpp
 ** クラス名   : MotorControl
 **
 ** 概要 : 走行制御を行うクラス
 ******************************************************************************
 **/
#include "MotorControl.h"

/**
 * コンストラクタ
 */
MotorControl::MotorControl() {
    XMotor   = new Motor(PORT_C);
    YMotor  = new Motor(PORT_B);
}

/**
 * 初期化
 */
void MotorControl::init() {
    XMotor->reset();
    YMotor->reset();
}

/**
 * 左モーター回転角度所得
 * @return 左モーター回転角度
 */
int32_t MotorControl::getXMotorAngle() {
    return XMotor->getCount();
}

/**
 * 右モーター回転角度所得
 * @return 右モーター回転角度
 */
int32_t MotorControl::getYMotorAngle() {
    return YMotor->getCount();
}

/**
 * 走行
 * @param 左モーターPWM値
 * @param 右モーターPWM値
 */
void MotorControl::setPWM(int8_t pwmL, int8_t pwmR) {
    if (pwmL == 0) {
         XMotor->stop();
    }
    else {
        XMotor->setPWM(pwmL);
    }

    if (pwmR == 0) {
         YMotor->stop();
    }
    else {
        YMotor->setPWM(pwmR);
    }
}

/**
 * モーター完全停止
 */
void MotorControl::stop() {
    XMotor->reset();
    YMotor->reset();
}

/**
 * 尻尾走行
 * @param forward 前進
 * @param turn    旋回
 */
void MotorControl::setNoBalanceRun(int forward, int turn) {
    int pwmX = forward + turn;
    int pwmY = forward - turn;

    if (pwmX > 100) {
        pwmY = 100;
    }
    if (pwmX > 100) {
        pwmY = 100;
    }

    setPWM(pwmX, pwmY);
}
