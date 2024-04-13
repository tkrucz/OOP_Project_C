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
        Animals/Wolf.h
        Animals/Wolf.cpp
        Animals/Sheep.h
        Animals/Sheep.cpp
        Plants/Grass.h
        Plants/Grass.cpp
        Plants/SowThistle.h
        Plants/SowThistle.cpp
        Plants/Guarana.h
        Plants/Guarana.cpp
        Plants/Belladonna.h
        Plants/Belladonna.cpp
        Plants/SosnowskyHogweed.h
        Plants/SosnowskyHogweed.cpp
        Animals/Fox.h
        Animals/Fox.cpp
        Animals/Turtle.cpp
        Animals/Antelope.cpp
)
