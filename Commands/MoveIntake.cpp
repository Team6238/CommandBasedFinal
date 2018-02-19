#include "MoveIntake.h"
#include "../Robot.h"

MoveIntake::MoveIntake() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::intake);
}

// Called just before this Command runs the first time
void MoveIntake::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveIntake::Execute() {
	if (Robot::oi.CheckForwardIntakeButton()&&Robot::oi.CheckBackwardIntakeButton())
		Robot::intake.Set(0);
	else if (Robot::oi.CheckForwardIntakeButton())
		Robot::intake.Set(1);
	else if (Robot::oi.CheckBackwardIntakeButton())
		Robot::intake.Set(-1);
	else
		Robot::intake.Set(0);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveIntake::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MoveIntake::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveIntake::Interrupted() {

}
