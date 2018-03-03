#include "MoveSolenoid.h"
#include "../Robot.h"

MoveSolenoid::MoveSolenoid(int i) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::pneumatics);
	target = i;
}

// Called just before this Command runs the first time
void MoveSolenoid::Initialize() {
	Robot::pneumatics.FlipSolenoid(target);
}

// Called repeatedly when this Command is scheduled to run
void MoveSolenoid::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool MoveSolenoid::IsFinished() {
	return 1;
}

// Called once after isFinished returns true
void MoveSolenoid::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveSolenoid::Interrupted() {

}
