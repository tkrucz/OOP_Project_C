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

    Animal w(9, 5, 0, {0, 0}, AnimalSpecies::wolf);
    Plant p(0, 0, {1, 0}, PlantSpecies::grass);
    World world(rows, columns);

    world.addOrganism(&w, w.GetPosition());
    world.addOrganism(&p, p.GetPosition());
    world.drawWorld();

    world.removeOrganism(&p);
    world.drawWorld();

    world.makeTurn();
    world.drawWorld();

    world.addOrganism(&p,{1,1});
    world.drawWorld();

    return 0;
}
