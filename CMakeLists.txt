cmake_minimum_required(VERSION 3.27)
project(Code)

set(CMAKE_CXX_STANDARD 17)

add_executable(Code main.cpp
        World.h
        Organism.h
        Define.cpp
        World.cpp
        Animal.h
        Plant.h
        Animal.cpp
        Plant.cpp
        Organism.cpp)
