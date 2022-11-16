#include "../Includes/MyServerConnection.h"

class MyServerConnection : public ServerConnection {
public:
	MyServerConnection() = default;
	 NodeReading getData() override{
		NodeReading nodeReading;
		nodeReading.reading = float(rand()%303)/3;
		time_t now = time(0); // get current time;
		nodeReading.timeStamp = ctime(&now);
		return nodeReading;
	}
};