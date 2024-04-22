#include "Wolf.h"
#include "iostream"

using namespace std;

Wolf::Wolf(const Position &position) : Animal(9, 5, position, wolf, false) {}

char Wolf::Draw() {
    return 'W';
}

string Wolf::nameToString() {
    return "wolf";
}

int Wolf::GetEnum() {
    return 0;
}

void Wolf::breeding(vector<Cell> &cellList, World &world, int rows, int columns) {
    Wolf *newWolf;
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
            newWolf = new Wolf(newAnimalPosiiton);
            newWolf->SetIsBaby();
            world.addOrganism(newWolf,newAnimalPosiiton);
            break;
        }
        case 2: {
            Position newAnimalPosiiton = {xCord - 1, yCord};
            newWolf = new Wolf(newAnimalPosiiton);
            newWolf->SetIsBaby();
            world.addOrganism(newWolf,newAnimalPosiiton);
            break;
        }
        case 3: {
            Position newAnimalPosiiton = {xCord, yCord + 1};
            newWolf = new Wolf(newAnimalPosiiton);
            newWolf->SetIsBaby();
            world.addOrganism(newWolf,newAnimalPosiiton);
            break;
        }
        case 4: {
            Position newAnimalPosiiton = {xCord, yCord - 1};
            newWolf = new Wolf(newAnimalPosiiton);
            newWolf->SetIsBaby();
            world.addOrganism(newWolf,newAnimalPosiiton);
            break;
        }
    }
    cout << "New animal " << nameToString() << " was born" << endl;
}