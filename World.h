#ifndef CODE_WORLD_H
#define CODE_WORLD_H

#include "Organism.h"
#include "Define.cpp"
#include "Vector.h"
#include "GeneralFunctions.h"

class World {
private:
    int rows;
    int cols;
    Vector<Cell> cellList;
    Vector<Organism*> organismList;
public:
    World(int numRows, int numCols);

    void addOrganism(Organism *organism, const Position &position);

    void removeOrganism(Organism *organism);

    void makeTurn(); // Perform one turn in the world

   void drawWorld() const; // Draw the world (visualization)

    ~World();
};

#endif //CODE_WORLD_H
