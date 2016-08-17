cmake_minimum_required(VERSION 3.3)
project(ModEngine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Console.cpp Console.h Message.cpp Message.h Agent.cpp Agent.h Gamer.cpp Gamer.h)
add_executable(ModEngine ${SOURCE_FILES})