#ifndef ROBOT_H
#define ROBOT_H

#include <Commands/Command.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>

#include <OI.h>
#include <TestPipeline.h>
#include <FindContours.h>
#include <Subsystems/Pneumatics.h>
#include <Subsystems/DriveTrain.h>
#include <Subsystems/Intake.h>
#include <Subsystems/Elevator.h>
#include <Subsystems/Temp.h>
#include <Commands/Autonomous.h>

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

	void RobotInit() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;


	//double centerX = -1;
};

#endif  // OI_H
