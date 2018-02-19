#ifndef MoveIntake_H
#define MoveIntake_H

#include <wpilib.h>

class MoveIntake : public Command {
public:
	MoveIntake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveIntake_H
