#include "Plant.h"
#include "World.h"

using namespace std;

Plant::Plant(int strength, const Position &position, PlantSpecies name)
        : Organism(strength, 0, 0, position), name(name) {}

void Plant::Action(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows, int &columns) {}

void Plant::Collision(vector<Cell> &cellList, vector<Organism *> &organismList, Organism *otherOrganism, World &world,
                      int &rows, int &columns) {
    // Set that cell is empty
    cellList[(position.cord.y * columns) + position.cord.x].isEmpty = true;
    // Remove the plant from the world after being eaten
    world.removeOrganism(this);
}

char Plant::Draw() {}

string Plant::nameToString() {}

int Plant::GetEnum() {}

AnimalSpecies Plant::GetName() {
    return notAnimal;
}