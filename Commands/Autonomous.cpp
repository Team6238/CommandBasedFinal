#include "Autonomous.h"

Autonomous::Autonomous() {
	if (!taskFlag){
		AddSequential(new DriveStraight());
	}else{
		fieldData = DriverStation::GetInstance().GetGameSpecificMessage();
		if (fieldData.at(0) == 'R')
			xSwitch = 2;
		if (fieldData.at(0) != xRobot){
			AddSequential(new Turn(fieldData.at(0) - xRobot));
		}
		AddSequential(new DriveToTarget());
		AddSequential(new DumpCube());
	}
}

