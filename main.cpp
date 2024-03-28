#include <iostream>
#include "World.h"

using namespace std;

int main() {
    animalStatsInit();
    plantStatsInit();

    Plant Rose{69, 1, {4, 20}, grass};
    Animal Wilk = {10, 10, 12, {10, 5}, wolf};
    Cell Origin = {{0, 0}, true};

    World world(2,2);
    world.drawWorld();
    cout << Rose.GetStrength() << endl;
    cout << Wilk.GetAge() << endl;
    cout << Origin.isEmpty << endl;

    cout << "Hello World" << endl;
    return 0;
}
