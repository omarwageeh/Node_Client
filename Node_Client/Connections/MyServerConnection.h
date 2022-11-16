#pragma once
#include "../Connections/IServerConnection.h"
class MyServerConnection : public IServerConnection {
public:
	MyServerConnection() = default;

	 NodeReading getData() {
		NodeReading nodeReading;
		nodeReading.reading = float(rand()%101)/((rand()%100)+1) * (-1 * rand() % 2);
		time_t now = time(0); // get current time;
		nodeReading.timeStamp = ctime(&now);
		return nodeReading;
	}
};