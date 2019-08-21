#include "Databank.h"

Databank::Databank(){};

/*
**CSV形式のファイルを開いて列の名前を付ける
**ファイを連番で作成
*/
void Databank::openLogFile(){

	char buf[12];
	int i=1;

	do{
		snprintf(buf,12,"%s%d%s","log",i,".csv");
		logfp = fopen(buf,"r");
		fclose(logfp);
		i++;
	}while(logfp != NULL);

	logfp = fopen(buf,"w");
	//logfp = fopen("log.csv","w");
	//fprintf(logfp, "TIME,RUNDIS,R,G,B,RGB,NRGB,ANG,ANGV\n");
	fprintf(logfp, "TIME,RUNDIS,R,G,B,RGB,NRGB\n");
}

/*
**ファイルにデータを書き出す
**時間,走行距離,R,G,B,RGB合計値,自然RGB合計値,ジャイロ角位置,ジャイロ角速度
*/
//int ang,int angv
void Databank::writeLogFile(int time,int rundis,int r,int g,int b,int rgb,int nrgb){

	//fprintf(logfp, "%d,%d,%d,%d,%d,%d,%d,%d,%d\n",time,rundis,r,g,b,rgb,nrgb,ang,angv);
	fprintf(logfp, "%d,%d,%d,%d,%d,%d,%d\n",time,rundis,r,g,b,rgb,nrgb);
}
void Databank::writeLogFile(int time,int rundis ,int rgb,int nrgb, int RunDistance){

	//fprintf(logfp, "%d,%d,%d,%d,%d,%d,%d,%d,%d\n",time,rundis,r,g,b,rgb,nrgb,ang,angv);
	fprintf(logfp, "%d,%d,%d,%d,%d\n",time,rundis,rgb,nrgb,RunDistance);
}


/*
**ファイルを閉じる
*/
void Databank::closeLogFile(){
	fclose(logfp);
}