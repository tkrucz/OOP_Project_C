#include "iostream"
#include "Plant.h"
#include "World.h"

using namespace std;

Plant::Plant(int strength, int age, const Position &position, PlantSpecies name)
        : Organism(strength, 0, age, position), name(name) {}

void Plant::Action(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows, int &columns) {
    int numActions = 1;
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
                    world.addOrganism(new Plant(strength, 0, newPlantPosition, name), newPlantPosition);
                    break;
                case 2:
                    xCord--;
                    newPlantPosition = {xCord, yCord};
                    world.addOrganism(new Plant(strength, 0, newPlantPosition, name), newPlantPosition);
                    break;
                case 3:
                    yCord++;
                    newPlantPosition = {xCord, yCord};
                    world.addOrganism(new Plant(strength, 0, newPlantPosition, name), newPlantPosition);
                    break;
                case 4:
                    yCord--;
                    newPlantPosition = {xCord, yCord};
                    world.addOrganism(new Plant(strength, 0, newPlantPosition, name), newPlantPosition);
                    break;
            }
        }
    }
}

void Plant::Collision(vector<Cell> &cellList, Organism *otherOrganism, World &world, int &columns) {
    // Implement collision behavior for plants
    // For example, interaction with other organisms
}

char Plant::Draw() {
    if (name == guarana)
        return '+';
    else if (name == sowThistle)
        return '*';
    else if (name == belladonna)
        return '?';
    else if (name == sosnowskysHogweed)
        return '!';
    else
        return '#';
}

Plant::~Plant() {
    cout << "Plant withered" << endl;
}
