#ifndef Intake_H
#define Intake_H

#include <wpilib.h>
#include "ctre/Phoenix.h"
#include <Commands/Subsystem.h>

class Intake : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	WPI_TalonSRX leftTalon{37}, rightTalon{38};

public:
	Intake();
	void InitDefaultCommand();
	void Set(int direction);
};

#endif  // Intake_H
