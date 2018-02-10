
//#define _GLIBCXX_USE_CXX11_ABI 0
#ifndef DriveTrain_H
#define DriveTrain_H
#include <wpilib.h>
#include "ctre/Phoenix.h"
#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>
#include <SpeedControllerGroup.h>

class DriveTrain : public Subsystem {
private:
	WPI_TalonSRX frontLeft{35}, frontRight{31}, midLeft{34}, midRight{32}, backLeft{33}, backRight{36};
	SpeedControllerGroup leftGroup{frontLeft, midLeft, backLeft}, rightGroup{frontRight, midRight, backRight};
	DifferentialDrive myDrive{leftGroup, rightGroup};
	//Encoder *encoder;
public:
	DriveTrain();
	void InitDefaultCommand();
	void Drive();
};

#endif  // DriveTrain_H
