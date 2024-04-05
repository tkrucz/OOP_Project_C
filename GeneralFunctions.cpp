#include "GeneralFunctions.h"
#include "World.h"
#include "iostream"

using namespace std;

void animalStatsInit() {
    Animal wolf1(9, 5, 0, {0, 0}, AnimalSpecies::wolf);
    Animal wolf2(9, 5, 0, {0, 0}, AnimalSpecies::wolf);
    Animal sheep1(4, 4, 0, {0, 0}, AnimalSpecies::sheep);
    Animal sheep2(4, 4, 0, {0, 0}, AnimalSpecies::sheep);
    Animal fox1(3, 7, 0, {0, 0}, AnimalSpecies::fox);
    Animal fox2(3, 7, 0, {0, 0}, AnimalSpecies::fox);
    Animal turtle1(2, 1, 0, {0, 0}, AnimalSpecies::turtle);
    Animal turtle2(2, 1, 0, {0, 0}, AnimalSpecies::turtle);
    Animal antelope1(4, 4, 0, {0, 0}, AnimalSpecies::antelope);
    Animal antelope2(4, 4, 0, {0, 0}, AnimalSpecies::antelope);

};

void plantStatsInit() {
    Plant grass(0, 0, {0, 0}, PlantSpecies::grass);
    Plant sow_thistle(0, 0, {0, 0}, PlantSpecies::sowThistle);
    Plant guarana(0, 0, {0, 0}, PlantSpecies::guarana);
    Plant belladonna(99, 0, {0, 0}, PlantSpecies::belladonna);
    Plant Sosnowskys_hogweed(10, 0, {0, 0}, PlantSpecies::sosnowskysHogweed);
}

void ageIncrease(Organism &organism) {
    int tmp = organism.GetAge();
    organism.SetAge(tmp + 1);
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

bool operator==(const Position &lhs, const Position &rhs) {
    return lhs.cord.x == rhs.cord.x && lhs.cord.y == rhs.cord.y;
}

void gameLoop(World &world) {
    char input;
    bool running = true;

    while (running) {
        nameDisplay(); // Display any necessary information to the player
        world.makeTurn(); // Execute a turn in the world
        world.drawWorld(); // Draw the updated state of the world

        cout << "Press 'q' to quit, 'k' to clear screen and proceed to next turn: ";
        cin >> input;

        switch (input) {
            case 'q':
                running = false;
                break;
            case 'k':
                clearScreen(); // Clear the console screen
                break;
            default:
                cout << "Invalid input. Please try again." << endl;
        }
    }
}

void clearScreen() {
    system("cls");
}