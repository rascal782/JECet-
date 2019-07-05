/**
 ******************************************************************************
 ** ファイル名 : Driver.h
 ** クラス名   : Driver
 **
 ** 概要 : 走行体に指示するクラス
 ******************************************************************************
 **/
#ifndef RUNNER_DRIVER_H
#define RUNNER_DRIVER_H

#include "Runner.h"
#include "../scenario/Course.h"
#include "Clock.h"

class Driver
{
private:
    Runner* runner;
    Course* mCourse;
    Course dCourse[8]{
        /*  {  距離,時間,衝撃,障害,  前進,旋回,尻尾,Gyro  P   ,    I   ,    D  ,目標RGB,走行法} */
       {     1,    0,  0,  0,      60,  0, 95,   0, 0.0300F, 0.0000F, 1.0000F, 1.00F, 1 },  //  初期化配列
       {     0,  150,  0,  0,      60,  0, 96,   0, 0.0300F, 0.0000F, 1.0000F, 1.00F, 1 },  //  S
       { 20000,    0,130,  0,      40,  0,  0,   0, 0.0900F, 0.0001F, 0.8000F, 2.00F, 1 },
       {   200,    0,  0,  0,     -20,  0, 75,  -7, 0.0000F, 0.0000F, 0.0000F, 1.00F, 1 },
       {  2000,    0,130,  0,     100,  0,  0,   2, 0.0000F, 0.0000F, 0.0000F, 1.00F, 1 },
       {  2000, 1000,  0,  0,     130,  0, 75,  -5, 0.0000F, 0.0000F, 0.0000F, 1.00F, 1 },
       {  5000,    0,  0,  0,     130,  0, 75,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 1 },
       {     0,    0,  0,  0,       0,  0, 81,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 }   //  完全停止用終端配列
    };
    
    Course lCourse[23] =  {
        {     1,    0,  0,  0,     150,  0, 95,   0, 0.0300F, 0.0000F, 1.0000F, 1.00F, 1 },  //  初期化配列
        {     0,  150,  0,  0,     115,  0, 96,   0, 0.0300F, 0.0000F, 1.0000F, 1.00F, 1 },  //  S
        {  2500,    0,  0,  0,     120,  0,  5,   0, 0.0500F, 0.0000F, 1.0000F, 1.00F, 1 },  //  1 直線
        {  1500,    0,  0,  0,     101,  0,  5,   0, 0.0920F, 0.0001F, 1.0000F, 1.00F, 1 },  //  2 左カーブ
        {  1800,    0,  0,  0,     80,  0,  5,   10, 0.0500F, 0.0000F, 1.0000F, 1.00F, 1 },  //  3 直線
        {   450,    0,  0,  0,     101,  0,  5,   0, 0.0920F, 0.0001F, 1.1000F, 0.95F, 1 },  //  4 右カーブ
        {   650,    0,  0,  0,     116,  0,  5,   0, 0.0500F, 0.0000F, 1.0000F, 1.00F, 1 },  //  5 直線
        {   700,    0,  0,  0,     101,  0,  5,   0, 0.0920F, 0.0001F, 1.1000F, 0.92F, 1 },  //  6 右カーブ
        {  2400,    0,  0,  0,     80,  0,  5,   -10, 0.0500F, 0.0000F, 1.0000F, 1.00F, 1 },  //  7 直進
        /* ここからルックアップ */
        {   900,    0,  0,  0,      30,  0,  5,   0, 0.0900F, 0.0001F, 0.7000F, 1.60F, 1 },  //  8G 左カーブ及び灰色
        {     0,    0,  0, 10,      10,  0, 70,   0, 0.0500F, 0.0001F, 0.7000F, 1.10F, 1 },  //  ルックアップ検知まで
        {     0,  100,  0,  0,      30,  0, 65,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  //  尻尾走行切り替え
        {     0,  700,  0,  0,       0,  0, 65,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  //  安定化停止
        {   320,    0,  0,  0,      10,  0, 65,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  //  シングル通過
        {     0, 1500,  0,  0,       0,  0, 65,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  //  安定化停止
        {   370,    0,  0,  0,     -10,  0, 65,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  //  バック通過
        {     0, 1200,  0,  0,       0,  0, 65,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  //  安定化停止
        {   440,    0,  0,  0,      10,  0, 65,   0, 0.0500F, 0.0002F, 0.3000F, 1.00F, 0 },  //  ダブル通過(PID ON)
        {   280,    0,  0,  0,      10,  0, 65,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  //  灰色通過
        {   195,    0,  0,  0,      10,  0, 70,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  //  ガレージ
        {     0,  300,  0,  0,     -13,  0, 81,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  //  走行体角度上げ
        {     0,    0,  0,  0,       0,  0, 81,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  //  完全停止
        {     0,    0,  0,  0,       0,  0, 81,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 }   //  完全停止用終端配列
    };
    Course rCourse[12] =  {
        {     1,    0,  0,  0,     100,  0, 95,   0, 0.0300F, 0.0000F, 1.0000F, 1.00F, 1 },  //  初期化配列
        {     0,  150,  0,  0,     100,  0, 96,   0, 0.0700F, 0.0000F, 1.0000F, 1.00F, 1 },  //  S
        {  1950,    0,  0,  0,     100,  0,  5,   0, 0.0500F, 0.0000F, 1.0000F, 1.00F, 1 },  //  1 直進
        {  1850,    0,  0,  0,     100,  0,  5,   0, 0.0920F, 0.0001F, 1.0000F, 1.20F, 1 },  //  2 左カーブ
        {   400,    0,  0,  0,     100,  0,  5,   0, 0.0500F, 0.0000F, 1.0000F, 1.10F, 1 },  //  3 直進
        {   700,    0,  0,  0,     100,  0,  5,   0, 0.0980F, 0.0000F, 1.0000F, 1.50F, 1 },  //  4 左カーブ
        {   700,    0,  0,  0,     100,  0,  5,   0, 0.0920F, 0.0000F, 1.1000F, 0.93F, 1 },  //  5 右カーブ
        {   600,    0,  0,  0,     100,  0,  5,   0, 0.0500F, 0.0000F, 1.1000F, 1.00F, 1 },  //  6 直進
        {  1160,    0,  0,  0,     100,  0,  5,   0, 0.0970F, 0.0001F, 1.1000F, 0.93F, 1 },  //  7 右カーブ
        {  2550,    0,  0,  0,     100,  0,  5,   0, 0.0500F, 0.0000F, 1.0000F, 1.00F, 1 },  //  8 直進
        /* ここからシーソー */
        { 92200,    0,  0,  0,      80,  0,  5,   0, 0.0900F, 0.0001F, 0.8000F, 1.50F, 1 },  //  8G 左カーブ及び灰色
        {     0,    0,  0,  0,       0,  0, 80,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 }   //  完全停止
    };
    Clock* clock;
    int beforeDistance;
    int beforeClock;
    int courseNumber = 0;
    int logBeforeClock = 0;

public:
    Driver();
    void start();
    void exec();
    int courseChange();
    void btUpdate();

};
#endif  // RUNNER_DRIVER_H
