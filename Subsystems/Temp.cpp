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

void Temp::UpdateFieldData(std::string data){
	fieldData = data;
}

std::string Temp::GetFieldData(){
	return fieldData;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
