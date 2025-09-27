cmake_minimum_required(VERSION 4.0)
project(vactionPlanning)

set(CMAKE_CXX_STANDARD 20)

add_executable(vactionPlanning main.cpp
        story1.h
        distance.cpp
        popularFood.cpp
        city.cpp
        utility.cpp)
