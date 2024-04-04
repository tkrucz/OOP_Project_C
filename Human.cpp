#include "Human.h"
#include "GeneralFunctions.h"
#include "iostream"

using namespace std;

Human::Human(const Position &position)
        : Animal(5, 4, 0, position, human) {}

void Human::Action(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows, int &columns) {

    bool isHumanPresent = false;
    for (Organism *organism: organismList) {
        if (dynamic_cast<Human *>(organism)) {
            isHumanPresent = true;
            break;
        }
    }
    if (isHumanPresent) {
        int xCord = position.cord.x, yCord = position.cord.y;
        char key;
        cout << "Enter a key to move: W (up), A (left),S (down),D (right) : ";
        cin >> key;
        switch (key) {
            case 'w':
                if (yCord > 0 && cellList[(yCord - 1) * columns + xCord].isEmpty) {
                    cellList[yCord * columns + xCord].isEmpty = true;
                    yCord--;
                    cellList[yCord * columns + xCord].isEmpty = false;
                    position.cord.y = yCord;
                } else {
                    Position newPos = {xCord, yCord - 1};
                    for (Organism *otherOrganism: organismList) {
                        if (otherOrganism->GetPosition() == newPos) {
                            Collision(otherOrganism, world);
                            break;
                        }
                    }
                }
                break;
            case 'a':
                if (xCord > 0 && cellList[yCord * columns + (xCord - 1)].isEmpty) {
                    cellList[yCord * columns + xCord].isEmpty = true;
                    xCord--;
                    cellList[yCord * columns + xCord].isEmpty = false;
                    position.cord.x = xCord;
                } else {
                    Position newPos = {xCord - 1, yCord};
                    for (Organism *otherOrganism: organismList) {
                        if (otherOrganism->GetPosition() == newPos) {
                            Collision(otherOrganism, world);
                            break;
                        }
                    }
                }
                break;
            case 's': // Move down
                if (yCord < rows - 1 && cellList[(yCord + 1) * columns + xCord].isEmpty) {
                    cellList[yCord * columns + xCord].isEmpty = true;
                    yCord++;
                    cellList[yCord * columns + xCord].isEmpty = false;
                    position.cord.y = yCord;
                } else {
                    Position newPos = {xCord, yCord + 1};
                    for (Organism *otherOrganism: organismList) {
                        if (otherOrganism->GetPosition() == newPos) {
                            Collision(otherOrganism, world);
                            break;
                        }
                    }
                }
                break;
            case 'd': // Move right
                if (xCord < columns - 1 && cellList[yCord * columns + (xCord + 1)].isEmpty) {
                    cellList[yCord * columns + xCord].isEmpty = true;
                    xCord++;
                    cellList[yCord * columns + xCord].isEmpty = false;
                    position.cord.x = xCord;
                } else {
                    Position newPos = {xCord + 1, yCord};
                    for (Organism *otherOrganism: organismList) {
                        if (otherOrganism->GetPosition() == newPos) {
                            Collision(otherOrganism, world);
                            break;
                        }
                    }
                }
                break;
            default:
                cout << "Invalid move. Please use W, A, S, or D." << endl;
        }
    }
}

Human::~Human() {
    cout << "Human was killed" << endl;
}

