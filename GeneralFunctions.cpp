#include "GeneralFunctions.h"
#include "World.h"
#include "iostream"
#include "fstream"

using namespace std;

void ageIncrease(Organism &organism) {
    int tmp = organism.GetAge();
    organism.SetAge(tmp + 1);
}

void changeIsBaby(Organism &organism) {
    if (auto *animal = dynamic_cast<Animal *>(&organism)) {
        bool tmp = animal->GetIsBaby();
        if(tmp)
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
    system("cls"); //?
}

void saveGame(World & world, int &rows, int &columns, Organism *organism) {
    ofstream saveFile("save.txt", std::ios::out); //Open file or create it
    saveFile.close(); // Close the file
}

void loadGame(){

}
bool operator==(const Position &lhs, const Position &rhs) {
    return lhs.cord.x == rhs.cord.x && lhs.cord.y == rhs.cord.y;
}