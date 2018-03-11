#include "DriveToTarget.h"
#include "../Robot.h"

DriveToTarget::DriveToTarget() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	timer = new Timer();
	Requires(&Robot::driveTrain);

}

// Called just before this Command runs the first time
void DriveToTarget::Initialize() {
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void DriveToTarget::Execute() {
	double target = Robot::temp.GetCenterX();
	double power = 0.5;
	if (target!=-1)
		power = target/160;
	Robot::driveTrain.Drive(power);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveToTarget::IsFinished() {
	return timer->Get() > 5;
	//return false;
}

// Called once after isFinished returns true
void DriveToTarget::End() {
	timer->Stop();
	timer->Reset();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveToTarget::Interrupted() {

}
