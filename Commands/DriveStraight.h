#ifndef DriveStraight_H
#define DriveStraight_H

#include "wpilib.h"

class DriveStraight : public Command {
public:
	DriveStraight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	Timer *timer;
};

#endif  // DriveStraight_H
