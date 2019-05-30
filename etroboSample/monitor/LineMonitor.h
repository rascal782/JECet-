#pragma once
#ifndef EV3_UNIT_LINEMONITOR_H_
#define EV3_UNIT_LINEMONITOR_H_

using namespace ev3api;
class LineMonitor
{
private:
	const ev3api::ColorSensor& mColorSensor;
	int8_t mThreshold;

public:
	static const int8_t INITIAL_THRESHOLD;

	explicit LineMonitor(ev3api::ColorSensor& colorSensor);
	~LineMonitor();
	
	bool isOnLine() const;
	void setThreshold(int8_t mThreshold) const;
};
	