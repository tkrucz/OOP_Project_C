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
                clearScreen();
                break;
            default:
                cout << "Invalid input. Please try again." << endl;
        }
    }
}

void clearScreen() {
    system("cls");
}

void saveGame(World &world, int &rows, int &columns) {
    char filename[] = "Save.txt";
    FILE *file = fopen(filename, "w");
    if (file != nullptr) {
        fprintf(file, "World size: %d, %d\n", rows, columns);

        // Loop through each organism in the organismList
        for (const auto &organism: world.getOrganismList()) {
            if (auto *human = dynamic_cast<Human *>(organism)) {
                fprintf(file, "%s, position: %d, %d, strength: %d \n", human->nameToString().c_str(),
                        human->GetPosition().cord.x,
                        human->GetPosition().cord.y,
                        human->GetStrength());
                fprintf(file, "AbilityIsActive: %d\n", human->getAbilityIsActive());
                if (human->getAbilityIsActive()) {
                    fprintf(file, "AbilityDuration: %d\n", human->getAbilityDuration());
                    fprintf(file, "AbilityCooldown: %d\n", human->getAbilityCooldown());
                }
            } else if (auto *animal = dynamic_cast<Animal *>(organism)) {
                fprintf(file, "%s, position: %d, %d, strength: %d \n", animal->nameToString().c_str(),
                        animal->GetPosition().cord.x,
                        animal->GetPosition().cord.y,
                        animal->GetStrength());
            }
        }
        fclose(file);
    }
}

void loadGame() {
    char filename[] = "Save.txt";
    FILE *file = fopen(filename, "r");

    fclose(file);
}

bool operator==(const Position &lhs, const Position &rhs) {
    return lhs.cord.x == rhs.cord.x && lhs.cord.y == rhs.cord.y;
}