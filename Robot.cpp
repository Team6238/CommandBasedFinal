//#define _GLIBCXX_USE_CXX11_ABI 0
#include <Robot.h>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <vector>

DriveTrain Robot::driveTrain;
//Elevator Robot::elevator;
//Intake Robot::intake;
//Pneumatics Robot::pneumatics;
OI Robot::oi;
double centerX = -1.0;
//VisionModule Robot::vm;

static void VisionThread(){
	cs::UsbCamera camera;
	cs::CvSink cvSink;
	cs::CvSource outputStreamStd;
	camera = CameraServer::GetInstance()->StartAutomaticCapture();
	camera.SetResolution(640, 480);
	cvSink = CameraServer::GetInstance()->GetVideo();
	outputStreamStd = CameraServer::GetInstance()->PutVideo("Raw", 640, 480);
	while (1){
		cv::Mat source;
		cvSink.GrabFrame(source);
		outputStreamStd.PutFrame(source);
		if (!source.empty()){
			grip::TestPipeline gp;
			gp.Process(source);
			std::vector<cv::KeyPoint>* blobs = gp.GetFindBlobsOutput();
			if (blobs->size() == 1)
				centerX = blobs->at(0).pt.x;
			else
				centerX = -1;
			std::cout << "centerX: " << centerX << "\n";
		}
		Wait(1);
	}
}

void Robot::RobotInit(){
	std::thread visionThread(VisionThread);
	visionThread.detach();
}


	void Robot::AutonomousInit()  {

	}

	void Robot::AutonomousPeriodic()  {
		frc::Scheduler::GetInstance()->Run();
	}

	void Robot::TeleopInit() {

	}

	void Robot::TeleopPeriodic()  {
		frc::Scheduler::GetInstance()->Run();
	}

	void Robot::TestPeriodic() {

	}


START_ROBOT_CLASS(Robot)
