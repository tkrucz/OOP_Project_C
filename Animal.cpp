#include "iostream"
#include "Animal.h"
#include "GeneralFunctions.h"
#include "World.h"

using namespace std;

Animal::Animal(int strength, int initiative, int age, const Position &_position, AnimalSpecies name)
        : Organism(strength, initiative, age, _position), name(name) {}

void Animal::Action(Vector<Cell> cellList, Vector<Organism *> organismList, World &world, int &rows, int &cols) {
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

    if (tmp > 0) {
        int index = rand() % tmp;
        switch (possibleMoves[index]) {
            case 1: // Right
                cellList.getElement((yCord * cols) + xCord).isEmpty = true;
                xCord++;
                break;
            case 2: // Left
                cellList.getElement((yCord * cols) + xCord).isEmpty = true;
                xCord--;
                break;
            case 3: // Down
                cellList.getElement((yCord * cols) + xCord).isEmpty = true;
                yCord++;
                break;
            case 4: // Up
                cellList.getElement((yCord * cols) + xCord).isEmpty = true;
                yCord--;
                break;
        }

        // Check for collision with another organism
        if (!cellList.getElement((yCord * cols) + xCord).isEmpty) {
            Position newPos = {xCord, yCord};
            Organism *otherOrganism = nullptr;
            for (int i = 0; i < organismList.Size(); ++i) {
                if (newPos == organismList.getElement(i)->GetPosition()) {
                    otherOrganism = organismList.getElement(i);
                    break;
                }
            }
            if (otherOrganism) {
                Collision(otherOrganism, world);
            }
        }

        // Update position and cell state
        cellList.getElement((yCord * cols) + xCord).isEmpty = false;
        position.cord.x = xCord;
        position.cord.y = yCord;
    }
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

