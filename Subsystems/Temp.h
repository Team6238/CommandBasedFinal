#ifndef Temp_H
#define Temp_H

#include <Commands/Subsystem.h>
#include "wpilib.h"

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <vector>

class Temp : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	double centerX = -1;
	bool pos = 0;

public:
	Temp();
	void InitDefaultCommand();
	void UpdateCenterX(double data);
	double GetCenterX();
	void UpdatePos(bool b);
	bool GetPos();
};

#endif  // Temp_H
