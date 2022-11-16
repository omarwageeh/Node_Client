#pragma once
#include "../Models/NodeReading.h"
__interface INodeDataHandler {
public:
	virtual NodeReading getReading() = 0;
};