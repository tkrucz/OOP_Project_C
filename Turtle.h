#ifndef CODE_TURTLE_H
#define CODE_TURTLE_H

#include "../Animal.h"
#include "../World.h"

class Turtle : public Animal {
public:
    Turtle(const Position &position);

    void Action(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows, int &columns) override;

    char Draw() override;

    string nameToString() override;

    int GetEnum() override;

    void breeding(vector<Cell> &cellList, World &world, int rows, int columns) override;
};

#endif //CODE_TURTLE_H