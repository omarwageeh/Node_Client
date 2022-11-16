#include "../Includes/MyNodeDataHandler.h"
class MyNodeDataHandler : public NodeDataHandler {
private:
	MyServerConnection serverConnection;
public:
	MyNodeDataHandler(MyServerConnection serverConnection) {
		this->serverConnection = serverConnection;
	}
	NodeReading getReading() override{
		return serverConnection.getData();
	}
};