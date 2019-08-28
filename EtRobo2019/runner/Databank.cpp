/**
 ******************************************************************************
 ** ファイル名 : Databank.cpp
 ** クラス名   : Databank
 **
 ** 概要 : 走行情報を記録するクラス
 ******************************************************************************
 **/
#include "Databank.h"

Databank::Databank(){};

/*
**CSV形式のファイルを開いて列の名前を付ける
**ファイを連番で作成
*/
void Databank::openLogFile(){

	char buf[20];//文字列バッファ
	
	for(int i = 1; i <= 10 ; i++){
		snprintf(buf,20,"%s%d%s","logdata/log",i,".csv");//文字列結合
		logfp = fopen(buf,"r");//ファイルオープン（読み取りモード）
		fclose(logfp);
		if(logfp == NULL){//ファイルが存在するか
			break;//存在しなければbreak
		}
	}


	logfp = fopen(buf,"w");//ファイル作成（書き込みモード）

	//各列名
	//走行情報記録1
	fprintf(logfp, "TIME,RUNDIS,RGB,TRGB,ANGV,LPWM,RPWM\n");
	//走行情報記録2
	//fprintf(logfp, "TIME,RUNDIS,RGB,NRGB,RunDistance,MA,MV,Gyro\n");
}

/*
**走行情報記録1
**ファイルにデータを書き出す
**時間,走行距離,RGB合計値,自然RGB合計値,ジャイロ角速度,左モータpwm,右モータpwm
*/
void Databank::writeLogFile(int time,
							int rundis,
							int rgb,
							int trgb,
							int angv,
							int lpwm,
							int rpwm
							)
{
	fprintf(logfp, "%d,%d,%d,%d,%d,%d,%d\n",
		time,
		rundis,
		rgb,
		trgb,
		angv,
		lpwm,
		rpwm);
}

/*
**走行情報記録2
**ファイルにデータを書き出す
**
*/
void Databank::writeLogFile(int time,int rundis ,int rgb,int nrgb, int RunDistance, int MA,int MV, int Gyro){

	fprintf(logfp, "%d,%d,%d,%d,%d,%d,%d,%d\n",
		time,
		rundis,
		rgb,
		nrgb,
		RunDistance,
		MA,
		MV,
		Gyro);	
}


/*
**ファイルを閉じる
*/
void Databank::closeLogFile(){
	fclose(logfp);
}