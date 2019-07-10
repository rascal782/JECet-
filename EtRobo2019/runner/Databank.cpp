#include "Databank.h"

Databank::Databank(){};

/*
**CSV形式のファイルを開いて列の名前を付ける
**ファイを連番で作成
*/
void Databank::openLogFile(){

	char buf[30];
	int i=1;

	
	while(1){
		snprintf(buf,30,"%s%d%s","logdata/log",i,".csv");
		logfp = fopen(buf,"r");

		if(logfp == NULL){
			fclose(logfp);
			break;
		}

		fclose(logfp);
		i++;
	}
	

	logfp = fopen(buf,"w");
	fprintf(logfp, "TIME,RUNDIS,R,G,B,RGB,NRGB,ANGV\n");
}

/*
**ファイルにデータを書き出す
**時間,走行距離,R,G,B,RGB合計値,自然RGB合計値
*/
void Databank::writeLogFile(int time,int rundis,int r,int g,int b,int rgb,int nrgb,int angv){
	
	fprintf(logfp, "%d,%d,%d,%d,%d,%d,%d,%d\n",time,rundis,r,g,b,rgb,nrgb,angv);
}

/*
**ファイルを閉じる
*/
void Databank::closeLogFile(){
	fclose(logfp);
}