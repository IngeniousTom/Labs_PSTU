cmake_minimum_required(VERSION 3.15)
project(LR_7)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(LR_7 main.cpp Vector.cpp Vector.h Time.cpp Time.h myUtilities.h)