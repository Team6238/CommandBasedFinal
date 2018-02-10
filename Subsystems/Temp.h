#ifndef Temp_H
#define Temp_H

#include <Commands/Subsystem.h>
#include "wpilib.h"

class Temp : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	double centerX;
public:
	Temp();
	void InitDefaultCommand();
	void UpdateCenterX(double value);
	double GetCenterX();
};

#endif  // Temp_H
