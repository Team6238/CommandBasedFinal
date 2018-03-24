#include "Elevator.h"
#include <Commands/MoveElevator.h>

Elevator::Elevator() : Subsystem("Elevator") {
}

void Elevator::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new MoveElevator());
}

void Elevator::Set(int direction){
	talon.Set(-1*direction);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
