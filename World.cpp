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

void World::drawWorld() {

}

World::~World() { //REMEMBER TO FREE MEMORY
    cout << "World destruction" << endl;
}