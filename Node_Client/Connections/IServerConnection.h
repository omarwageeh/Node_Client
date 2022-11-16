#pragma once
#include "../Models/NodeReading.h"
__interface IServerConnection {
public:
	NodeReading getData() = 0;
};

