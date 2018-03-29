#ifndef Autonomous_H
#define Autonomous_H

#include "wpilib.h"
#include "DriveToTarget.h"
#include "DumpCube.h"
#include "DriveStraight.h"
#include "FlipShifter.h"

class Autonomous : public CommandGroup {
public:
	Autonomous(bool b); //{0, 1) -> {switch on left, right}

private:
	bool taskFlag = 1; //{0, 1} -> {straight, go for switch}
	bool pos = 1; //{0, 1} -> {robot on left, right}
};

#endif  // Autonomous_H
