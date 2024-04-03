#include "iostream"
#include "World.h"

using namespace std;

World::World(int numRows, int numCols) : rows(numRows), cols(numCols), cellList(numRows * numCols), organismList(0) {}

void World::addOrganism(Organism *newOrganism, const Position &position) {
    newOrganism->SetPosition(position);
    organismList.push_back(newOrganism);
    int index = position.cord.y * cols + position.cord.x;
    cellList[index] = {position, false}; // Direct access using operator[]
}

void World::removeOrganism(Organism *organism) {
    Position position = organism->GetPosition();
    int index = position.cord.y * cols + position.cord.x;
    cellList[index] = {position, true}; // Direct access using operator[]

    for (auto it = organismList.begin(); it != organismList.end(); ++it) {
        if (*it == organism) {
            organismList.erase(it);
            break;
        }
    }
}

void World::makeTurn() {
    for (auto organism : organismList) {
        organism->Action(cellList, organismList, *this, rows, cols);
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
                for (auto organism : organismList) {
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

World::~World() {
    cout << "World destruction" << endl;
}