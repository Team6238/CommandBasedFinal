#include "Autonomous.h"
#include <iostream>
#include "../Robot.h"

Autonomous::Autonomous(bool b):CommandGroup("Autonomous") {
	//vision switch
	/*if (!taskFlag){
		AddSequential(new DriveStraight());
	}else{
		AddSequential(new DriveToTarget());
		AddSequential(new DumpCube());
	}*/

	//50/50 blind switch
	AddSequential (new FlipShifter(), 1.0);
	AddSequential (new DriveStraight(), 3.5);
	SmartDashboard::PutBoolean("transferredB", b);
	if (taskFlag && b == pos)
			AddSequential(new DumpCube(), 3.0);
}

