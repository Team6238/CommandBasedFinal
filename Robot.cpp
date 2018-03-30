//#define _GLIBCXX_USE_CXX11_ABI 0
#include <Robot.h>

DriveTrain Robot::driveTrain;
Elevator Robot::elevator;
Intake Robot::intake;
Pneumatics Robot::pneumatics;
OI Robot::oi;
Temp Robot::temp;

bool comp(double a, double b){
	return a > b;
}

static void VisionThread(){
	cs::UsbCamera camera;
	cs::CvSink cvSink;
	cs::CvSource outputStreamStd;
	camera = CameraServer::GetInstance()->StartAutomaticCapture();
	camera.SetResolution(640, 480);
	cvSink = CameraServer::GetInstance()->GetVideo();
	outputStreamStd = CameraServer::GetInstance()->PutVideo("Raw", 640, 480);
	cv::Mat source;
	grip::FindContours gp;
	bool pos = Robot::temp.GetPos();
	SmartDashboard::PutBoolean("visionPos", pos);
	while (1){
		cvSink.GrabFrame(source);
		outputStreamStd.PutFrame(source);
		if (!source.empty()){
			gp.Process(source);
			std::vector<std::vector<cv::Point>>* contours = gp.GetFilterContoursOutput();
			std::vector<double> centers;
			for (unsigned int i = 0; i < contours->size(); i++){
				cv::RotatedRect temp = cv::minAreaRect(contours->at(i));
				centers.push_back(temp.center.x);
			}
			double centerX = -1;
			if (centers.size()>1){
				if (!pos)
					sort(centers.begin(), centers.begin()+centers.size());
				else
					sort(centers.begin(), centers.begin()+centers.size(), comp);
				centerX = (centers.at(0)+centers.at(1))/2.0;
			}
			Robot::temp.UpdateCenterX(centerX);
			SmartDashboard::PutNumber("NContours", centers.size());
			SmartDashboard::PutNumber("centerX", centerX);
		}
	}
}


void Robot::RobotInit(){
	rpc = new SendableChooser<bool>();
	rpc->AddObject("right", 1);
	rpc->AddObject("left", 0);
	SmartDashboard::PutData("robot starting position chooser", rpc);
	tfc = new SendableChooser<bool>();
	tfc->AddObject("get switch", 1);
	tfc->AddObject("drive straight", 0);
	SmartDashboard::PutData("autonomous goal", tfc);
	std::thread visionThread(VisionThread);
	visionThread.detach();
}

void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic(){
}

void Robot::AutonomousInit()  {
	std::string s = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	bool switchPos = s.length() > 0 && s.at(0) == 'R';
	switchPosition = switchPos;
	Robot::temp.UpdatePos(switchPos);
	Command* auton = new Autonomous(switchPos, (bool)rpc->GetSelected(), (bool)tfc->GetSelected());
	auton->Start();
}

void Robot::AutonomousPeriodic()  {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	//autonomous->Cancel();
	flip->Start();
}

void Robot::TeleopPeriodic()  {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {

}


START_ROBOT_CLASS(Robot)
