# Node_Client
###### 1. Utilized CMake Build System as it is widely used in C++ and has multiplatform support and it makes for seemeless integration with many IDE's and compilers.

#### Client design:

###### I opted for abstracting as much as possible of the "services" used in the application 
``` cpp 
__interface IServerConnection {
public:
	NodeReading getData() = 0;
};

```
```cpp


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
```
###### using Dependency Injection to evade from rewriting code and make it as modular as possible.

###### ```getData()``` functions is used as a mockup for the actual data received from the server
```cpp
NodeReading getData() {
		NodeReading nodeReading;
		nodeReading.reading = float(rand()%101)/((rand()%100)+1) * (-1 * rand() % 2);
		time_t now = time(0); // get current time;
		nodeReading.timeStamp = ctime(&now);
		return nodeReading;
	}
```
###### ```getData()``` returns a model of ```NodeReading``` which has a reading member and timeStamp
```cpp
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
```
###### The main function is where Services are assigned
```cpp
IServerConnection *connection = new MyServerConnection();
INodeDataHandler *nodeData =  new MyNodeDataHandler(connection);
```
###### The program then calls the mock server
```cpp
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

```
