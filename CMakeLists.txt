cmake_minimum_required(VERSION 3.27)
project(dictionary)

set(CMAKE_CXX_STANDARD 17)

add_executable(dictionary main.cpp
        dictionary.h
        dictionary.cpp
        dictionary.cpp)
