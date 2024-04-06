#include "iostream"
#include "Animal.h"
#include "World.h"

using namespace std;

Animal::Animal(int strength, int initiative, int age, const Position &position, AnimalSpecies name)
        : Organism(strength, initiative, age, position), name(name) {}

void Animal::Action(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows, int &columns) {
    int xCord = position.cord.x, yCord = position.cord.y;
    int possibleMoves[4] = {0, 0, 0, 0};
    int index = 0, numActions = 1;
    if (name == antelope)
        numActions = 2; // Antelope performs action
    if (name == turtle) {
        int probability = rand() % 100;
        if (probability < 75)
            return;
    }
    for (int i = 0; i < numActions; i++) {
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
                if (cellList[(yCord * columns) + xCord + 1].isEmpty ||
                    (name == fox && !isStronger(cellList, organismList, strength, columns))) {
                    moveAnimal(cellList, xCord, yCord, xCord + 1, yCord, columns);
                } else { //Checking the collision for this cell
                    Organism *otherOrganism = findOrganismAtPosition({xCord + 1, yCord}, organismList, cellList,
                                                                     columns);
                    if (otherOrganism)
                        Collision(cellList, otherOrganism, world, columns);
                }
                break;
            case 2:
                if (cellList[(yCord * columns) + xCord - 1].isEmpty ||
                    (name == fox && !isStronger(cellList, organismList, strength, columns))) {
                    moveAnimal(cellList, xCord, yCord, xCord - 1, yCord, columns);
                } else { //Checking the collision for this cell
                    Organism *otherOrganism = findOrganismAtPosition({xCord + -1, yCord}, organismList, cellList,
                                                                     columns);
                    if (otherOrganism)
                        Collision(cellList, otherOrganism, world, columns);
                }
                break;
            case 3:
                if (cellList[((yCord + 1) * columns) + xCord].isEmpty ||
                    (name == fox && !isStronger(cellList, organismList, strength, columns))) {
                    moveAnimal(cellList, xCord, yCord, xCord, yCord + 1, columns);
                } else { //Checking the collision for this cell
                    Organism *otherOrganism = findOrganismAtPosition({xCord, yCord + 1}, organismList, cellList,
                                                                     columns);
                    if (otherOrganism)
                        Collision(cellList, otherOrganism, world, columns);
                }
                break;
            case 4:
                if (cellList[((yCord - 1) * columns) + xCord].isEmpty ||
                    (name == fox && !isStronger(cellList, organismList, strength, columns))) {
                    moveAnimal(cellList, xCord, yCord, xCord, yCord - 1, columns);
                } else { //Checking the collision for this cell
                    Organism *otherOrganism = findOrganismAtPosition({xCord, yCord - 1}, organismList, cellList,
                                                                     columns);
                    if (otherOrganism)
                        Collision(cellList, otherOrganism, world, columns);
                }
                break;
        }
    }
}

void Animal::Collision(vector<Cell> &cellList, Organism *otherOrganism, World &world, int &columns) {
    int xCord = position.cord.x, yCord = position.cord.y;
    int predatorStr = strength, defenderStr = otherOrganism->GetStrength();
    Position occupiedCell = otherOrganism->GetPosition();
    if (predatorStr >= defenderStr) {
        cout << " Predator: " << nameToString() << " wins!" << endl;
        world.removeOrganism(otherOrganism);
        moveAnimal(cellList, xCord, yCord, occupiedCell.cord.x, occupiedCell.cord.y, columns);
    } else {
        cout << " Defender wins!" << endl;
        cellList[(yCord * columns) + xCord].isEmpty = true;
        //update that attacker dies so cell on which he stands is empty
    }
}

char Animal::Draw() {
    switch (name) {
        case wolf:
            return 'W';
        case sheep:
            return 'S';
        case fox:
            return 'F';
        case turtle:
            return 'T';
        case antelope:
            return 'A';
        default:
            return 'H';
    }
}

string Animal::nameToString() {
    switch (name) {
        case wolf:
            return "wolf";
        case sheep:
            return "sheep";
        case fox:
            return "fox";
        case turtle:
            return "turtle";
        case antelope:
            return "antelope";
        default:
            return "human";
    }
}

void Animal::moveAnimal(vector<Cell> &cellList, int &xCord, int &yCord, int newX, int newY, int columns) {
    cellList[(yCord * columns) + xCord].isEmpty = true;
    xCord = newX;
    yCord = newY;
    cellList[(yCord * columns) + xCord].isEmpty = false;
    position.cord.x = xCord;
    position.cord.y = yCord;
}

bool Animal::isStronger(vector<Cell> &cellList, vector<Organism *> &organismList, int strength, int columns) {
    int xCord = position.cord.x, yCord = position.cord.y;
    Organism *otherOrganism = findOrganismAtPosition({xCord, yCord}, organismList, cellList, columns);
    if (otherOrganism && otherOrganism->GetStrength() > strength) {
        return true;
    }
    return false;
}

AnimalSpecies Animal::GetAnimalName() const {
    return name;
}

Animal::~Animal() {
    cout << "Animal was killed" << endl;
}