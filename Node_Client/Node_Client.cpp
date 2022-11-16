// Node_Client.cpp : Defines the entry point for the application.
//

#include "Node_Client.h"


using namespace std;

int main()
{
	//Services Needed
	IServerConnection *connection = new MyServerConnection();
	INodeDataHandler *nodeData =  new MyNodeDataHandler(connection);
	//Start program start

	int accumulated = 0;
	float avg;
	for (int i = 1;;i++) {
		vector<NodeReading> buffer(5);
		for (int i = 0; i < 5; i++) {
			buffer[i] = nodeData->getReading();
		}
		for (auto e : buffer) {
			accumulated += e.reading;
		}
		avg = accumulated / i;
		std::cout << "Averagre Reading in Celesius = " << avg << "C ---- Accumulated Reading = " << accumulated << " ---- TimeStamp of Last Reading "<< buffer[4].timeStamp << endl;
		
		if (accumulated >= INT_MAX - 100 && accumulated <= INT_MIN+100) { //preventing accumulated from overflowing
			//Start all over
			accumulated = 0;
			avg = 0;
			i = 0;
		}
	}
	return 0;
}
