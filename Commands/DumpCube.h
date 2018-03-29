#ifndef DumpCube_H
#define DumpCube_H

#include "wpilib.h"

class DumpCube : public Command {
public:
	DumpCube();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	Timer *timer;
};

#endif  // DumpCube_H
