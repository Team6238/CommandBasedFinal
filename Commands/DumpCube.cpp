#include "DumpCube.h"
#include "../Robot.h"

DumpCube::DumpCube() {
	Requires(&Robot::intake);
	timer = new Timer();
}

// Called just before this Command runs the first time
void DumpCube::Initialize() {
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void DumpCube::Execute() {
	Robot::intake.Set(-1);
}

// Make this return true when this Command no longer needs to run execute()
bool DumpCube::IsFinished() {
	return timer->Get()>3.0;
}

// Called once after isFinished returns true
void DumpCube::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DumpCube::Interrupted() {

}
