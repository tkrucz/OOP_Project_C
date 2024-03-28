#ifndef CODE_GENERALFUNCTIONS_H
#define CODE_GENERALFUNCTIONS_H

#include "Plant.h"
#include "Animal.h"

void animalStatsInit(); //set basic stats for animals

void plantStatsInit(); //set basic stats for plants

bool cellCheck(Cell &cell); //check if cell is empty

void cellChange(Cell &cell); //change cell "flag"

void ageIncreasing(Organism &organism);

bool operator==(const Position& lhs, const Position& rhs);

#endif //CODE_GENERALFUNCTIONS_H
