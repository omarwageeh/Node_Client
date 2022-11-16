#pragma once
#include "../Handlers/NodeDataHandler.h"
#include "../Connections/MyServerConnection.h"
class MyNodeDataHandler : public NodeDataHandler {
private:
	MyServerConnection serverConnection;
public:
	MyNodeDataHandler(MyServerConnection serverConnection) {
		this->serverConnection = serverConnection;
	}
	NodeReading getReading() override {
		_sleep(1000);
		return serverConnection.getData();
	}
};