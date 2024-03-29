#include "iostream"
#include "World.h"

using namespace std;

World::World(int numRows, int numCols) : rows(numRows), cols(numCols), cellList(numRows * numCols), organismList(0) {}


void World::addOrganism(Organism *newOrganism, const Position &position) {
    newOrganism->SetPosition(position); // Set position for this organism
    organismList.push_back(newOrganism); // Add new organism to Vector of organisms
    int index = position.cord.y * cols + position.cord.x;
    cellList.setElement(index, {position, false});
}

void World::removeOrganism(Organism *organism) {
    Position position = organism->GetPosition();
    int index = position.cord.y * cols + position.cord.x;
    cellList.setElement(index, {position, true});

    // Find and remove the organism from the organismList
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
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << "*";
        cout << endl;
    }
}

World::~World() { //REMEMBER TO FREE MEMORY
    cout << "World destruction" << endl;
}