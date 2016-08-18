cmake_minimum_required(VERSION 2.8)
project(Drunken-Algorithms)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Wno-unused-parameter")
file(GLOB_RECURSE Drunken-Algorithms_SOURCES "src/*.cpp")
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/includes/)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/src/)

add_executable(Drunken-Algorithms main.cpp ${Drunken-Algorithms_SOURCES})