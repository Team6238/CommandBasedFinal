#include "Autonomous.h"

Autonomous::Autonomous() {
	AddSequential(new DriveToTarget());
}

