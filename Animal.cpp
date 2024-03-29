#include "iostream"
#include "Animal.h"

using namespace std;

Animal::Animal(int _strength, int _initiative, int _age, const Position &_position, AnimalSpecies _name)
        : Organism(_strength, _initiative, _age, _position, nullptr), name(_name) {}

AnimalSpecies Animal::getSpecies() const {
    return name;
}

void Animal::setSpecies(AnimalSpecies new_name) {
    name = new_name;
}

void Animal::Action() {
    // Implement action for animals
    // For example, animals may move or perform specific actions in their action method
}

void Animal::Collision(Organism *other_organism) {
    // Implement collision behavior for animals
    // For example, interaction with other organisms
}

char Animal::Draw() {
    if(name==wolf)
        return 'W';
    else if (name == sheep)
        return 'S';
    else if (name == fox)
        return 'F';
    else if (name == turtle)
        return 'T';
    else if (name == antelope)
        return 'A';
    else
        return 'H';
}

Animal::~Animal() {
    cout << "Animal was killed" << endl;
}

