#ifndef ROBOT_H
#define ROBOT_H

#include <Commands/Command.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>

#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <vector>
#include <algorithm>

#include <OI.h>
#include <FindContours.h>
#include <Subsystems/Pneumatics.h>
#include <Subsystems/DriveTrain.h>
#include <Subsystems/Intake.h>
#include <Subsystems/Elevator.h>
#include <Subsystems/Temp.h>
#include <Commands/Autonomous.h>
#include <Commands/FlipShifter.h>


class Robot: public frc::IterativeRobot{
public:
	static DriveTrain driveTrain;
	static Intake intake;
	static Elevator elevator;
	static Pneumatics pneumatics;
	static OI oi;
	//static VisionModule vm;
	static Temp temp;
private:
	frc::LiveWindow* lw = frc::LiveWindow::GetInstance();
	Autonomous* autonomous = new Autonomous();
	Command* flip = new FlipShifter();

	bool comp(double a, double b);
	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;


	//double centerX = -1;
};

#endif  // OI_H
