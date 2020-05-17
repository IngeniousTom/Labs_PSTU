cmake_minimum_required(VERSION 3.15)
project(LR_10)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(LR_10 main.cpp Time.cpp Time.h FileWork.h myUtilities.h)