#ifndef CODE_WORLD_H
#define CODE_WORLD_H

#include "Organism.h"
#include "Define.cpp"
#include "GeneralFunctions.h"
#include "vector"

using namespace std;

class World {
private:
    int rows;
    int cols;
    vector <Cell> cellList;
    vector <Organism *> organismList;
public:
    World(int numRows, int numCols);

    void addOnlyOrganism(Organism *organism);

    void addOrganism(Organism *organism, const Position &position);

    void removeOrganism(Organism *organism);

    void makeTurn();

    void drawWorld() const;

    const vector<Organism *> getOrganismList() const;

    void clearConsole();

    ~World();
};

#endif //CODE_WORLD_H