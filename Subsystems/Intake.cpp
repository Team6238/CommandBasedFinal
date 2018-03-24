#include "Intake.h"
#include <Commands/MoveIntake.h>

Intake::Intake() : Subsystem("Intake") {
}

void Intake::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new MoveIntake());
}

void Intake::Set(int direction){
	leftTalon.Set(-1*direction*0.75);
	rightTalon.Set(-1*direction*0.75);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
