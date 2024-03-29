#include <iostream>
#include "World.h"

using namespace std;

int main() {
    //animalStatsInit();
    //plantStatsInit();
    Animal w (9, 5, 0, {0, 0}, AnimalSpecies::wolf);
    Plant p(0,0,{1,0},PlantSpecies::grass);
    World wtf(2,2);
    wtf.addOrganism(&w,w.GetPosition());
    wtf.addOrganism(&p,p.GetPosition());
    wtf.drawWorld();
    cout << "Hello World" << endl;
    return 0;
}
