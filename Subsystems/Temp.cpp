#include "Temp.h"

Temp::Temp() : Subsystem("Temp") {
	centerX = -1;
}

void Temp::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Temp::UpdateCenterX(double value) {
	centerX = value;
}

double Temp::GetCenterX() {
	return centerX;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
