cmake_minimum_required(VERSION 3.1)
project(kinSpin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(kinSpin ${SOURCE_FILES} kinematics.cpp kinematics.h unitTesting.cpp unitTesting.h)