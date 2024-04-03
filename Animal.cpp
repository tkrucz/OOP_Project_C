#include "iostream"
#include "Animal.h"
#include "GeneralFunctions.h"
#include "World.h"

using namespace std;

Animal::Animal(int strength, int initiative, int age, const Position &_position, AnimalSpecies name)
        : Organism(strength, initiative, age, _position), name(name) {}

void Animal::Action(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows, int &columns) {
    int xCord = position.cord.x, yCord = position.cord.y;
    int possibleMoves[4] = {0, 0, 0, 0};
    int index = 0;
    if (xCord + 1 < columns)
        possibleMoves[index++] = 1;
    if (xCord - 1 >= 0)
        possibleMoves[index++] = 2;
    if (yCord + 1 < rows)
        possibleMoves[index++] = 3;
    if (yCord - 1 >= 0)
        possibleMoves[index++] = 4;
    index = rand() % index;
    switch (possibleMoves[index]) {
        case 1:
            if (cellList[(yCord * columns) + xCord + 1].isEmpty) {
                cellList[(yCord * columns) + xCord].isEmpty = true;
                xCord++;
                cellList[(yCord * columns) + xCord].isEmpty = false;
                position.cord.x = xCord;
            }
            break;
        case 2:
            if (cellList[(yCord * columns) + xCord - 1].isEmpty) {
                cellList[(yCord * columns) + xCord].isEmpty = true;
                xCord--;
                cellList[(yCord * columns) + xCord].isEmpty = false;
                position.cord.x = xCord;
            }
            break;
        case 3:
            if (cellList[((yCord + 1) * columns) + xCord].isEmpty) {
                cellList[(yCord * columns) + xCord].isEmpty = true;
                yCord++;
                cellList[(yCord * columns) + xCord].isEmpty = false;
                position.cord.y = yCord;
            }
            break;
        case 4:
            if (cellList[((yCord - 1) * columns) + xCord].isEmpty) {
                cellList[(yCord * columns) + xCord].isEmpty = true;
                yCord--;
                cellList[(yCord * columns) + xCord].isEmpty = false;
                position.cord.y = yCord;
            }
            break;
    }
//    // Check for collision with another organism
//    if (!cellList[(yCord * columns) + xCord].isEmpty) {
//        Position newPos = {xCord, yCord};
//        Organism *otherOrganism = nullptr;
//        for (auto other : organismList) {
//            if (newPos == other->GetPosition()) {
//                otherOrganism = other;
//                break;
//            }
//        }
//        if (otherOrganism) {
//            Collision(otherOrganism, world);
//        }
//    }
}

void Animal::Collision(Organism *other_organism, World &world) {
    int predatorStr = strength;
    int defenderStr = other_organism->GetStrength();
    if (predatorStr >= defenderStr) {
        cout << "Predator wins!" << endl;
        world.removeOrganism(other_organism);
    } else {
        cout << "Defender wins!" << endl;
        world.removeOrganism(this);
    }
}

char Animal::Draw() {
    if (name == wolf)
        return 'W';
    else if (name == sheep)
        return 'S';
    else if (name == fox)
        return 'F';
    else if (name == turtle)
        return 'T';
    else if (name == antelope)
        return 'A';
    else
        return 'H';
}

Animal::~Animal() {
    cout << "Animal was killed" << endl;
}