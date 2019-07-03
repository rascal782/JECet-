/**
 ******************************************************************************
 ** ファイル名 : Databank.h
 ** クラス名   : Databank
 **
 ** 概要 : 走行情報を記録するクラス
 ******************************************************************************
 **/
#pragma once
#include <stdio.h>

class Databank
{
private:
	FILE* logfp;
public:
	Databank();
	void openLogFile();
	void writeLogFile(int time,int rundis,int r,int g,int b,int trgb,int ntrgb);
	void closeLogFile();
};