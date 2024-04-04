#ifndef CODE_GENERALFUNCTIONS_H
#define CODE_GENERALFUNCTIONS_H

#include "Plant.h"
#include "Animal.h"
#include "Human.h"

void animalStatsInit(); //set basic stats for animals

void plantStatsInit(); //set basic stats for plants

void ageIncrease(Organism &organism);

void introduction(char& key, int &rows, int &columns);

void charDictionary();

void worldInit(int &rows, int &columns);

bool operator==(const Position& lhs, const Position& rhs);

#endif //CODE_GENERALFUNCTIONS_H
