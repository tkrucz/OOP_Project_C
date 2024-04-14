#include "iostream"
#include "Animal.h"
#include "World.h"

using namespace std;

Animal::Animal(int strength, int initiative, const Position &position, AnimalSpecies name, bool isBaby)
        : Organism(strength, initiative, 0, position), name(name), isBaby(false) {}

void Animal::Action(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows, int &columns) {
    int numActions = 1;
    if (isBaby)
        return;
    if (name == antelope)
        numActions = 2; // Antelope move twice
    if (name == turtle) {
        int probability = rand() % 100;
        if (probability < 75)
            return; //Turtle doesn't move
    }
    for (int i = 0; i < numActions; i++) {
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
                if (cellList[(yCord * columns) + xCord + 1].isEmpty ||
                    (name == fox && !isStronger(cellList, organismList, xCord + 1, yCord, strength, columns))) {
                    if (name == fox) {
                        Organism *otherOrganism = findOrganismAtPosition({xCord + 1, yCord}, organismList, cellList,
                                                                         columns);
                        if (otherOrganism)
                            Collision(cellList, organismList, otherOrganism, world, rows, columns);
                        moveAnimal(cellList, xCord, yCord, xCord + 1, yCord, columns);
                        return;
                    }
                    moveAnimal(cellList, xCord, yCord, xCord + 1, yCord, columns);
                } else { //Checking the collision for this cell
                    Organism *otherOrganism = findOrganismAtPosition({xCord + 1, yCord}, organismList, cellList,
                                                                     columns);
                    if (otherOrganism)
                        Collision(cellList, organismList, otherOrganism, world, rows, columns);
                }
                break;
            case 2:
                if (cellList[(yCord * columns) + xCord - 1].isEmpty ||
                    (name == fox && !isStronger(cellList, organismList, xCord - 1, yCord, strength, columns))) {
                    if (name == fox) {
                        Organism *otherOrganism = findOrganismAtPosition({xCord - 1, yCord}, organismList, cellList,
                                                                         columns);
                        if (otherOrganism)
                            Collision(cellList, organismList, otherOrganism, world, rows, columns);
                        moveAnimal(cellList, xCord, yCord, xCord - 1, yCord, columns);
                        return;
                    }
                    moveAnimal(cellList, xCord, yCord, xCord - 1, yCord, columns);
                } else { //Checking the collision for this cell
                    Organism *otherOrganism = findOrganismAtPosition({xCord - 1, yCord}, organismList, cellList,
                                                                     columns);
                    if (otherOrganism)
                        Collision(cellList, organismList, otherOrganism, world, rows, columns);
                }
                break;
            case 3:
                if (cellList[((yCord + 1) * columns) + xCord].isEmpty ||
                    (name == fox && !isStronger(cellList, organismList, xCord, yCord + 1, strength, columns))) {
                    if (name == fox) {
                        Organism *otherOrganism = findOrganismAtPosition({xCord, yCord + 1}, organismList, cellList,
                                                                         columns);
                        if (otherOrganism)
                            Collision(cellList, organismList, otherOrganism, world, rows, columns);
                        moveAnimal(cellList, xCord, yCord, xCord, yCord + 1, columns);
                        return;
                    }
                    moveAnimal(cellList, xCord, yCord, xCord, yCord + 1, columns);
                } else { //Checking the collision for this cell
                    Organism *otherOrganism = findOrganismAtPosition({xCord, yCord + 1}, organismList, cellList,
                                                                     columns);
                    if (otherOrganism)
                        Collision(cellList, organismList, otherOrganism, world, rows, columns);
                }
                break;
            case 4:
                if (cellList[((yCord - 1) * columns) + xCord].isEmpty ||
                    (name == fox && !isStronger(cellList, organismList, xCord, yCord - 1, strength, columns))) {
                    if (name == fox) {
                        Organism *otherOrganism = findOrganismAtPosition({xCord, yCord - 1}, organismList, cellList,
                                                                         columns);
                        if (otherOrganism)
                            Collision(cellList, organismList, otherOrganism, world, rows, columns);
                        moveAnimal(cellList, xCord, yCord, xCord, yCord - 1, columns);
                        return;
                    }
                    moveAnimal(cellList, xCord, yCord, xCord, yCord - 1, columns);
                } else { //Checking the collision for this cell
                    Organism *otherOrganism = findOrganismAtPosition({xCord, yCord - 1}, organismList, cellList,
                                                                     columns);
                    if (otherOrganism)
                        Collision(cellList, organismList, otherOrganism, world, rows, columns);
                }
                break;
        }
    }
}

void Animal::Collision(vector<Cell> &cellList, vector<Organism *> &organismList, Organism *otherOrganism, World &world,
                       int &rows, int &columns) {
    int predatorStr = strength;
    int defenderStr = otherOrganism->GetStrength();
    int xCord = position.cord.x, yCord = position.cord.y;
    Position occupiedCell = otherOrganism->GetPosition();

    if (name == antelope) {
        int probability = rand() % 100;
        if (probability < 50) {
            cout << "Antelope escape from fight" << endl;
            Action(cellList, organismList, world, rows, columns); //Antelope escape
        }
        return;
    }
    // Check if the other organism is an animal
    if (auto *otherAnimal = dynamic_cast<Animal *>(otherOrganism)) {
        if (otherAnimal->GetName() == turtle) {
            // If the defender is a turtle, handle turtle's defense
            if (predatorStr < 5) {
                // Turtle successfully defends by reflecting the attack
                cout << "Turtle reflects the attack of " << nameToString() << endl;
            }
            return; // Predator stays on its previous cell
        }
        //Check if other animal is the same
        if (otherAnimal->GetName() == name) {
            breeding(cellList, otherAnimal, world, rows, columns);
            return;
        }

        if (predatorStr >= defenderStr) {
            // Predator wins the fight
            cout << "Predator " << nameToString() << " attacked and defeated " << otherAnimal->nameToString() << endl;
            world.removeOrganism(otherOrganism);
            // Move to the defender's position
            moveAnimal(cellList, xCord, yCord, occupiedCell.cord.x, occupiedCell.cord.y, columns);
        } else {
            // Defender wins the fight
            cout << "Defender " << otherAnimal->nameToString() << " defeated " << nameToString() << endl;
            world.removeOrganism(this);
            // Remove predator from the current position
            cellList[(yCord * columns) + xCord].isEmpty = true;
        }
    }
        // If the other organism is a plant, animal eats the plant
    else if (auto *otherPlant = dynamic_cast<Plant *>(otherOrganism)) {
        if (otherPlant->nameToString() == "guarana" || otherPlant->nameToString() == "belladonna"
            || otherPlant->nameToString() == "sosnowsky's hogweed")
            otherPlant->Collision(cellList, organismList, this, world, rows, columns);
        else {
            cout << "Predator " << nameToString() << " ate ";
            cout << otherPlant->nameToString() << endl;
            world.removeOrganism(otherOrganism);
        }
        if (!cellList[yCord * columns + xCord].isEmpty)
            // Move to the plant's position
            moveAnimal(cellList, xCord, yCord, occupiedCell.cord.x, occupiedCell.cord.y, columns);
        else
            return;
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

int Animal::GetEnum() {
    switch (name) {
        case wolf:
            return 0;
        case sheep:
            return 1;
        case fox:
            return 2;
        case turtle:
            return 3;
        case antelope:
            return 4;
        default:
            return 5;
    }
}

AnimalSpecies Animal::GetName() {
    return name;
}

bool Animal::GetIsBaby() {
    return isBaby;
}

void Animal::SetIsBaby() {
    isBaby=true;
}

void Animal::SetIsNoBaby() {
    isBaby = false;
}

void Animal::moveAnimal(vector<Cell> &cellList, int &xCord, int &yCord, int newX, int newY, int columns) {
    cellList[(yCord * columns) + xCord].isEmpty = true;
    xCord = newX;
    yCord = newY;
    cellList[(yCord * columns) + xCord].isEmpty = false;
    position.cord.x = xCord;
    position.cord.y = yCord;
}

bool Animal::isStronger(vector<Cell> &cellList, vector<Organism *> &organismList, int newX, int newY, int strength,
                        int columns) {
    int xCord = newX, yCord = newY;
    Organism *otherOrganism = findOrganismAtPosition({xCord, yCord}, organismList, cellList, columns);
    if (otherOrganism && otherOrganism->GetStrength() > strength) {
        return true;
    }
    return false;
}

void Animal::breeding(vector<Cell> &cellList, Animal *otherAnimal, World &world, int rows, int columns) {
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
            world.addOrganism(new Animal(strength, initiative, newAnimalPosiiton, name, true), newAnimalPosiiton);
            break;
        }
        case 2: {
            Position newAnimalPosiiton = {xCord - 1, yCord};
            world.addOrganism(new Animal(strength, initiative, newAnimalPosiiton, name, true), newAnimalPosiiton);
            break;
        }
        case 3: {
            Position newAnimalPosiiton = {xCord, yCord + 1};
            world.addOrganism(new Animal(strength, initiative, newAnimalPosiiton, name, true), newAnimalPosiiton);
            break;
        }
        case 4: {
            Position newAnimalPosiiton = {xCord, yCord - 1};
            world.addOrganism(new Animal(strength, initiative, newAnimalPosiiton, name, true), newAnimalPosiiton);
            break;
        }
    }
    cout << "New animal " << nameToString() << " was born" << endl;
    otherAnimal->SetIsBaby();
}

Animal::~Animal() {}