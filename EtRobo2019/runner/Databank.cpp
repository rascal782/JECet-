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

<<<<<<< HEAD

	logfp = fopen(buf,"w");//ファイル作成（書き込みモード）

	//各列名
	fprintf(logfp, "TIME,RUNDIS,R,G,B,RGB,NRGB,TRGB,ANGV,LPWM,RPWM\n");
=======
	do{
		snprintf(buf,12,"%s%d%s","log",i,".csv");
		logfp = fopen(buf,"r");
		fclose(logfp);
		i++;
	}while(logfp != NULL);

	logfp = fopen(buf,"w");
	//logfp = fopen("log.csv","w");
	//fprintf(logfp, "TIME,RUNDIS,R,G,B,RGB,NRGB,ANG,ANGV\n");
	fprintf(logfp, "TIME,RUNDIS,RGB,NRGB,RunDistance,MA,MV\n");
>>>>>>> origin/rascal
}

/*
**ファイルにデータを書き出す
**時間,走行距離,R,G,B,RGB合計値,自然RGB合計値
*/
<<<<<<< HEAD
void Databank::writeLogFile(int time,
							int rundis,
							int r,
							int g,
							int b,
							int rgb,
							int nrgb,
							int trgb,
							int angv,
							int lpwm,
							int rpwm
							)
{
	fprintf(logfp, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
		time,
		rundis,
		r,
		g,
		b,
		rgb,
		nrgb,
		trgb,
		angv,
		lpwm,
		rpwm);
=======
//int ang,int angv
// void Databank::writeLogFile(int time,int rundis,int r,int g,int b,int rgb,int nrgb){

// 	//fprintf(logfp, "%d,%d,%d,%d,%d,%d,%d,%d,%d\n",time,rundis,r,g,b,rgb,nrgb,ang,angv);
// 	fprintf(logfp, "%d,%d,%d,%d,%d,%d,%d\n",time,rundis,r,g,b,rgb,nrgb);
// }
void Databank::writeLogFile(int time,int rundis ,int rgb,int nrgb, int RunDistance){

	//fprintf(logfp, "%d,%d,%d,%d,%d,%d,%d,%d,%d\n",time,rundis,r,g,b,rgb,nrgb,ang,angv);
	fprintf(logfp, "%d,%d,%d,%d,%d\n",time,rundis,rgb,nrgb,RunDistance);
>>>>>>> origin/rascal
}
void Databank::writeLogFile(int time,int rundis ,int rgb,int nrgb, int RunDistance, int MA,int MV){

	//fprintf(logfp, "%d,%d,%d,%d,%d,%d,%d,%d,%d\n",time,rundis,r,g,b,rgb,nrgb,ang,angv);
	fprintf(logfp, "%d,%d,%d,%d,%d,%d,%d\n",time,rundis,rgb,nrgb,RunDistance,MA,MV);	
}


/*
**ファイルを閉じる
*/
void Databank::closeLogFile(){
	fclose(logfp);
}