#include "World.h"
#include "ctime"
#include "cstdlib"

int main() {
    //animalStatsInit(); Necessary ?
    //plantStatsInit(); Necessary ?
    char key;
    int rows, columns;

    srand(time(NULL));
    introduction(key, rows, columns);
    World world(rows, columns);

    Animal w(9, 5, 0, {0, 0}, AnimalSpecies::wolf);
//    Animal w1(9, 5, 0, {1, 1}, AnimalSpecies::wolf);
//    Animal s(4, 4, 0, {0, 1}, AnimalSpecies::sheep);
//    Animal s1(4, 4, 0, {1, 2}, AnimalSpecies::sheep);
//    Animal f(3, 7, 0, {2,2 }, AnimalSpecies::fox);
//    Animal f1(3, 7, 0, {2, 3}, AnimalSpecies::fox);

    Plant p(0, 0, {1, 0}, PlantSpecies::grass);

    world.addOrganism(&w, w.GetPosition());
    world.addOrganism(&p, p.GetPosition());
    world.drawWorld();

    world.removeOrganism(&p);
    world.drawWorld();

    world.makeTurn();
    world.drawWorld();

    return 0;
}
