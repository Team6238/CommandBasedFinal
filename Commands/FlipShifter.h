#ifndef FlipShifter_H
#define FlipShifter_H

#include "wpilib.h"

class FlipShifter : public Command {
public:
	FlipShifter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // FlipShifter_H
