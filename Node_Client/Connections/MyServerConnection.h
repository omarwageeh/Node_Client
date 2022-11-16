#pragma once
#include "ServerConnection.h"
class MyServerConnection : public ServerConnection {
public:
	MyServerConnection() = default;

	 NodeReading getData() override{
		NodeReading nodeReading;
		nodeReading.reading = float(rand()%101)/((rand()%100)+1);
		time_t now = time(0); // get current time;
		nodeReading.timeStamp = ctime(&now);
		return nodeReading;
	}
};