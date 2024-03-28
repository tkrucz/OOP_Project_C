#pragma once

struct Coordinates{
    int x;
    int y;
};

struct Position{
    Coordinates cord;
};

enum AnimalSpecies{
    wolf,
    sheep,
    fox,
    turtle,
    antelope
};

enum PlantSpecies{
    grass,
    sow_thistle,
    guarana,
    belladonna,
    Sosnowskys_hogweed
};

struct Cell{
    Position cellCord;
    bool isEmpty = false;
};