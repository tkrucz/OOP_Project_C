#include "Human.h"
#include "GeneralFunctions.h"
#include "iostream"

using namespace std;

Human::Human(const Position &position)
        : Animal(5, 4, position, human, false),
          abilityIsActive(false), abilityDuration(0), abilityCooldown(0) {}

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
        bool actionDone = false;
        if (abilityIsActive)
            cout << "Enter a key to move: W (up), A (left),S (down),D (right) : ";
        else {
            cout << "Enter a key to move or to activate a special ability : " << endl;
            cout << "W (up), A (left),S (down),D (right), H(special ability) : ";
        }
        cin >> key;
        switch (key) {
            case 'w':
                if (yCord > 0 && cellList[(yCord - 1) * columns + xCord].isEmpty) {
                    moveAnimal(cellList, xCord, yCord, xCord, yCord - 1, columns);
                } else {
                    Position newPos = {xCord, yCord - 1};
                    for (Organism *otherOrganism: organismList) {
                        if (otherOrganism->GetPosition() == newPos) {
                            Collision(cellList, organismList, otherOrganism, world, rows, columns);
                            break;
                        }
                    }
                }
                actionDone = true;
                break;
            case 'a':
                if (xCord > 0 && cellList[yCord * columns + (xCord - 1)].isEmpty) {
                    moveAnimal(cellList, xCord, yCord, xCord - 1, yCord, columns);
                } else {
                    Position newPos = {xCord - 1, yCord};
                    for (Organism *otherOrganism: organismList) {
                        if (otherOrganism->GetPosition() == newPos) {
                            Collision(cellList, organismList, otherOrganism, world, rows, columns);
                            break;
                        }
                    }
                }
                actionDone = true;
                break;
            case 's': // Move down
                if (yCord < rows - 1 && cellList[(yCord + 1) * columns + xCord].isEmpty) {
                    moveAnimal(cellList, xCord, yCord, xCord, yCord + 1, columns);
                } else {
                    Position newPos = {xCord, yCord + 1};
                    for (Organism *otherOrganism: organismList) {
                        if (otherOrganism->GetPosition() == newPos) {
                            Collision(cellList, organismList, otherOrganism, world, rows, columns);
                            break;
                        }
                    }
                }
                actionDone = true;
                break;
            case 'd': // Move right
                if (xCord < columns - 1 && cellList[yCord * columns + (xCord + 1)].isEmpty) {
                    moveAnimal(cellList, xCord, yCord, xCord + 1, yCord, columns);
                } else {
                    Position newPos = {xCord + 1, yCord};
                    for (Organism *otherOrganism: organismList) {
                        if (otherOrganism->GetPosition() == newPos) {
                            Collision(cellList, organismList, otherOrganism, world, rows, columns);
                            break;
                        }
                    }
                }
                actionDone = true;
                break;
            case 'h':
                if (!abilityIsActive) {
                    abilityActivation();
                    Action(cellList, organismList, world, rows, columns);
                } else
                    cout << "Ability is already active" << endl;
                actionDone = true;
                break;
        }
        if (actionDone)
            roundCounting();
        else {
            cout << "Invalid key. Please use W, A, S, D or H." << endl;
            Action(cellList, organismList, world, rows, columns);
        }
    }
}

void Human::abilityActivation() {
    cout << "Magical potion activated" << endl;
    abilityIsActive = true;
    abilityDuration = 1;
    this->SetStrength(strength + 5);
}

void Human::roundCounting() {
    if (abilityIsActive) {
        abilityDuration++;
        this->SetStrength(--strength);
        return;
    } else if (abilityIsActive && abilityDuration == 5) {
        abilityIsActive = false;
        abilityCooldown = 5;
        if (strength >= 8)
            this->SetStrength(8);
        else
            this->SetStrength(5);
    } else if (!abilityIsActive && abilityCooldown > 0)
        abilityCooldown--;
}

bool Human::getAbilityIsActive() {
    return abilityIsActive;
}

void Human::setAbilityIsActive(bool value) {
    abilityIsActive = value;
}

int Human::getAbilityCooldown() {
    return abilityCooldown;
}

void Human::setAbilityCooldown(int value) {
    abilityCooldown = value;
}

int Human::getAbilityDuration() {
    return abilityDuration;
}

void Human::setAbilityDuration(int value) {
    abilityDuration = value;
}

Human::~Human() {}