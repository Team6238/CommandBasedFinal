#ifndef Autonomous_H
#define Autonomous_H

#include "wpilib.h"
#include "DriveToTarget.h"
#include "DumpCube.h"
#include "DriveStraight.h"
#include "Turn.h"

class Autonomous : public CommandGroup {
public:
	Autonomous();

private:
	bool taskFlag = 0; //{0, 1} -> {straight, go for switch}
	int xRobot = 0; //{0, 1, 2} -> {left, mid, right}
	int xSwitch = 0; //{0, 2} -> {left, right}
	std::string fieldData;
};

#endif  // Autonomous_H
