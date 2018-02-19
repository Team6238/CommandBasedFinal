//#define _GLIBCXX_USE_CXX11_ABI 0
#include "OI.h"
#include <wpilib.h>

OI::OI() {
	// Process operator interface input here.
	rightStick = new Joystick(0);
	leftStick = new Joystick(1);
	solenoidButton = new JoystickButton(rightStick, 1);
	forwardIntakeButton = new JoystickButton(rightStick, 3);
	backwardIntakeButton = new JoystickButton(rightStick, 5);
	upwardElevatorButton = new JoystickButton(rightStick, 4);
	downwardElevatorButton = new JoystickButton(rightStick, 6);
	//solenoidButton->WhenPressed(new MoveSolenoid());
}

Joystick* OI::GetLeftStick() {
	return leftStick;
}

Joystick* OI::GetRightStick(){
	return rightStick;
}

bool OI::CheckForwardIntakeButton(){
	return forwardIntakeButton->Get();
}

bool OI::CheckBackwardIntakeButton(){
	return backwardIntakeButton->Get();
}

bool OI::CheckUpwardElevatorButton(){
	return upwardElevatorButton->Get();
}

bool OI::CheckDownwardElevatorButton(){
	return downwardElevatorButton->Get();
}
