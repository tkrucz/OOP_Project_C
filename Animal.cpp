#include "iostream"
#include "Animal.h"

using namespace std;

Animal::Animal(int _strength, int _initiative, int _age, const Position &_position, AnimalSpecies _name)
        : Organism(_strength, _initiative, _age, _position, nullptr), name(_name) {}

void Animal::Action() {
    //Add random movement for animals
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

