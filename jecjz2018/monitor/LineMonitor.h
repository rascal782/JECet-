
#ifndef EV3_UNIT_LINEMONITOR_H_
#define EV3_UNIT_LINEMONITOR_H_

#include "ColorSensor.h"

class LineMonitor
{

public:
	static const int8_t INITIAL_THRESHOLD;

	explicit LineMonitor(ev3api::ColorSensor& colorSensor);
	~LineMonitor();
	
	bool isOnLine() const;
	void setThreshold(int8_t mThreshold) const;
	
private:
	const ev3api::ColorSensor& mColorSensor;
	int8_t mThreshold;
};
	