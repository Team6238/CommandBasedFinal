#include "Autonomous.h"
#include <iostream>
#include "../Robot.h"

Autonomous::Autonomous(bool switchPos, bool robotPos, bool taskFlag):CommandGroup("Autonomous") {
	//vision switch
	/*if (!taskFlag){
		AddSequential(new DriveStraight());
	}else{
		AddSequential(new DriveToTarget());
		AddSequential(new DumpCube());
	}*/

	//50/50 blind switch
	AddSequential (new FlipShifter());
	AddSequential (new DriveStraight());
	//SmartDashboard::PutBoolean("autonB", switchPos);
	if (taskFlag && switchPos == robotPos)
		AddSequential(new DumpCube());
}

