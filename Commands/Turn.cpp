#include "Turn.h"
#include "../Robot.h"

Turn::Turn(int target) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::driveTrain);
	timer = new Timer();
	direction = target/abs(target);
	timeF = 0.5*abs(target);
}

// Called just before this Command runs the first time
void Turn::Initialize() {
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void Turn::Execute() {
	Robot::driveTrain.Drive(0.5*direction, -0.5*direction);
}

// Make this return true when this Command no longer needs to run execute()
bool Turn::IsFinished() {
	return timer->Get() <= timeF;
}

// Called once after isFinished returns true
void Turn::End() {
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Turn::Interrupted() {

}
