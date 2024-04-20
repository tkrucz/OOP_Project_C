#ifndef CODE_ANTELOPE_H
#define CODE_ANTELOPE_H

#include "../Animal.h"
#include "../World.h"

class Antelope : public Animal {
public:
    Antelope(const Position &position);

    char Draw() override;

    void Action(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows, int &columns) override;

    void Collision(vector<Cell> &cellList, vector<Organism *> &organismList, Organism *otherOrganism, World &world, int &rows, int &columns) override;

    string nameToString() override;

    int GetEnum() override;

    void breeding(vector<Cell> &cellList, World &world, int rows, int columns) override;

    ~Antelope();
};

#endif //CODE_ANTELOPE_H
