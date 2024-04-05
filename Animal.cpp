#include "iostream"
#include "Animal.h"
#include "World.h"

using namespace std;

Animal::Animal(int strength, int initiative, int age, const Position &position, AnimalSpecies name)
        : Organism(strength, initiative, age, position), name(name) {}

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
    cellList[(yCord * columns) + xCord].isEmpty = true;
    index = rand() % index;
    switch (possibleMoves[index]) {
        case 1:
            if (cellList[(yCord * columns) + xCord + 1].isEmpty) {
                xCord++;
                cellList[(yCord * columns) + xCord].isEmpty = false;
                position.cord.x = xCord;
            } else { //Checking the collision for this cell
                Position newPos = {xCord + 1, yCord};
                Organism *otherOrganism = nullptr;
                for (int i = 0; i < organismList.size(); ++i) {
                    if (newPos == organismList[i]->GetPosition()) {
                        otherOrganism = organismList[i];
                        break;
                    }
                }
                if (otherOrganism) {
                    Collision(otherOrganism, world);
                    cellList[(yCord * columns) + xCord + 1].isEmpty = false;
                }
            }
            break;
        case 2:
            if (cellList[(yCord * columns) + xCord - 1].isEmpty) {
                xCord--;
                cellList[(yCord * columns) + xCord].isEmpty = false;
                position.cord.x = xCord;
            } else { //Checking the collision for this cell
                Position newPos = {xCord - 1, yCord};
                Organism *otherOrganism = nullptr;
                for (int i = 0; i < organismList.size(); ++i) {
                    if (newPos == organismList[i]->GetPosition()) {
                        otherOrganism = organismList[i];
                        break;
                    }
                }
                if (otherOrganism) {
                    Collision(otherOrganism, world);
                    cellList[(yCord * columns) + xCord - 1].isEmpty = false;
                }
            }
            break;
        case 3:
            if (cellList[((yCord + 1) * columns) + xCord].isEmpty) {
                yCord++;
                cellList[(yCord * columns) + xCord].isEmpty = false;
                position.cord.y = yCord;
            } else { //Checking the collision for this cell
                Position newPos = {xCord, yCord + 1};
                Organism *otherOrganism = nullptr;
                for (int i = 0; i < organismList.size(); ++i) {
                    if (newPos == organismList[i]->GetPosition()) {
                        otherOrganism = organismList[i];
                        break;
                    }
                }
                if (otherOrganism) {
                    Collision(otherOrganism, world);
                    cellList[((yCord + 1) * columns) + xCord].isEmpty = false;
                }
            }
            break;
        case 4:
            if (cellList[((yCord - 1) * columns) + xCord].isEmpty) {
                yCord--;
                cellList[(yCord * columns) + xCord].isEmpty = false;
                position.cord.y = yCord;
            } else { //Checking the collision for this cell
                Position newPos = {xCord, yCord - 1};
                Organism *otherOrganism = nullptr;
                for (int i = 0; i < organismList.size(); ++i) {
                    if (newPos == organismList[i]->GetPosition()) {
                        otherOrganism = organismList[i];
                        break;
                    }
                }
                if (otherOrganism) {
                    Collision(otherOrganism, world);
                    cellList[((yCord - 1) * columns) + xCord].isEmpty = false;
                }
            }
            break;
    }
}

void Animal::Collision(Organism *other_organism, World &world) {
    int predatorStr = strength;
    int defenderStr = other_organism->GetStrength();
    Position occupiedCell = other_organism->GetPosition();
    if (predatorStr >= defenderStr) {
        cout << " Predator: " << nameToString() << " wins!" << endl;
        position.cord.x = occupiedCell.cord.x;
        position.cord.y = occupiedCell.cord.y;
        world.removeOrganism(other_organism);
    } else {
        cout << " Defender wins!" << endl;
        world.removeOrganism(this);
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
        case human:
            return "human";
        default:
            return "Unknown";
    }
}

Animal::~Animal() {
    cout << "Animal was killed" << endl;
}