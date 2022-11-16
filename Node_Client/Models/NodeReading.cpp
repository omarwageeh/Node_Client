#inlcude "NodeReading.h"

class NodeReading {
public:
	float reading;
	string timeStamp;
	NodeReading(float reading, time_t timeStamp) {
		this->reading = reading;
		this->timeStamp = timeStamp;
	}
};