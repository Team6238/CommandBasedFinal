
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
	WPI_TalonSRX right1{30}, right2{34}, right3{33}, left1{31}, left2{32}, left3{36};
	SpeedControllerGroup leftGroup{left1, left2, left3}, rightGroup{right1, right2, right3};
	DifferentialDrive myDrive{leftGroup, rightGroup};
	Encoder *leftEncoder, *rightEncoder;
public:
	DriveTrain();
	void InitDefaultCommand();
	void Drive();
	void Drive(double power);
	void Drive(double leftPower, double rightPower);
	bool IsStopped();
};

#endif  // DriveTrain_H
