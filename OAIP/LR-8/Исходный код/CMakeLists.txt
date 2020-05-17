cmake_minimum_required(VERSION 3.15)
project(LR_8)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(LR_8 main.cpp Objecto.cpp Objecto.h Print.cpp Print.h Book.cpp Book.h Vector.cpp Vector.h Event.h Dialog.cpp Dialog.h myUtilities.h)