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
    cout << "Keys binding : \nm - symbols meaning \ns - start game";
    cout << endl;
    key = char(getchar());
    while (key != 's') {
        if (key == 'm') {
            charDictionary();
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

void gameLoop(World &world) {
    char input;
    bool running = true;

    while (running) {
        nameDisplay(); // Display information about author
        world.makeTurn(); // Execute a turn in the world
        world.drawWorld(); // Draw the updated state of the world

        cout << "Press 'q' to quit, 'k' to clear screen and proceed to next turn: ";
        cin >> input;

        switch (input) {
            case 'q':
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

        // Loop through each organism in the organismList
        for (const auto &organism: world.getOrganismList()) {
            if (auto *human = dynamic_cast<Human *>(organism)) {
                fprintf(file, "%s, position: %d, %d, strength: %d\n", human->nameToString().c_str(),
                        human->GetPosition().cord.x,
                        human->GetPosition().cord.y,
                        human->GetStrength());
                fprintf(file, "AbilityIsActive: %d\n", human->getAbilityIsActive());
                if (human->getAbilityIsActive()) {
                    fprintf(file, "AbilityDuration: %d\n", human->getAbilityDuration());
                    fprintf(file, "AbilityCooldown: %d\n", human->getAbilityCooldown());
                }
            } else if (auto *animal = dynamic_cast<Animal *>(organism)) {
                fprintf(file, "%s, position: %d, %d, strength: %d\n", animal->nameToString().c_str(),
                        animal->GetPosition().cord.x,
                        animal->GetPosition().cord.y,
                        animal->GetStrength());
            } else if (auto *plant = dynamic_cast<Plant *>(organism)) {
                fprintf(file, "%s, position: %d, %d\n", plant->nameToString().c_str(),
                        plant->GetPosition().cord.x,
                        plant->GetPosition().cord.y);
            }
        }
        fclose(file);
    }
}

void loadGame(World &world) {
    char filename[] = "Save.txt";
    FILE *file = fopen(filename, "r");
    for (int i = 0; i < checkFileLength(); i++) {
        if (i == 0) {
            int rows, columns;
            fscanf(file, "World size: %d, %d\n", &rows, &columns);
            world = World(rows, columns);
        } else {
            string organismName;
            int x, y, strength;
            bool abilityIsActive;
            int abilityDuration, abilityCooldown;
            fscanf(file, "%s, position: %d, %d", &organismName, &x, &y);
            Position position = {x,y};
            if (organismName == "wolf" || organismName == "sheep" || organismName == "antelope" ||
                organismName == "fox" || organismName == "turtle" || organismName == "human") {
                Animal *newAnimal;
                newAnimal->SetPosition(position);
                newAnimal->SetName(organismName);
            }
            else if(organismName == "grass" || organismName == "guarana" || organismName == "sow thistle" ||
                    organismName == "belladonna" || organismName == "sosnowsky's hogweed"){
                Plant* newPlant;
                newPlant->SetPosition(position);
                newPlant->SetName(organismName);
            }
        }
    }
    fclose(file);
}

int checkFileLength() {
    int rowsNumber = 0;
    int character;
    char filename[] = "Save.txt";
    FILE *file = fopen(filename, "r");

    while ((character = fgetc(file)) != EOF) {
        if (character == '\n')
            rowsNumber++;
    }
    fclose(file);
    return rowsNumber;
}

bool operator==(const Position &lhs, const Position &rhs) {
    return lhs.cord.x == rhs.cord.x && lhs.cord.y == rhs.cord.y;
}