#include "iostream"
#include "Plant.h"

using namespace std;

Plant::Plant(int strength, int age, const Position &position, PlantSpecies name)
        : Organism(strength, 0, age, position), name(name) {}

void Plant::Action(Vector<Cell>cellList, Vector<Organism *> organismList, World &world, int &rows, int &cols) {
    // Implement action for plants
    // For example, plants may grow or reproduce in their action method
}

void Plant::Collision(Organism *other_organism, World &world) {
    // Implement collision behavior for plants
    // For example, interaction with other organisms
}

char Plant::Draw() {
    if(name==guarana)
        return '+';
    else if (name == sowThistle)
        return '*';
    else if (name == belladonna)
        return '?';
    else if (name == sosnowskysHogweed)
        return '!';
    else
        return '#';
}

Plant::~Plant() {
    cout << "Plant withered" << endl;
}
