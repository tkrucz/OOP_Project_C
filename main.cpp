#include "World.h"
#include "ctime"
#include "cstdlib"

int main(){
    srand(time(NULL));
    char key;
    int rows, columns;
//    World world = loadGame();
//    world.drawWorld();

    introduction(key, rows, columns);

    World world(rows, columns);

    Wolf w({1,0});
    Sheep s({0,0});
    Fox f({2, 2});
    Antelope a({0, 4});
    Turtle t({3, 0});

    Human h({3,3});

    Grass g({1,2});
    SowThistle sT({1, 5});
    Guarana gu({3, 2});
    Belladonna b({4, 0});
    SosnowskyHogweed sH({4, 4});

    world.addOrganism(&w, w.GetPosition());
    world.addOrganism(&s, s.GetPosition());
    world.addOrganism(&f, f.GetPosition());
    world.addOrganism(&a,a.GetPosition());
    world.addOrganism(&t,t.GetPosition());
    world.addOrganism(&h,h.GetPosition());

    world.addOrganism(&g, g.GetPosition());
    world.addOrganism(&sT, sT.GetPosition());
    world.addOrganism(&gu, gu.GetPosition());
    world.addOrganism(&b, b.GetPosition());
    world.addOrganism(&sH, sH.GetPosition());

    nameDisplay();
    world.drawWorld();

//  saveGame(world,rows,columns);
    gameLoop(world,rows,columns);

    return 0;
}
