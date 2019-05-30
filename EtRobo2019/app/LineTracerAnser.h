#ifndef EV3_APP_LINETRACER_H_
#define EV3_APP_LINETRACER_H_

#include "LineMonitor.h"
#include "BalancingWalker.h"

class LineTracerAnser {
public:
	LineMonitor(consr LineMonitor* LineMonitor BalancingWalker* balancingWalker);
	void run();

}

private:
	const LineMonitor* ;
	const LineMonitor;
	const BalancingWalker*;
	const balancingWalker;

	bool mIsInitialized;
	int calcDirection(bool isOnLine);

}

#endif