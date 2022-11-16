#pragma once
#include "../Models/NodeReading.h"
class NodeDataHandler {
public:
	virtual NodeReading getReading() = 0;
};