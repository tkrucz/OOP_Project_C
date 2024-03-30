#include "iostream"
#include "World.h"

using namespace std;

World::World(int numRows, int numCols) : rows(numRows), cols(numCols), cellList(numRows * numCols), organismList(0) {}


void World::addOrganism(Organism *newOrganism, const Position &position) {
    newOrganism->SetPosition(position);
    organismList.push_back(newOrganism);
    int index = position.cord.y * cols + position.cord.x;
    cellList.setElement(index, {position, false});
}

void World::removeOrganism(Organism *organism) {
    Position position = organism->GetPosition();
    int index = position.cord.y * cols + position.cord.x;
    cellList.setElement(index, {position, true});

    for (int i = 0; i < organismList.Size(); ++i) {
        if (organismList.getElement(i) == organism) {
            organismList.erase(i);
            break;
        }
    }
}


void World::makeTurn() {

}

void World::drawWorld() const {
    cout << "WORLD STATUS :" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = i * cols + j;
            if (cellList.getElement(index).isEmpty)
                cout << "_";
            else {
                for (int k = 0; k < organismList.Size(); ++k) {
                    if (organismList.getElement(k)->GetPosition().cord.x == j &&
                        organismList.getElement(k)->GetPosition().cord.y == i) {
                        cout << organismList.getElement(k)->Draw();
                        break;
                    }
                }
            }
        }
        cout << endl;
    }
    cout << endl; //New line after printing the world
}

World::~World() { //REMEMBER TO FREE MEMORY
    cout << "World destruction" << endl;
}