cmake_minimum_required(VERSION 3.27)
project(Code)

set(CMAKE_CXX_STANDARD 17)

add_executable(Code main.cpp
        World.h
        World.cpp
        Organism.h
        Organism.cpp
        Define.cpp
        Animal.h
        Animal.cpp
        Plant.h
        Plant.cpp
        GeneralFunctions.h
        GeneralFunctions.cpp
        Human.h
        Human.cpp
)
