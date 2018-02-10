#include "DriveToTarget.h"
#include "../Robot.h"

DriveToTarget::DriveToTarget() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void DriveToTarget::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveToTarget::Execute() {
	double power =  Robot::temp.GetCenterX() / 160;
	Robot::driveTrain.Drive(power);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveToTarget::IsFinished() {
	return Robot::driveTrain.IsStopped();
}

// Called once after isFinished returns true
void DriveToTarget::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveToTarget::Interrupted() {

}
