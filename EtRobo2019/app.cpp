/******************************************************************************
 *  app.cpp (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/25
 *  Implementation of the Task main_task
 *  Author: Kazuhiro.Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#include "ev3api.h"
#include "app.h"
// デストラクタ問題の回避
// https://github.com/ETrobocon/etroboEV3/wiki/problem_and_coping
#include "runner/Driver.h"

#define DEBUG

#ifdef DEBUG
#define _debug(x) (x)
#else
#define _debug(x)
#endif

Driver* driver;

/**
 * メインタスク
 *　@param unused 拡張情報
 */
void mainTask(intptr_t unused){
    char buf[64];
    driver = new Driver();

    act_tsk(BT_TASK);

    driver->start();

    ER er = ev3_sta_cyc(CYC_HANDLER);
    sprintf(buf, "main_task: error_code=%d",MERCD(er))

    slp_tsk();
    ext_tsk();
}

/**
 * コントロールタスク
 * @param unused 拡張情報
 */
void controllerTask(intptr_t unused){
    driver->exec();
}

/**
 * BTタスク
 * @param unused 拡張情報
 * `comment Blutppth通信によるリモートスタート。Tera Termなどのターミナルソフトから、ASCIIコードで1を送信すると、リモートスタートする。
 */

void btTask(intptr_t unused){
    while(1){
        driver->btUpdate();
    }
}