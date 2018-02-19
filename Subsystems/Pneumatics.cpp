#include "Pneumatics.h"
#include "wpilib.h"

Pneumatics::Pneumatics() : Subsystem("Pneumatics") {
	solenoid = new frc::Solenoid(0);
	compressor = new frc::Compressor(0);
	state = 0;
}

void Pneumatics::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands
void Pneumatics::FlipSolenoid(){
	solenoid->Set(state);
	state = !state;
}

