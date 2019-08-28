/**
 ******************************************************************************
 ** ファイル名 : Databank.h
 ** クラス名   : Databank
 **
 ** 概要 : 走行情報を記録するクラス
 ******************************************************************************
 **/
#pragma once
#include "ev3api.h"
#include <string.h>
class Databank
{
private:
	FILE* logfp;
public:
	Databank();
	void openLogFile();

	//走行情報記録1
	void writeLogFile(int time,
					  int rundis,
					  int rgb,
					  int trgb,
					  int angv,
					  int lpwm,
					  int rpwm
					  );

	//走行情報記録2
	void writeLogFile(int time,
					  int rundis,
					  int rgb,
					  int nrgb,
					  int RunDistance,
					   int MA,
					   int MV,
					   int Gyro
					   );

	void closeLogFile();
};