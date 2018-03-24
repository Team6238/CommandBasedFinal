#include "Autonomous.h"
#include <iostream>
#include "../Robot.h"

Autonomous::Autonomous() {
	//vision switch
	/*if (!taskFlag){
		AddSequential(new DriveStraight());
	}else{
		AddSequential(new DriveToTarget());
		AddSequential(new DumpCube());
	}*/

	//50/50 blind switch
	if (!taskFlag)
		AddSequential(new DriveStraight());
	else{
		AddSequential (new FlipShifter());
		AddSequential (new DriveStraight());
		std::string temp = Robot::temp.GetFieldData();
		SmartDashboard::PutString("fieldData" , temp);
		if (temp.length()==3 && temp.at(0) == 'R')
			AddSequential(new DumpCube());
	}
}

