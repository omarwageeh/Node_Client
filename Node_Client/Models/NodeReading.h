//Defines a node reading in celcius
#pragma once
#include <ctime>
#include <string>
class NodeReading {
public:
	float reading;
	std::string timeStamp;
	NodeReading() = default;
	NodeReading(float reading, time_t timeStamp) {
		this->reading = reading;
		this->timeStamp = timeStamp;
	}
};