cmake_minimum_required(VERSION 3.15)
project(LR_9)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(LR_9 main.cpp Vector.cpp Vector.h Error.h IndexError.h SizeError.h MaxSizeError.h EmptySizeError.h IndexError1.h IndexError2.h myUtilities.h)