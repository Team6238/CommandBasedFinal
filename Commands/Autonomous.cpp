#include "Autonomous.h"

Autonomous::Autonomous() {
	if (!taskFlag){
		AddSequential(new DriveStraight());
	}else{
		/*fieldData = DriverStation::GetInstance().GetGameSpecificMessage();
		if (fieldData.at(0) == 'R')
			xSwitch = 2;
		if (fieldData.at(0) != xRobot){
			if (xSwitch < xRobot)
				//turn left
			else
				//turn right
		}*/
		AddSequential(new DriveToTarget());
		AddSequential(new DumpCube());
	}
}

