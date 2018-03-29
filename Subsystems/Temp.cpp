#include "Temp.h"

Temp::Temp() : Subsystem("Temp") {
}

void Temp::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Temp::UpdateCenterX(double data) {
	centerX = data;
}
double Temp::GetCenterX() {
	return centerX;
}

void Temp::UpdatePos(bool data){
	pos = data;
}

bool Temp::GetPos(){
	return pos;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
