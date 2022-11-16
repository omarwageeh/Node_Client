# CMakeList.txt : CMake project for Node_Client, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Node_Client "Node_Client.cpp" "Node_Client.h" "Includes/NodeDataHandler.h" "Models/NodeReading.h"  "Handlers/MyServerConnection.cpp" "Includes/ServerConnection.h" "Includes/MyServerConnection.h"  "Includes/MyNodeDataHandler.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Node_Client PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
