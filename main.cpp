#include "World.h"
#include "ctime"
#include "cstdlib"

int main() {
    //animalStatsInit(); Necessary ?
    //plantStatsInit(); Necessary ?

    srand(time(NULL));
    char key;
    int rows, columns;

    introduction(key, rows, columns);

    World world(rows, columns);

    Animal w(9, 5, 0, {1, 0}, AnimalSpecies::wolf);
    Animal s(4, 4, 0, {0, 0}, AnimalSpecies::sheep);
    Animal f(3, 7, 0, {2, 2}, AnimalSpecies::fox);
    Animal a(4, 4, 0, {3, 3}, AnimalSpecies::antelope);
    Animal t(2, 1, 0, {3, 0}, AnimalSpecies::turtle);
    Human h({1,1});

    Plant p(0, 0, {1, 2}, PlantSpecies::grass);
    Plant sH(10, 0, {4, 4}, PlantSpecies::sosnowskysHogweed);

    world.addOrganism(&w, w.GetPosition());
    world.addOrganism(&s, s.GetPosition());
    world.addOrganism(&f, f.GetPosition());
    world.addOrganism(&h,h.GetPosition());
    world.addOrganism(&a,a.GetPosition());
    world.addOrganism(&t,t.GetPosition());
    world.addOrganism(&p, p.GetPosition());
    world.addOrganism(&sH, sH.GetPosition());



    nameDisplay();
    world.drawWorld(); //First world visualization

    world.makeTurn();
    world.drawWorld();
    world.makeTurn();
    world.drawWorld();
    world.makeTurn();
    world.drawWorld();

    //gameLoop(world);

    return 0;
}
