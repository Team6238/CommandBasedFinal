#ifndef Autonomous_H
#define Autonomous_H

#include "wpilib.h"
#include "DriveToTarget.h"
#include "DumpCube.h"
#include "DriveStraight.h"

class Autonomous : public CommandGroup {
public:
	Autonomous();

private:
	bool taskFlag = 0;
	int xRobot = 0;
	int xSwitch = 0;
	std::string fieldData;
};

#endif  // Autonomous_H
