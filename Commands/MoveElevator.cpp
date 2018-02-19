#include "MoveElevator.h"
#include "../Robot.h"

MoveElevator::MoveElevator() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::elevator);
}

// Called just before this Command runs the first time
void MoveElevator::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveElevator::Execute() {
	if (Robot::oi.CheckUpwardElevatorButton()&&Robot::oi.CheckDownwardElevatorButton())
		Robot::elevator.Set(0);
	else if (Robot::oi.CheckUpwardElevatorButton())
		Robot::elevator.Set(1);
	else if (Robot::oi.CheckDownwardElevatorButton())
		Robot::elevator.Set(-1);
	else
		Robot::elevator.Set(0);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveElevator::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MoveElevator::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveElevator::Interrupted() {

}
