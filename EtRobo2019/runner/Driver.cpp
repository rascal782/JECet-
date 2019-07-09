/**
 ******************************************************************************
 ** ファイル名 : Driver.cpp
 ** クラス名   : Driver
 **
 ** 概要 : 走行体に指示するクラス
 ******************************************************************************
 **/
#include "Driver.h"

#include "ev3api.h"

/**
 * コンストラクタ
 */
Driver::Driver() {
    runner = new Runner();
    clock = new Clock();
}

/**
 * スタート待機
 */
void Driver::start() {
    runner->start(0, 0, 94);
    // TODO ここの処理は新たに作成するコースクラスで実装
    if (runner->getBtCmd() == 1) {
        mCourse = lCourse;
    }
    else if (runner->getBtCmd() == 2) {
        mCourse = rCourse;
    }
    else if (runner->getBtCmd() == 3) {
        mCourse = dCourse;
    }
    beforeDistance = runner->getDistance();
    beforeClock = clock->now();
}

/**
 * 走行
 */
void Driver::exec() {
    // TODO この処理は新たに作成するコースクラスで実装
    if (courseChange()) {
        courseNumber++;
        runner->setGyroOffset(mCourse[courseNumber].getGyroOffset());
        runner->setStyle(mCourse[courseNumber].getStyle());
        runner->setPID(mCourse[courseNumber].getP(), mCourse[courseNumber].getI(), mCourse[courseNumber].getD());
        beforeDistance = runner->getDistance();
        beforeClock = clock->now();
    }
    runner->run(mCourse[courseNumber].getForward(), mCourse[courseNumber].getTurn(), mCourse[courseNumber].getTailAngle(), mCourse[courseNumber].getKrgb());
    if ((mCourse[courseNumber].getDis() + mCourse[courseNumber].getTime() + mCourse[courseNumber].getImpact() + mCourse[courseNumber].getSonarDis()) == 0) {
        runner->stop();
    }
    runner->recordLog(clock->now());
}

/**
 * 区間変更条件確認
 * @param changeCnt 変更情報
 */
bool Driver::courseChange() {
    bool changeCnt =false;
    //syslog(LOG_NOTICE, "%d", courseNumber);
    switch(mCourse[courseNumber].getTrans()){
        case 0:
            if ( mCourse[courseNumber].getTime() != 0) {
                if ((int)(clock->now() - beforeClock) >= mCourse[courseNumber].getTime()) {
                    changeCnt = true;
                }
            }
            break;
        case 1:
            if (mCourse[courseNumber].getDis() != 0) {
                int tmpDis = runner->getDistance() - beforeDistance;
                if (tmpDis < 0) {
                    tmpDis = tmpDis * (-1);
                }
                if (tmpDis >= mCourse[courseNumber].getDis()) {
                    changeCnt = true;
                }
            }
            break;
        case 2:
            if (mCourse[courseNumber].getImpact() != 0) {
                if (runner->getGyroImpact() <= mCourse[courseNumber].getImpact()) {
                    changeCnt = true;
                }
            }
            break;
        case 3:
             if (mCourse[courseNumber].getSonarDis() != 0) {
                if (runner->getSonarDis() <= mCourse[courseNumber].getSonarDis()) {
                    changeCnt = true;
                }
            }
            break;
    }
    return changeCnt;
}

/**
 * BT更新
 */
void Driver::btUpdate() {
    runner->btUpdate();
}
