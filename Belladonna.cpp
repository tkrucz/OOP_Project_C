#include "Belladonna.h"
#include "iostream"

using namespace std;

Belladonna::Belladonna(const Position &position) : Plant(99, position, belladonna) {}

void Belladonna::Action(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows, int &columns) {
    int probability = rand() % 100;
    int xCord = position.cord.x, yCord = position.cord.y;
    int freeCells[4] = {0, 0, 0, 0};
    Position newPlantPosition;
    if (probability < 20) {
        int index = 0;
        if (xCord + 1 < columns && cellList[(yCord * columns) + xCord + 1].isEmpty)
            freeCells[index++] = 1;
        if (xCord - 1 >= 0 && cellList[(yCord * columns) + xCord - 1].isEmpty)
            freeCells[index++] = 2;
        if (yCord + 1 < rows && cellList[((yCord + 1) * columns) + xCord].isEmpty)
            freeCells[index++] = 3;
        if (yCord - 1 >= 0 && cellList[((yCord - 1) * columns) + xCord].isEmpty)
            freeCells[index++] = 4;
        if (index != 0)
            index = rand() % index;
        switch (freeCells[index]) {
            case 1:
                xCord++;
                newPlantPosition = {xCord, yCord};
                world.addOrganism(new Belladonna(newPlantPosition), newPlantPosition);
                break;
            case 2:
                xCord--;
                newPlantPosition = {xCord, yCord};
                world.addOrganism(new Belladonna(newPlantPosition), newPlantPosition);
                break;
            case 3:
                yCord++;
                newPlantPosition = {xCord, yCord};
                world.addOrganism(new Belladonna(newPlantPosition), newPlantPosition);
                break;
            case 4:
                yCord--;
                newPlantPosition = {xCord, yCord};
                world.addOrganism(new Belladonna(newPlantPosition), newPlantPosition);
                break;
        }
    }
}

void Belladonna::Collision(vector<Cell> &cellList, vector<Organism *> &organismList, Organism *otherOrganism, World &world,
                      int &rows, int &columns) {
    if (auto *animal = dynamic_cast<Animal *>(otherOrganism)) {
        cout << "Predator " << animal->nameToString() << " ate belladonna and died!" << endl;
        cellList[(animal->GetPosition().cord.y * columns) + animal->GetPosition().cord.x].isEmpty = true;
        // Remove animal from its current position
        world.removeOrganism(animal);
    }
    Plant::Collision(cellList,organismList,otherOrganism,world,rows,columns);
}

char Belladonna::Draw() {
    return '?';
};

string Belladonna::nameToString() {
    return "belladonna";
}

int Belladonna::GetEnum() {
    return 3;
}