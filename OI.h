//#define _GLIBCXX_USE_CXX11_ABI 0
#ifndef OI_H
#define OI_H

#include <wpilib.h>

class OI {
private:
	Joystick* rightStick, *leftStick;
	JoystickButton *solenoidButton, *forwardIntakeButton, *backwardIntakeButton, *upwardElevatorButton, *downwardElevatorButton;

public:
	OI();
	Joystick* GetRightStick();
	Joystick* GetLeftStick();
	bool CheckForwardIntakeButton();
	bool CheckBackwardIntakeButton();
	bool CheckUpwardElevatorButton();
	bool CheckDownwardElevatorButton();
};

#endif  // OI_H
