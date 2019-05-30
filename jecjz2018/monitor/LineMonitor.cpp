#include "LineMonitor.h"

const int8_t LineMonitor::INITIAL_THRESHOLD = 20;

LineMonitor::LineMonitor(const ev3api::ColorSensor& colorSensor){
	mColorSensor(colorSensor); 
	mThreshold(INITIAL_THRESHOLD) {}
}

bool LineMonitor::isOnline() const{
	if(mColorSensor.getBrightness() >= mThreshold){
		return true;
	}else{
		return false;
	}
}

void LineMonitor::setThreshold(int8_t threshold){
	mThreshold = threshold;
}