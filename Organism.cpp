#include "Organism.h"
#include "World.h"

Organism::Organism(int _strength, int _initiative, int _age, const Position &_position, World *_world)
        : strength(_strength), initiative(_initiative), age(_age), position(_position) {}

int Organism::GetStrength() const {
    return strength;
}

void Organism::SetStrength(int new_strength) {
    strength = new_strength;
}

int Organism::GetInitiative() const {
    return initiative;
}

void Organism::SetInitiative(int new_initiative) {
    initiative = new_initiative;
}

int Organism::GetAge() const {
    return age;
}

void Organism::SetAge(int new_age) {
    age = new_age;
}

Position Organism::GetPosition() const {
    return position;
}

void Organism::SetPosition(const Position &new_position) {
    position = new_position;
}

Organism::~Organism() {
}
