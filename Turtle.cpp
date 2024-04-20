#include "Turtle.h"
#include "iostream"

using namespace std;

Turtle::Turtle(const Position &position) : Animal(2, 1, position, turtle, false) {}

void Turtle::Action(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows, int &columns) {
    int probability = rand() % 100;
    if (probability < 75)
        return; //Turtle doesn't move
    else
        Animal::Action(cellList, organismList, world, rows, columns);
}

char Turtle::Draw() {
    return 'T';
}

string Turtle::nameToString() {
    return "turtle";
}

int Turtle::GetEnum() {
    return 3;
}

void Turtle::breeding(vector<Cell> &cellList, World &world, int rows, int columns) {
    Turtle *newTurtle;
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
            newTurtle = new Turtle(newAnimalPosiiton);
            newTurtle->SetIsBaby();
            world.addOrganism(newTurtle,newAnimalPosiiton);
            break;
        }
        case 2: {
            Position newAnimalPosiiton = {xCord - 1, yCord};
            newTurtle = new Turtle(newAnimalPosiiton);
            newTurtle->SetIsBaby();
            world.addOrganism(newTurtle,newAnimalPosiiton);
            break;
        }
        case 3: {
            Position newAnimalPosiiton = {xCord, yCord + 1};
            newTurtle = new Turtle(newAnimalPosiiton);
            newTurtle->SetIsBaby();
            world.addOrganism(newTurtle,newAnimalPosiiton);
            break;
        }
        case 4: {
            Position newAnimalPosiiton = {xCord, yCord - 1};
            newTurtle = new Turtle(newAnimalPosiiton);
            newTurtle->SetIsBaby();
            world.addOrganism(newTurtle,newAnimalPosiiton);
            break;
        }
    }
    cout << "New animal " << nameToString() << " was born" << endl;
}

Turtle::~Turtle() {};