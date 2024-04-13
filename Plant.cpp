#include "iostream"
#include "Plant.h"
#include "World.h"

using namespace std;

Plant::Plant(int strength, const Position &position, PlantSpecies name)
        : Organism(strength, 0, 0, position), name(name) {}

void Plant::Action(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows, int &columns) {
    int numActions = 1;
    if (name == sosnowskysHogweed) {
        sosnowskysAction(cellList, organismList, world, rows, columns); //still something is wrong
        return; //This species of plant does only his special action
    }
    if (name == sowThistle)
        numActions = 3;
    for (int i = 0; i < numActions; i++) {
        int probability = rand() % 10;
        int xCord = position.cord.x, yCord = position.cord.y;
        int freeCells[4] = {0, 0, 0, 0};
        Position newPlantPosition;
        if (probability < 2) {
            int index = 0;
            if (xCord + 1 < columns && cellList[(yCord * columns) + xCord + 1].isEmpty)
                freeCells[index++] = 1;
            if (xCord - 1 >= 0 && cellList[(yCord * columns) + xCord - 1].isEmpty)
                freeCells[index++] = 2;
            if (yCord + 1 < rows && cellList[((yCord + 1) * columns) + xCord].isEmpty)
                freeCells[index++] = 3;
            if (yCord - 1 >= 0 && cellList[((yCord - 1) * columns) + xCord].isEmpty)
                freeCells[index++] = 4;
            index = rand() % index;
            switch (freeCells[index]) {
                case 1:
                    xCord++;
                    newPlantPosition = {xCord, yCord};
                    world.addOrganism(new Plant(strength, newPlantPosition, name), newPlantPosition);
                    break;
                case 2:
                    xCord--;
                    newPlantPosition = {xCord, yCord};
                    world.addOrganism(new Plant(strength, newPlantPosition, name), newPlantPosition);
                    break;
                case 3:
                    yCord++;
                    newPlantPosition = {xCord, yCord};
                    world.addOrganism(new Plant(strength, newPlantPosition, name), newPlantPosition);
                    break;
                case 4:
                    yCord--;
                    newPlantPosition = {xCord, yCord};
                    world.addOrganism(new Plant(strength, newPlantPosition, name), newPlantPosition);
                    break;
            }
        }
    }
}

void Plant::Collision(vector<Cell> &cellList, Organism *otherOrganism, World &world, int &rows, int &columns) {
    if (auto *animal = dynamic_cast<Animal *>(otherOrganism)) {
        // Handle collision based on the type of plant
        if (name == guarana) {
            // Guarana: Increase the strength of the animal by 3
            animal->SetStrength(animal->GetStrength() + 3);
            cout << "Predator " << animal->nameToString() << " ate guarana and gained 3 strength!" << endl;
        } else if (name == belladonna || name == sosnowskysHogweed) {
            // Belladonna or SosnowskyHogweed's hogweed: Kills the animal
            cout << "Predator " << animal->nameToString() << " ate " << nameToString() << " and died!" << endl;
            world.removeOrganism(animal);
            // Remove animal from its current position
            cellList[(animal->GetPosition().cord.y * columns) + animal->GetPosition().cord.x].isEmpty = true;
        }
        // Remove the plant from the world after being eaten
        world.removeOrganism(this);
        // Remove plant from its current position
        cellList[(position.cord.y * columns) + position.cord.x].isEmpty = true;
    }
}

char Plant::Draw() {
    switch (name) {
        case guarana:
            return '+';
        case sowThistle:
            return '*';
        case belladonna:
            return '?';
        case sosnowskysHogweed:
            return '!';
        default:
            return '#';
    }
}

string Plant::nameToString() {
    switch (name) {
        case guarana:
            return "guarana";
        case sowThistle:
            return "sow thistle";
        case belladonna:
            return "belladonna";
        case sosnowskysHogweed:
            return "sosnowsky's hogweed";
        default:
            return "grass";
    }
}

int Plant::GetEnum() {
    switch (name) {
        case grass:
            return 0;
        case sowThistle:
            return 1;
        case belladonna:
            return 3;
        case sosnowskysHogweed:
            return 4;
        default:
            return 2;
    }
}
//Kills every animal in its immediate neighborhood
void Plant::sosnowskysAction(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows,
                             int &columns) {
    int xCord = position.cord.x, yCord = position.cord.y;
    if (yCord - 1 >= 0 && !cellList[((yCord - 1) * columns) + xCord].isEmpty) {
        Organism *otherOrganism = findOrganismAtPosition({xCord, yCord - 1}, organismList, cellList, columns);
        if (otherOrganism) {
            world.removeOrganism(otherOrganism);
            cellList[((yCord - 1) * columns) + xCord].isEmpty = true;
        }
    }
    if (yCord + 1 < rows && !cellList[((yCord + 1) * columns) + xCord].isEmpty) {
        Organism *otherOrganism = findOrganismAtPosition({xCord, yCord + 1}, organismList, cellList, columns);
        if (otherOrganism) {
            world.removeOrganism(otherOrganism);
            cellList[((yCord + 1) * columns) + xCord].isEmpty = true;
        }
    }
    if (xCord - 1 >= 0 && !cellList[(yCord * columns) + (xCord - 1)].isEmpty) {
        Organism *otherOrganism = findOrganismAtPosition({xCord - 1, yCord}, organismList, cellList, columns);
        if (otherOrganism) {
            world.removeOrganism(otherOrganism);
            cellList[(yCord * columns) + (xCord - 1)].isEmpty = true;
        }
    }
    if (xCord + 1 < columns && !cellList[(yCord * columns) + (xCord + 1)].isEmpty) {
        Organism *otherOrganism = findOrganismAtPosition({xCord + 1, yCord}, organismList, cellList, columns);
        if (otherOrganism) {
            world.removeOrganism(otherOrganism);
            cellList[(yCord * columns) + (xCord + 1)].isEmpty = true;
        }
    }
}

AnimalSpecies Plant::GetName() {
    return notAnimal;
}

Plant::~Plant() {
    cout << "Plant withered" << endl;
}
