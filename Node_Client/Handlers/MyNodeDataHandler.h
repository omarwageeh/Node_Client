#pragma once
#include "../Handlers/INodeDataHandler.h"
#include "../Connections/IServerConnection.h"
class MyNodeDataHandler : public INodeDataHandler {
private:
	IServerConnection *serverConnection;
public:
	MyNodeDataHandler(IServerConnection *serverService)
		: serverConnection(serverService) {
		if (serverService == nullptr)
			throw std::invalid_argument("Server Service must not be null");
	}
	NodeReading getReading() override {
		_sleep(1000);
		return serverConnection->getData();
	}
};