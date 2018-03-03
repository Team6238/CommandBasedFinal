//#define _GLIBCXX_USE_CXX11_ABI 0
#ifndef Pneumatics_H
#define Pneumatics_H

#include <Commands/Subsystem.h>
#include <wpilib.h>

#define NSolenoids 2

class Pneumatics : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Solenoid *solenoids[NSolenoids];
	bool states[NSolenoids];
	Compressor *compressor;

public:
	Pneumatics();
	void InitDefaultCommand();
	void FlipSolenoid(int i);
};

#endif  // Pneumatics_H
