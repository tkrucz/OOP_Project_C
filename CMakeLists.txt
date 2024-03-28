cmake_minimum_required(VERSION 3.27)
project(Code)

set(CMAKE_CXX_STANDARD 17)

add_executable(Code main.cpp
        List.h
        World.h
        World.cpp
        Organism.h
        Organism.cpp
        Define.cpp
        Animal.h
        Plant.h
        Animal.cpp
        Plant.cpp
        GeneralFunctions.h
        GeneralFunctions.cpp
)
