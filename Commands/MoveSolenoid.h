#ifndef MoveSolenoid_H
#define MoveSolenoid_H

#include <wpilib.h>
#include <Commands/Command.h>

class MoveSolenoid : public Command {
public:
	MoveSolenoid();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

};

#endif  // MoveSolenoid_H
