//#define _GLIBCXX_USE_CXX11_ABI 0
#include "DriveTrain.h"
#include "../Robot.h"
#include "Commands/TankDrive.h"
#include <iostream>

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {
	myDrive.SetSafetyEnabled(0);
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TankDrive());
}

void DriveTrain::Drive() {
	myDrive.TankDrive(-1*Robot::oi.GetLeftStick()->GetY(), -1*Robot::oi.GetRightStick()->GetY(), 1);
	//std::cout << encoder->Get();
}
void DriveTrain::Drive(double power) {
	myDrive.TankDrive(power, 1 - power);
}
bool DriveTrain::IsStopped() {
	return leftGroup.Get() == 0 && rightGroup.Get() == 0;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
