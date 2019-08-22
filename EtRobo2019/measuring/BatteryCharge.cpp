/**
 ******************************************************************************
 ** ファイル名 : BatteryCharge.cpp
 ** クラス名   : BatteryCharge
 **
 ** 概要 : バッテリー残量を監視するクラス
 ******************************************************************************
 **/
#include "BatteryCharge.h"
#include "ev3api.h"

/**
 * コンストラクタ
 */
BatteryCharge::BatteryCharge() {	   	
 	mA = ev3_battery_current_mA();
	mV = ev3_battery_voltage_mV();
}

/**
 * 更新
 */
void BatteryCharge::mAUpdate() {
	mA = ev3_battery_current_mA();
}
/**
 * 更新
 */
void BatteryCharge::mVUpdate() {
	mV = ev3_battery_voltage_mV();
}
/**
 *ゲッター
*/
int BatteryCharge::getMA(){
	mAUpdate();
	return mA;
}
int BatteryCharge::getMV(){
	mVUpdate();
	return mV;
}