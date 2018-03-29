#include "DriveStraight.h"
#include "../Robot.h"


DriveStraight::DriveStraight() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::driveTrain);
	timer = new Timer();
}

// Called just before this Command runs the first time
void DriveStraight::Initialize() {
	//Wait(7.0);
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void DriveStraight::Execute() {
	if (timer->Get() < 3.0)
		Robot::driveTrain.Drive(0.65, 0.65);
	else
		Robot::driveTrain.Drive(0, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraight::IsFinished() {
	return timer->Get()>3.0;
}

// Called once after isFinished returns true
void DriveStraight::End() {
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraight::Interrupted() {

}
