cmake_minimum_required(VERSION 3.28.3)

project(mat_test LANGUAGES C CXX)
cmake_policy(SET CMP0146 OLD)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDS_VERSION_MINOR=1 -DDS_VERSION_MAJOR=5 -std=c++11 -Wall -Ofast -g -Wfatal-errors -D_MWAITXINTRIN_H_INCLUDED")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

message(STATUS "PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")

if(DEFINED ENV{HOME})
    set(HOME_DIR $ENV{HOME})
else()
    message(FATAL_ERROR "Environment variable HOME is not set.")
endif()

message("Home directory: ${HOME_DIR}")

# Set path to the Google Test directory
set(GTEST_DIR ${HOME_DIR}/googletest-release-1.12.1)

# Include directories for Google Test headers
include_directories(${GTEST_DIR}/googletest/include)

# Set the source files
set(SOURCES ${PROJECT_SOURCE_DIR}/mat_test.cpp)

include_directories(${PROJECT_SOURCE_DIR}/../include)

list(APPEND ALL_LIBS
        ${GTEST_DIR}/build/lib
        )

link_directories(${ALL_LIBS})

# Set include directories
add_executable(mat_test ${SOURCES}) 

target_link_libraries(mat_test ${PROJECT_SOURCE_DIR}/../libs/libdeepcortex.so gtest gtest_main)
if(UNIX)
add_definitions(-O2 -pthread)
endif(UNIX)