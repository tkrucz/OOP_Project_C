#ifndef CODE_GENERALFUNCTIONS_H
#define CODE_GENERALFUNCTIONS_H

#include "Plant.h"
#include "Plants/Grass.h"
#include "Plants/SowThistle.h"
#include "Plants/Guarana.h"
#include "Plants/Belladonna.h"
#include "Plants/SosnowskyHogweed.h"

#include "Animal.h"
#include "Human.h"
#include "Animals/Wolf.h"
#include "Animals/Sheep.h"
#include "Animals/Fox.h"
#include "Animals/Antelope.h"
#include "Animals/Turtle.h"

void ageIncrease(Organism &organism);

void changeIsBaby(Organism & organism);

void nameDisplay();

void introduction(char &key, int &rows, int &columns);

void charDictionary();

void worldInit(int &rows, int &columns);

void gameLoop(World &world, int &rows, int &columns);

void saveGame(World &world, int &rows, int &columns);

World loadGame();

bool operator==(const Position &lhs, const Position &rhs);

#endif //CODE_GENERALFUNCTIONS_H
