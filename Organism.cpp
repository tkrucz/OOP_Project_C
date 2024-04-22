#include "Organism.h"
#include "World.h"

Organism::Organism(int _strength, int _initiative, int _age, const Position &_position)
        : strength(_strength), initiative(_initiative), age(_age), position(_position) {}

int Organism::GetStrength() const {
    return strength;
}

void Organism::SetStrength(int newStrength) {
    strength = newStrength;
}

int Organism::GetInitiative() const {
    return initiative;
}

int Organism::GetAge() const {
    return age;
}

void Organism::SetAge(int newAge) {
    age = newAge;
}

Position Organism::GetPosition() const {
    return position;
}

void Organism::SetPosition(const Position &newPosition) {
    position = newPosition;
}

Organism *Organism::findOrganismAtPosition(const Position &position, const vector<Organism *> &organismList,
                                           const vector<Cell> &cellList, int columns) {
    int xCord = position.cord.x;
    int yCord = position.cord.y;
    Cell cell = cellList[(yCord * columns) + xCord];

    if (cell.isEmpty) {
        return nullptr;
    }

    for (int i=0; i<organismList.size() ; i++) {
        if (organismList[i]->GetPosition() == cell.cellCord) {
            return organismList[i];
        }
    }
    return nullptr;
}

Organism::~Organism() {}
