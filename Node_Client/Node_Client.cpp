// Node_Client.cpp : Defines the entry point for the application.
//

#include "Node_Client.h"


using namespace std;

int main()
{
	MyServerConnection *connection = new MyServerConnection();
	MyNodeDataHandler *nodeData =  new MyNodeDataHandler(*connection);
	while (true) {
		vector<NodeReading> buffer(5);
		for (int i = 0; i < 5; i++) {
			NodeReading buffer = nodeData->getReading();
			cout << buffer.reading<< "      " << buffer.timeStamp << endl;
		}
		_sleep(5000);
	}
	return 0;
}
