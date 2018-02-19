#ifndef MoveElevator_H
#define MoveElevator_H

#include <wpilib.h>
class MoveElevator : public Command {
public:
	MoveElevator();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveElevator_H
