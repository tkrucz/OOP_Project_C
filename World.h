#ifndef CODE_WORLD_H
#define CODE_WORLD_H

#include "Organism.h"
#include "Define.cpp"
class World {
private:
    int rows; // Number of rows in the grid
    int cols; // Number of columns in the grid

    //   std::vector<std::vector<Cell>> map; // 2D grid of cells
    //    std::vector<Organism*> organisms; // Vector to store pointers to organisms
    //    std::list<Cell> cellList; // List of cells in the world

public:
   World(int numRows, int numCols);
//
//    void addOrganism(Organism *organism, const Position &position);
//
//    void removeOrganism(Organism *organism);
//
//    void makeTurn(); // Perform one turn in the world
//
//    void drawWorld(); // Draw the world (visualization)
    ~World();
};

#endif //CODE_WORLD_H
