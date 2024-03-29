#include "GeneralFunctions.h"

void animalStatsInit() {
    Animal wolf(9, 5, 0, {0, 0}, AnimalSpecies::wolf);
    Animal sheep(4, 4, 0, {0, 0}, AnimalSpecies::sheep);
    Animal fox(3, 7, 0, {0, 0}, AnimalSpecies::fox);
    Animal turtle(2, 1, 0, {0, 0}, AnimalSpecies::turtle);
    Animal antelope(4, 4, 0, {0, 0}, AnimalSpecies::antelope);
};

void plantStatsInit() {
    Plant grass(0, 0, {0, 0}, PlantSpecies::grass);
    Plant sow_thistle(0, 0, {0, 0}, PlantSpecies::sow_thistle);
    Plant guarana(0, 0, {0, 0}, PlantSpecies::guarana);
    Plant belladonna(99, 0, {0, 0}, PlantSpecies::belladonna);
    Plant Sosnowskys_hogweed(10, 0, {0, 0}, PlantSpecies::Sosnowskys_hogweed);
}

bool cellCheck(Cell &cell) {
    if (cell.isEmpty)
        return true;
    return false;
}

void cellChange(Cell &cell) {
    if (cell.isEmpty)
        cell.isEmpty = false;
    cell.isEmpty = true;
}

void ageIncrease(Organism &organism) {
    int tmp = organism.GetAge();
    organism.SetAge(tmp + 1);
}

bool operator==(const Position &lhs, const Position &rhs) {
    return lhs.cord.x == rhs.cord.x && lhs.cord.y == rhs.cord.y;
}