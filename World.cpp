#include "iostream"
#include "World.h"

using namespace std;

World::World(int numRows, int numCols) : rows(numRows), cols(numCols), cellList(numRows * numCols) {}


void World::addOrganism(Organism *newOrganism, const Position &position) {

}

void World::removeOrganism(Organism *organismToRemove) {

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