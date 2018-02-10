//#define _GLIBCXX_USE_CXX11_ABI 0

#ifndef TankDrive_H
#define TankDrive_H
#include "wpilib.h"
#include <Commands/Command.h>

class TankDrive : public Command {
public:
	TankDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TankDrive_H
