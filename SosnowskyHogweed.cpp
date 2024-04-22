#include "SosnowskyHogweed.h"
#include "iostream"

using namespace std;

SosnowskyHogweed::SosnowskyHogweed(const Position &position) : Plant(10, position, sosnowskysHogweed) {}

//Kills every animal in its immediate neighborhood
void SosnowskyHogweed::Action(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows,
                              int &columns) {
    int xCord = position.cord.x, yCord = position.cord.y;
    Organism *otherOrganism = nullptr;
    if (yCord - 1 >= 0 && !cellList[((yCord - 1) * columns) + xCord].isEmpty) {
        otherOrganism = findOrganismAtPosition({xCord, yCord - 1}, organismList, cellList, columns);
        if (auto *animal = dynamic_cast<Animal *>(otherOrganism)) {
            cout << "Sosnowsky's hogweed kill " << otherOrganism->nameToString() << endl;
            world.removeOrganism(animal);
            cellList[((yCord - 1) * columns) + xCord].isEmpty = true;
        }
    }
    if (yCord + 1 < rows && !cellList[((yCord + 1) * columns) + xCord].isEmpty) {
        otherOrganism = findOrganismAtPosition({xCord, yCord + 1}, organismList, cellList, columns);
        if (auto *animal = dynamic_cast<Animal *>(otherOrganism)) {
            cout << "Sosnowsky's hogweed kill " << otherOrganism->nameToString() << endl;
            world.removeOrganism(animal);
            cellList[((yCord + 1) * columns) + xCord].isEmpty = true;
        }
    }
    if (xCord - 1 >= 0 && !cellList[(yCord * columns) + (xCord - 1)].isEmpty) {
        otherOrganism = findOrganismAtPosition({xCord - 1, yCord}, organismList, cellList, columns);
        if (auto *animal = dynamic_cast<Animal *>(otherOrganism)) {
            cout << "Sosnowsky's hogweed kill " << otherOrganism->nameToString() << endl;
            world.removeOrganism(animal);
            cellList[(yCord * columns) + (xCord - 1)].isEmpty = true;
        }
    }
    if (xCord + 1 < columns && !cellList[(yCord * columns) + (xCord + 1)].isEmpty) {
        otherOrganism = findOrganismAtPosition({xCord + 1, yCord}, organismList, cellList, columns);
        if (auto *animal = dynamic_cast<Animal *>(otherOrganism)) {
            cout << "Sosnowsky's hogweed kill " << otherOrganism->nameToString() << endl;
            world.removeOrganism(animal);
            cellList[(yCord * columns) + (xCord + 1)].isEmpty = true;
        }
    }
}

void SosnowskyHogweed::Collision(vector<Cell> &cellList, vector<Organism *> &organismList, Organism *otherOrganism,
                                 World &world, int &rows, int &columns) {
    if (auto *animal = dynamic_cast<Animal *>(otherOrganism)) {
            cout << "Predator " << animal->nameToString() << " ate sosnowsky's hogweed and died!" << endl;
            cellList[(animal->GetPosition().cord.y * columns) + animal->GetPosition().cord.x].isEmpty = true;
            world.removeOrganism(animal);
        }
    Plant::Collision(cellList,organismList,otherOrganism,world,rows,columns);
}

char SosnowskyHogweed::Draw() {
    return '!';
}

string SosnowskyHogweed::nameToString() {
    return "sosnowsky's hogweed";
}

int SosnowskyHogweed::GetEnum() {
    return 4;
}