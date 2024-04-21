cmake_minimum_required(VERSION 3.28.3)
project(deepcortex)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3 -g -Wall -Wextra -Wpedantic -Wfatal-errors -shared -fPIC")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

# Set the source files
set(SOURCES src/mat.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)

# Create the library
add_library(deepcortex SHARED ${SOURCES})

set_target_properties(deepcortex PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/libs)
if(UNIX)
add_definitions(-O2 -pthread)
endif(UNIX)