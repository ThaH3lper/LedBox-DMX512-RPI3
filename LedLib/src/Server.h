#ifndef SERVER_H
#define SERVER_H
#include "SharedMemory/SharedMemory.h"
#include "Behavior/FadeToSimple.hpp"
#include "Behavior/BootBehavior.hpp"
#include "Dmx/DmxController.h"
#include <unistd.h> //Sleep
#include <chrono>
#include <string.h>
#include "global.h"
#include "Selector/Selector.hpp"

class Server {

private:
	SharedMemory mSMServerStatus;
	SharedMemory mSMData;
	BaseBehavior* mBehaviors[10];
	DmxController mDmxController;
	Selector mSelector;

	double update(double delta);

public:

	Server();

	void start();

	void stop();

};

#endif