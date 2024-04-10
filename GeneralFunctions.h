#ifndef CODE_GENERALFUNCTIONS_H
#define CODE_GENERALFUNCTIONS_H

#include "Plant.h"
#include "Animal.h"
#include "Human.h"

void ageIncrease(Organism &organism);

void changeIsBaby(Organism & organism);

void nameDisplay();

void introduction(char& key, int &rows, int &columns);

void charDictionary();

void worldInit(int &rows, int &columns);

bool operator==(const Position& lhs, const Position& rhs);

void gameLoop(World &world); //main game loop <-- Has to be changed !!

void clearScreen(); //<-- Has to be changed!!

#endif //CODE_GENERALFUNCTIONS_H
