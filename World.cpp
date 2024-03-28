#include "iostream"
#include "World.h"

using namespace std;

World::World(int numRows, int numCols) : rows(numRows), cols(numCols) {

}

//void World::addOrganism(Organism* organism, const Position& position) {
//
//}
//
//void World::removeOrganism(Organism* organism) {
//
//}
//
//void World::makeTurn() {
//
//}
//
//void World::drawWorld() {
//
//}

World::~World() { //REMEMBER TO FREE MEMORY
    cout << "World destruction" << endl;
}