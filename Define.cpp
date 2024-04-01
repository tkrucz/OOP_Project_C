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
    sowThistle,
    guarana,
    belladonna,
    sosnowskysHogweed
};

struct Cell{
    Position cellCord;
    bool isEmpty = true;
};