#ifndef MoveSolenoid_H
#define MoveSolenoid_H

#include <wpilib.h>
#include <Commands/Command.h>

class MoveSolenoid : public Command {
public:
	MoveSolenoid(int i);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	int target;

};

#endif  // MoveSolenoid_H
