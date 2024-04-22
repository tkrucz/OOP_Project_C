#include "Sheep.h"
#include "iostream"

using namespace std;

Sheep::Sheep(const Position &position) : Animal(4, 4, position, sheep, false) {}

char Sheep::Draw() {
    return 'S';
}

string Sheep::nameToString() {
    return "sheep";
}

int Sheep::GetEnum() {
    return 1;
}

void Sheep::breeding(vector<Cell> &cellList, World &world, int rows, int columns) {
    Sheep *newSheep;
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
            newSheep = new Sheep(newAnimalPosiiton);
            newSheep->SetIsBaby();
            world.addOrganism(newSheep,newAnimalPosiiton);
            break;
        }
        case 2: {
            Position newAnimalPosiiton = {xCord - 1, yCord};
            newSheep = new Sheep(newAnimalPosiiton);
            newSheep->SetIsBaby();
            world.addOrganism(newSheep,newAnimalPosiiton);
            break;
        }
        case 3: {
            Position newAnimalPosiiton = {xCord, yCord + 1};
            newSheep = new Sheep(newAnimalPosiiton);
            newSheep->SetIsBaby();
            world.addOrganism(newSheep,newAnimalPosiiton);
            break;
        }
        case 4: {
            Position newAnimalPosiiton = {xCord, yCord - 1};
            newSheep = new Sheep(newAnimalPosiiton);
            newSheep->SetIsBaby();
            world.addOrganism(newSheep,newAnimalPosiiton);
            break;
        }
    }
    cout << "New animal " << nameToString() << " was born" << endl;
}