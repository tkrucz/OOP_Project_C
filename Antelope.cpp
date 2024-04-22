#include "Antelope.h"
#include "iostream"

using namespace std;

Antelope::Antelope(const Position &position) : Animal(4, 4, position, antelope, false) {}

void Antelope::Action(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows, int &columns) {
    int moves = 2;
    for(int i=0; i < moves; i++)
        Animal::Action(cellList,organismList,world,rows,columns);
}

void Antelope::Collision(vector<Cell> &cellList, vector<Organism *> &organismList, Organism *otherOrganism, World &world,
                    int &rows, int &columns) {
    int probability = rand() % 100;
    if (probability < 50) {
        cout << "Antelope escape from fight" << endl;
        Animal::Action(cellList, organismList, world, rows, columns); //Antelope escape
    }
}
char Antelope::Draw() {
    return 'A';
}

string Antelope::nameToString() {
    return "antelope";
}

int Antelope::GetEnum() {
    return 4;
}

void Antelope::breeding(vector<Cell> &cellList, World &world, int rows, int columns) {
    Antelope *newAntelope;
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
            newAntelope = new Antelope(newAnimalPosiiton);
            newAntelope->SetIsBaby();
            world.addOrganism(newAntelope,newAnimalPosiiton);
            break;
        }
        case 2: {
            Position newAnimalPosiiton = {xCord - 1, yCord};
            newAntelope = new Antelope(newAnimalPosiiton);
            newAntelope->SetIsBaby();
            world.addOrganism(newAntelope,newAnimalPosiiton);
            break;
        }
        case 3: {
            Position newAnimalPosiiton = {xCord, yCord + 1};
            newAntelope = new Antelope(newAnimalPosiiton);
            newAntelope->SetIsBaby();
            world.addOrganism(newAntelope,newAnimalPosiiton);
            break;
        }
        case 4: {
            Position newAnimalPosiiton = {xCord, yCord - 1};
            newAntelope = new Antelope(newAnimalPosiiton);
            newAntelope->SetIsBaby();
            world.addOrganism(newAntelope,newAnimalPosiiton);
            break;
        }
    }
    cout << "New animal " << nameToString() << " was born" << endl;
}