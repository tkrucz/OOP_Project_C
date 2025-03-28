#include "iostream"
#include "World.h"
#include "algorithm"

using namespace std;

World::World(int numRows, int numCols) : rows(numRows), cols(numCols), cellList(numRows * numCols), organismList(0) {}

void World::addOnlyOrganism(Organism *organism) {
    addOrganism(organism,organism->GetPosition());
}

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
    delete organism;
}

void World::makeTurn() {
    sort(organismList.begin(), organismList.end(), [](Organism *a, Organism *b) {
        if (a->GetInitiative() == b->GetInitiative()) {
            return a->GetAge() < b->GetAge();
        }
        return a->GetInitiative() > b->GetInitiative();
    });
    for(int i=0; i<organismList.size() ; i++) {
        organismList[i]->Action(cellList, organismList, *this, rows, cols);
    }
    for (int i=0; i<organismList.size() ; i++) {
        changeIsBaby(*organismList[i]);
    }
    for (int i=0; i<organismList.size() ; i++) {
        ageIncrease(*organismList[i]);
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

void World::clearConsole() {
    system("cls");
}

World::~World() {}