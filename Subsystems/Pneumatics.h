//#define _GLIBCXX_USE_CXX11_ABI 0
#ifndef Pneumatics_H
#define Pneumatics_H

#include <Commands/Subsystem.h>
#include <wpilib.h>

class Pneumatics : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Solenoid *solenoid;
	Compressor *compressor;
	bool state;

public:
	Pneumatics();
	void InitDefaultCommand();
	void FlipSolenoid();
};

#endif  // Pneumatics_H
