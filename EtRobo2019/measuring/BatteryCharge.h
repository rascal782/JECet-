/**
 ******************************************************************************
 ** ファイル名 : BatteryCharge.h
 ** クラス名   : BatteryCharge
 **
 ** 概要 : バッテリー残量を監視するクラス
 ******************************************************************************
 **/
#ifndef MEASURING_BATTERY_CHARGE_H
#define MEASURING_BATTERY_CHARGE_H

#include "ev3api.h"


class BatteryCharge
{
private:
    int mA;         /* バッテリー電流 */
    int mV;         /*バッテリー電圧*/

public:
    BatteryCharge();
    void mAUpdate();
    void mVUpdate();
    int getMA();
    int getMV();
};
#endif  // MEASURING_COLOR_H