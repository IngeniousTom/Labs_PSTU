cmake_minimum_required(VERSION 3.15)
project(LR_14)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(LR_14 main.cpp myUtilities.h Event.h Components/Dialog.h Components/Dialog.cpp Components/Manager.cpp Components/Manager.h structs.h constants.h Components/DBConnectSystem.cpp Components/DBConnectSystem.h Components/DBProcessor.cpp Components/DBProcessor.h Components/IOSystem.cpp Components/IOSystem.h Exceptions/ConnectException.h Exceptions/FileNotFoundException.h Exceptions/Exception.h Exceptions/FileCreateException.h Exceptions/FileWriteException.h Exceptions/FileOpenException.h Exceptions/FileReadException.h Exceptions/EntryNotFoundException.h Exceptions/WrongPositionException.h Exceptions/RuntimeException.h)