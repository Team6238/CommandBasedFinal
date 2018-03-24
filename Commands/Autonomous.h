#ifndef Autonomous_H
#define Autonomous_H

#include "wpilib.h"
#include "DriveToTarget.h"
#include "DumpCube.h"
#include "DriveStraight.h"
#include "Turn.h"
#include "FlipShifter.h"

class Autonomous : public CommandGroup {
public:
	Autonomous();

private:
	bool taskFlag = 0; //{0, 1} -> {straight, go for switch}
};

#endif  // Autonomous_H
