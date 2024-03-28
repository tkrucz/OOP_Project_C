#include "iostream"
#include "Plant.h"

using namespace std;

Plant::Plant(int strength, const Position& position, PlantSpecies name)
        : Organism(strength, 0, position, nullptr), name(name) {}

int Plant::GetStrength() const {
    return strength;
}

void Plant::SetStrength(int new_strength) {
    strength = new_strength;
}

Position Plant::GetPosition() const {
    return position;
}

void Plant::SetPosition(const Position& new_position) {
    position = new_position;
}

PlantSpecies Plant::GetName() const {
    return name;
}

void Plant::SetName(PlantSpecies new_name) {
    name = new_name;
}

void Plant::Action() {
    // Implement action for plants
    // For example, plants may grow or reproduce in their action method
}

void Plant::Collision(Organism* other_organism) {
    // Implement collision behavior for plants
    // For example, interaction with other organisms
}

char Plant::Draw() {
    // Implement drawing for plants
    // Return a character representing the plant
    // For example, return 'T' for tree or 'F' for flower
    return 'P'; // Placeholder character
}

Plant::~Plant() {
    cout << "Plant withered" << endl;
}
