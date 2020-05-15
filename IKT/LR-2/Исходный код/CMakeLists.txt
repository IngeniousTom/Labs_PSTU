cmake_minimum_required(VERSION 3.15)
project(LR_2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(LR_2 main.cpp Number.cpp Number.h myUtilities.h)