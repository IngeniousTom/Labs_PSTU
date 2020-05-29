cmake_minimum_required(VERSION 3.16)
project(LR_15)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(LR_15 main.cpp Components/HashTable.cpp Components/HashTable.h Components/Data.cpp Components/Data.h myUtilities.h Components/DataGenerator.cpp Components/DataGenerator.h Components/Manager.cpp Components/Manager.h Event.h Components/Dialog.h Components/Dialog.cpp constants.h structs.h)