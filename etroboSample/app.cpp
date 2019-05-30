/**
 ******************************************************************************
 ** ファイル名 : app.cpp
 **
 ** 概要 : 2輪倒立振子ライントレースロボットのTOPPERS/HRP2用C++サンプルプログラム
 **
 ** 注記 : sample_cpp (ライントレース/尻尾モータ/超音波センサ/リモートスタート)
 ******************************************************************************
 **/
#include "app.h"

#include "monitor/LineMonitor.h"

#define DEBUG

#ifdef DEBUG
#define _debug(x) (x)
#else
#define _debug(x)
#endif

LineMonitor* lineMonitor;

/**
 * メインタスク
 * @param unused 拡張情報
 */
void mainTask(intptr_t unused){
    
    lineMonitor = new LineMonitor();
    
    bool sirokuro = lineMonitor->isOnLine();

    //ER er = ev3_sta_cyc(CYC_HANDLER);   //周期ハンドラを起動
    // sprintf(buf, "main_task: error_code=%d", MERCD(er) );   // APIのエラーコードの表示の仕方です。
    syslog(LOG_NOTICE, "白黒 %d", sirokuro);
    // slp_tsk();

    // ext_tsk();
}

/**
//  * コントロールタスク
//  * @param unused 拡張情報
//  */
// void controllerTask(intptr_t unused)
// {
//     //driver->exec();
// }

// /**
//  * 周期ハンドラ(4ms)
//  * @param unused 拡張情報
//  */
// void cycHandler(intptr_t unused)
// {
//     act_tsk(CONTROLLER_TASK);
// }

// *
//  * BTタスク
//  * @param unused 拡張情報
//  * @comment Bluetooth通信によるリモートスタート。 Tera Termなどのターミナルソフトから、
//  *          ASCIIコードで1を送信すると、リモートスタートする。
 
// void btTask(intptr_t unused)
// {
//     while(1) {
//         //driver->btUpdate();
//     }
