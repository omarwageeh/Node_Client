# Node_Client
1. Utilized CMake Build System as it is widely used in C++ and has multiplatform support and it makes for seemeless integration with many IDE's and compilers.
2.Chose GitHub as VCS
3.Client design:

I opted for abstracting as much as possible of the "services" used in the application 
``` cpp 
#pragma once
#include "../Models/NodeReading.h"
__interface IServerConnection {
public:
	NodeReading getData() = 0;
};

```
