#include "Guarana.h"
#include "iostream"
#include "../Animal.h"

Guarana::Guarana(const Position &position) : Plant(0, position, guarana) {}

void Guarana::Action(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows, int &columns) {
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
        if (index != 0)
            index = rand() % index;
        switch (freeCells[index]) {
            case 1:
                xCord++;
                newPlantPosition = {xCord, yCord};
                world.addOrganism(new Guarana(newPlantPosition), newPlantPosition);
                break;
            case 2:
                xCord--;
                newPlantPosition = {xCord, yCord};
                world.addOrganism(new Guarana(newPlantPosition), newPlantPosition);
                break;
            case 3:
                yCord++;
                newPlantPosition = {xCord, yCord};
                world.addOrganism(new Guarana(newPlantPosition), newPlantPosition);
                break;
            case 4:
                yCord--;
                newPlantPosition = {xCord, yCord};
                world.addOrganism(new Guarana(newPlantPosition), newPlantPosition);
                break;
        }
    }
}

void Guarana::Collision(vector<Cell> &cellList, vector<Organism *> &organismList, Organism *otherOrganism, World &world,
                        int &rows, int &columns) {
    if (auto *animal = dynamic_cast<Animal *>(otherOrganism)) {
        animal->SetStrength(animal->GetStrength() + 3);
        cout << "Predator " << animal->nameToString() << " ate guarana and gained 3 strength!" << endl;
    }
    Plant::Collision(cellList,organismList,otherOrganism,world,rows,columns);
}

char Guarana::Draw() {
    return '+';
}

string Guarana::nameToString() {
    return "guarana";
}

int Guarana::GetEnum() {
    return 2;
}