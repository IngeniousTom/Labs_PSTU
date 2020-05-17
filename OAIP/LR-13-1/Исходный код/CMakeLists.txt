cmake_minimum_required(VERSION 3.15)
project(LR_13_1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(LR_13_1 main.cpp Time.h Time.cpp myUtilities.h)