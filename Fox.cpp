#include "Fox.h"
#include "iostream"

using namespace std;

Fox::Fox(const Position &position) : Animal(3, 7, position, fox, false) {}

char Fox::Draw() {
    return 'F';
}

void Fox::Action(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows, int &columns) {
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
            if (cellList[yCord * columns + xCord].isEmpty) {
                Animal::moveAnimal(cellList, xCord, yCord, xCord + 1, yCord, columns);
            } else if (checkOpponent(cellList, organismList, xCord + 1, yCord, columns)) {
                Action(cellList, organismList, world, rows, columns);
            } else {
                Organism *otherOrganism = findOrganismAtPosition({xCord + 1, yCord}, organismList, cellList,
                                                                 columns);
                if (otherOrganism)
                    Collision(cellList, organismList, otherOrganism, world, rows, columns);
            }
            break;
        case 2:
            if (cellList[yCord * columns + xCord].isEmpty) {
                Animal::moveAnimal(cellList, xCord, yCord, xCord - 1, yCord, columns);
            } else if (checkOpponent(cellList, organismList, xCord - 1, yCord, columns)) {
                Action(cellList, organismList, world, rows, columns);
            } else {
                Organism *otherOrganism = findOrganismAtPosition({xCord - 1, yCord}, organismList, cellList,
                                                                 columns);
                if (otherOrganism)
                    Collision(cellList, organismList, otherOrganism, world, rows, columns);            }
            break;
        case 3:
            if (cellList[yCord * columns + xCord].isEmpty) {
                Animal::moveAnimal(cellList, xCord, yCord, xCord, yCord + 1, columns);
            } else if (checkOpponent(cellList, organismList, xCord, yCord + 1, columns)) {
                Action(cellList, organismList, world, rows, columns);
            } else {
                Organism *otherOrganism = findOrganismAtPosition({xCord, yCord + 1}, organismList, cellList,
                                                                 columns);
                if (otherOrganism)
                    Collision(cellList, organismList, otherOrganism, world, rows, columns);
            }
            break;
        case 4:
            if (cellList[yCord * columns + xCord].isEmpty) {
                Animal::moveAnimal(cellList, xCord, yCord, xCord, yCord - 1, columns);
            } else if (checkOpponent(cellList, organismList, xCord, yCord - 1, columns)) {
                Action(cellList, organismList, world, rows, columns);
            } else {
                Organism *otherOrganism = findOrganismAtPosition({xCord, yCord - 1}, organismList, cellList,
                                                                 columns);
                if (otherOrganism)
                    Collision(cellList, organismList, otherOrganism, world, rows, columns);
            }
            break;
    }
}

string Fox::nameToString() {
    return "fox";
}

int Fox::GetEnum() {
    return 2;
}

bool Fox::checkOpponent(vector<Cell> &cellList, vector<Organism *> &organismList, int newX, int newY, int columns) {
    int xCord = newX, yCord = newY;
    Organism *otherOrganism = findOrganismAtPosition({xCord, yCord}, organismList, cellList, columns);
    if (otherOrganism && otherOrganism->GetStrength() > strength) {
        return true;
    }
    return false;
}

void Fox::breeding(vector<Cell> &cellList, World &world, int rows, int columns) {
    Fox *newFox;
    int xCord = position.cord.x, yCord = position.cord.y;
    int freeCells[4] = {0, 0, 0, 0};
    int index = 0;
    if (xCord + 1 < columns && cellList[((yCord) * columns) + xCord + 1].isEmpty)
        freeCells[index++] = 1;
    if (xCord - 1 >= 0 && cellList[((yCord) * columns) + xCord - 1].isEmpty)
        freeCells[index++] = 2;
    if (yCord + 1 < rows && cellList[((yCord + 1) * columns) + xCord].isEmpty)
        freeCells[index++] = 3;
    if (yCord - 1 >= 0 && cellList[((yCord - 1) * columns) + xCord].isEmpty)
        freeCells[index++] = 4;
    index = rand() % index;
    switch (freeCells[index]) {
        case 1: {
            Position newAnimalPosiiton = {xCord + 1, yCord};
            newFox = new Fox(newAnimalPosiiton);
            newFox->SetIsBaby();
            world.addOrganism(newFox,newAnimalPosiiton);
            break;
        }
        case 2: {
            Position newAnimalPosiiton = {xCord - 1, yCord};
            newFox = new Fox(newAnimalPosiiton);
            newFox->SetIsBaby();
            world.addOrganism(newFox,newAnimalPosiiton);
            break;
        }
        case 3: {
            Position newAnimalPosiiton = {xCord, yCord + 1};
            newFox = new Fox(newAnimalPosiiton);
            newFox->SetIsBaby();
            world.addOrganism(newFox,newAnimalPosiiton);
            break;
        }
        case 4: {
            Position newAnimalPosiiton = {xCord, yCord - 1};
            newFox = new Fox(newAnimalPosiiton);
            newFox->SetIsBaby();
            world.addOrganism(newFox,newAnimalPosiiton);
            break;
        }
    }
    cout << "New animal " << nameToString() << " was born" << endl;
}

Fox::~Fox() {};