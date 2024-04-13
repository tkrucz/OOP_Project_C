#include "iostream"
#include "World.h"
#include "algorithm"

using namespace std;

World::World(int numRows, int numCols) : rows(numRows), cols(numCols), cellList(numRows * numCols), organismList(0) {}

void World::addOrganism(Organism *newOrganism, const Position &position) {
    newOrganism->SetPosition(position);
    organismList.push_back(newOrganism);
    int index = position.cord.y * cols + position.cord.x;
    cellList[index] = {position, false};
}

void World::removeOrganism(Organism *organism) {
    for (auto i = organismList.begin(); i != organismList.end(); ++i) {
        if (*i == organism) {
            organismList.erase(i);
            break;
        }
    }
}

void World::makeTurn() {
    sort(organismList.begin(), organismList.end(), [](Organism *a, Organism *b) {
        if (a->GetInitiative() == b->GetInitiative()) {
            return a->GetAge() < b->GetAge();
        }
        return a->GetInitiative() > b->GetInitiative();
    });
    for (Organism *organism: organismList) {
        organism->Action(cellList, organismList, *this, rows, cols);
    }
    for (Organism *organism: organismList) {
        changeIsBaby(*organism);
    }
    for (Organism *organism: organismList) {
        ageIncrease(*organism);
    }
}

void World::drawWorld() const {
    cout << "WORLD STATUS :" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = i * cols + j;
            if (cellList[index].isEmpty)
                cout << "_";
            else {
                for (auto organism: organismList) {
                    if (organism->GetPosition().cord.x == j &&
                        organism->GetPosition().cord.y == i) {
                        cout << organism->Draw();
                        break;
                    }
                }
            }
        }
        cout << endl;
    }
    cout << endl; // New line after printing the world
}

const vector<Organism *> World::getOrganismList() const {
    return organismList;
}

void World::clearConsole() const {
    cout << "\33[2J\033[H";
}

World::~World() {
    cout << "World destruction" << endl;
}