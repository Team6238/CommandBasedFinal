#ifndef Turn_H
#define Turn_H

#include "wpilib.h"

class Turn : public Command {
public:
	Turn(int target);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	Timer *timer;
	double timeF;
	int direction; //-1 = turn left, 1 = turn right
};

#endif  // Turn_H
