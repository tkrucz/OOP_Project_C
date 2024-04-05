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

void Organism::SetInitiative(int newInitiative) {
    initiative = newInitiative;
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

Organism *Organism::findOrganismAtPosition(const Position &position, const std::vector<Organism *> &organismList,
                                           const std::vector<Cell> &cellList, int columns) {
    int xCord = position.cord.x;
    int yCord = position.cord.y;
    Position newCell = cellList[(yCord * columns) + xCord].cellCord;
    for (int i = 0; i < organismList.size(); ++i) {
        if (newCell == organismList[i]->GetPosition()) {
            return organismList[i];
        }
    }
    return nullptr;
}

Organism::~Organism() {
}
