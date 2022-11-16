//Defines a node reading in celcius
#pragma once
#include <ctime>
#include <string>
class NodeReading {
public:
	float reading;
	std::string timeStamp;
	NodeReading() = default;
	NodeReading(float reading, std::string timeStamp);
};