#include "World.h"
#include "ctime"
#include "cstdlib"

int main(){
    srand(time(NULL));
    char key;
    int rows, columns;
//    World world = loadGame(rows,columns);

    introduction(key, rows, columns);

    World world(rows, columns);

    auto *w = new Wolf ({1,0});
    auto *s = new Sheep ({0,0});
    auto *f = new Fox ({2, 2});
    auto *a = new Antelope ({0, 4});
    auto *t = new Turtle ({3, 0});

    auto *h = new Human ({3,3});

    auto *g = new Grass ({1,2});
    auto * sT = new SowThistle ({1, 5});
    auto * gu = new Guarana ({3, 2});
    auto *b = new Belladonna ({4, 0});
    auto *sH = new SosnowskyHogweed ({4, 4});

    world.addOnlyOrganism(w);
    world.addOnlyOrganism(s);
    world.addOnlyOrganism(f);
    world.addOnlyOrganism(a);
    world.addOnlyOrganism(t);
    world.addOnlyOrganism(h);

    world.addOnlyOrganism(g);
    world.addOnlyOrganism(sT);
    world.addOnlyOrganism(gu);
    world.addOnlyOrganism(b);
    world.addOnlyOrganism(sH);

    nameDisplay();
    world.drawWorld();

    gameLoop(world,rows,columns);

    return 0;
}