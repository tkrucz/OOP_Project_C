#include "GeneralFunctions.h"
#include "iostream"

using namespace std;

void animalStatsInit() {
    Animal wolf(9, 5, 0, {0, 0}, AnimalSpecies::wolf);
    Animal sheep(4, 4, 0, {0, 0}, AnimalSpecies::sheep);
    Animal fox(3, 7, 0, {0, 0}, AnimalSpecies::fox);
    Animal turtle(2, 1, 0, {0, 0}, AnimalSpecies::turtle);
    Animal antelope(4, 4, 0, {0, 0}, AnimalSpecies::antelope);
};

void plantStatsInit() {
    Plant grass(0, 0, {0, 0}, PlantSpecies::grass);
    Plant sow_thistle(0, 0, {0, 0}, PlantSpecies::sowThistle);
    Plant guarana(0, 0, {0, 0}, PlantSpecies::guarana);
    Plant belladonna(99, 0, {0, 0}, PlantSpecies::belladonna);
    Plant Sosnowskys_hogweed(10, 0, {0, 0}, PlantSpecies::sosnowskysHogweed);
}

bool cellCheck(Cell &cell) {
    if (cell.isEmpty)
        return true;
    return false;
}

void cellChange(Cell &cell) {
    if (cell.isEmpty)
        cell.isEmpty = false;
    cell.isEmpty = true;
}

void ageIncrease(Organism &organism) {
    int tmp = organism.GetAge();
    organism.SetAge(tmp + 1);
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
        }
        else if( key != '\n')
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