#include "iostream"
#include "Animal.h"

using namespace std;

Animal::Animal(int _strength, int _initiative, int _age, const Position &_position, AnimalSpecies _name)
        : Organism(_strength, _initiative, _age, _position, nullptr), name(_name) {}

void Animal::Action(Vector<Cell> cellList, int &rows, int &cols) {
    int xCord = position.cord.x, yCord = position.cord.y;
    int possibleMoves[4] = {0, 0, 0, 0};
    int tmp = 0;
    if (xCord + 1 < cols)
        possibleMoves[tmp++] = 1;
    if (xCord - 1 >= 0)
        possibleMoves[tmp++] = 2;
    if (yCord + 1 < rows)
        possibleMoves[tmp++] = 3;
    if (yCord - 1 >= 0)
        possibleMoves[tmp++] = 4;
    int index = rand() % tmp;
    switch (possibleMoves[index]) {
        case 1:
            cellList.getElement((yCord * cols) + xCord).isEmpty = true;
            xCord++;
            cellList.getElement((yCord * cols) + xCord).isEmpty = false;
            position.cord.x = xCord;
            break;
        case 2:
            cellList.getElement((yCord * cols) + xCord).isEmpty = true;
            xCord--;
            cellList.getElement((yCord * cols) + xCord).isEmpty = false;
            position.cord.x = xCord;
            break;
        case 3:
            cellList.getElement((yCord * cols) + xCord).isEmpty = true;
            yCord++;
            cellList.getElement((yCord * cols) + xCord).isEmpty = false;
            position.cord.y = yCord;
            break;
        case 4:
            cellList.getElement((yCord * cols) + xCord).isEmpty = true;
            yCord--;
            cellList.getElement((yCord * cols) + xCord).isEmpty = false;
            position.cord.y = yCord;
            break;
    }
}


void Animal::Collision(Organism *other_organism) {
    // Implement collision behavior for animals
    // For example, interaction with other organisms
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

