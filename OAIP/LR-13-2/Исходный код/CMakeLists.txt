cmake_minimum_required(VERSION 3.16)
project(LR_13_2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(LR_13_2 main.cpp Time.h Time.cpp myUtilities.h)