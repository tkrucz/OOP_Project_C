#include <cstring>
#include "GeneralFunctions.h"
#include "World.h"
#include "iostream"

using namespace std;

void ageIncrease(Organism &organism) {
    int tmp = organism.GetAge();
    organism.SetAge(tmp + 1);
}

void changeIsBaby(Organism &organism) {
    if (auto *animal = dynamic_cast<Animal *>(&organism)) {
        bool tmp = animal->GetIsBaby();
        if (tmp)
            animal->SetIsNoBaby();
    }
}

void nameDisplay() {
    cout << "World Simulator : Tomasz Kruczalak 198049" << endl;
}

void introduction(char &key, int &rows, int &columns) {
    cout << "Author: Tomasz Kruczalak 198049 \nWelcome to World Simulator ! " << endl;
    cout << "Keys binding : \nm - symbols meaning \ns - start game\nl - load game";
    cout << endl;
    key = char(getchar());
    while (key != 's') {
        if (key == 'm') {
            charDictionary();
            break;
        } else if (key == 'l') { //jakoś to trzbea rozegrać
            loadGame();
            break;
        } else if (key != '\n')
            cout << "Wrong key" << endl;
        key = char(getchar());
    }
    cout << endl;
    worldInit(rows, columns);
}

void charDictionary() {
    cout << "Characters for organisms :" << endl;
    cout << "Plants : \ngrass # \nguarana + \nsow_thistle * \nbelladonna ? \nSosnowskys hogweed ! " << endl;
    cout << "Animals : \nwolf W \nsheep S \nfox F \nturtle T \nantelope A \nHuman H " << endl;
    cout << "Empty cell _" << endl;
}

void worldInit(int &rows, int &columns) {
    cout << "Enter number of rows and columns for world initialization : " << endl;
    cout << "Rows : ";
    cin >> rows;
    cout << "Columns : ";
    cin >> columns;
    cout << endl;
}

void gameLoop(World &world, int &rows, int &columns) {
    char input;
    bool running = true;

    while (running) {
        nameDisplay(); // Display information about author
        world.makeTurn(); // Execute a turn in the world
        world.drawWorld(); // Draw the updated state of the world

        cout << "Press 'q' to quit, 's' to save game or 'k' to clear screen and proceed to next turn: ";
        cin >> input;

        switch (input) {
            case 'q':
                running = false;
                break;
            case 's':
                saveGame(world, rows, columns);
                running = false;
                break;
            case 'k':
                world.clearConsole();
                break;
            default:
                cout << "Invalid input. Please try again." << endl;
        }
    }
    world.clearConsole();
    cout << "Game finished." << endl;
}

void saveGame(World &world, int &rows, int &columns) {
    char filename[] = "Save.txt";
    FILE *file = fopen(filename, "w");
    if (file != nullptr) {
        fprintf(file, "World size: %d, %d\n", rows, columns);

        for (const auto &organism: world.getOrganismList()) {
            if (auto *human = dynamic_cast<Human *>(organism)) {
                fprintf(file, "H, position: %d, %d, strength: %d\n",
                        human->GetPosition().cord.x,
                        human->GetPosition().cord.y,
                        human->GetStrength());
                fprintf(file, "AbilityIsActive: %d\n", human->getAbilityIsActive());
                if (human->getAbilityIsActive()) {
                    fprintf(file, "AbilityDuration: %d\n", human->getAbilityDuration());
                    fprintf(file, "AbilityCooldown: %d\n", human->getAbilityCooldown());
                }
            } else if (auto *animal = dynamic_cast<Animal *>(organism)) {
                fprintf(file, "A%d, position: %d, %d, strength: %d\n", animal->GetEnum(),
                        animal->GetPosition().cord.x,
                        animal->GetPosition().cord.y,
                        animal->GetStrength());
            } else if (auto *plant = dynamic_cast<Plant *>(organism)) {
                fprintf(file, "P%d, position: %d, %d\n", plant->GetEnum(),
                        plant->GetPosition().cord.x,
                        plant->GetPosition().cord.y);
            }
        }
        fclose(file);
    }
}

World loadGame() {
    char filename[] = "Save.txt";
    FILE *file = fopen(filename, "r");

    int rows, columns;
    fscanf(file, "World size: %d, %d\n", &rows, &columns);
    World world(rows, columns);

    char organismName;
    int x, y, strength = 0;

    while (fscanf(file, "%c", &organismName) != EOF) {
        Position position;
        Organism *newOrganism = nullptr;

        switch (organismName) {
            case 'H': // Human
                bool bLAbilityIsActive;
                int abilityIsActive, abilityDuration, abilityCooldown;
                fscanf(file, ", position: %d, %d, strength: %d\n", &x, &y, &strength);
                position = {x, y};
                newOrganism = new Human(position);
                fscanf(file, "AbilityIsActive: %d\n", &abilityIsActive);
                bLAbilityIsActive = abilityIsActive;
                if (bLAbilityIsActive) {
                    fscanf(file, "AbilityDuration: %d\n", &abilityDuration);
                    fscanf(file, "AbilityCooldown: %d\n", &abilityCooldown);
                    Human *humanPtr = dynamic_cast<Human *>(newOrganism);
                    if (humanPtr) {
                        humanPtr->setAbilityIsActive(true);
                        humanPtr->setAbilityDuration(abilityDuration);
                        humanPtr->setAbilityCooldown(abilityCooldown);
                    }
                }
                break;
            case 'A': // Animal
                int animalType;
                fscanf(file, "%d, position: %d, %d, strength: %d\n", &animalType, &x, &y, &strength);
                position = {x, y};
                switch (animalType) {
                    case 0:
                        newOrganism = new Wolf(position);
                        break;
                    case 1:
                        newOrganism = new Sheep(position);
                        break;
                    case 2:
                        newOrganism = new Fox(position);
                        break;
                    case 3:
                        newOrganism = new Turtle(position);
                        break;
                    case 4:
                        newOrganism = new Antelope(position);
                        break;
                    default:
                        break;
                }
                break;
            case 'P': // Plant
                int plantType;
                fscanf(file, "%d, position: %d, %d\n", &plantType, &x, &y);
                position = {x, y};
                switch (plantType) {
                    case 0:
                        newOrganism = new Grass(position);
                        break;
                    case 1:
                        newOrganism = new SowThistle(position);
                        break;
                    case 2:
                        newOrganism = new Guarana(position);
                        break;
                    case 3:
                        newOrganism = new Belladonna(position);
                        break;
                    case 4:
                        newOrganism = new SosnowskyHogweed(position);
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }

        if (newOrganism != nullptr) {
            if (strength != 0)
                newOrganism->SetStrength(strength);
            world.addOrganism(newOrganism, position);
        }
        strength = 0;
    }

    fclose(file);
    return world;
}

bool operator==(const Position &lhs, const Position &rhs) {
    return lhs.cord.x == rhs.cord.x && lhs.cord.y == rhs.cord.y;
}