cmake_minimum_required(VERSION 3.15)
project(LR_5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(LR_5 main.cpp Pair.cpp Pair.h Complex.cpp Complex.h Objecto.cpp Objecto.h Vector.cpp Vector.h myUtilities.h)