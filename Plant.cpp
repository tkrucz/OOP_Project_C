#include "iostream"
#include "Plant.h"

using namespace std;

Plant::Plant(int strength, int age, const Position &position, PlantSpecies name)
        : Organism(strength, 0, age, position, nullptr), name(name) {}

void Plant::Action(Vector<Cell>cellList, int &rows, int &cols) {
    // Implement action for plants
    // For example, plants may grow or reproduce in their action method
}

void Plant::Collision(Organism *other_organism) {
    // Implement collision behavior for plants
    // For example, interaction with other organisms
}

char Plant::Draw() {
    if(name==guarana)
        return '+';
    else if (name == sow_thistle)
        return '*';
    else if (name == belladonna)
        return '?';
    else if (name == Sosnowskys_hogweed)
        return '!';
    else
        return '#';
}

Plant::~Plant() {
    cout << "Plant withered" << endl;
}
