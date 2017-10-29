cmake_minimum_required(VERSION 3.8)
project(c__)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Time.cpp Time.h Schedule.cpp Schedule.h)
add_executable(c__ ${SOURCE_FILES})