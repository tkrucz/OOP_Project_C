#ifndef CODE_GRASS_H
#define CODE_GRASS_H

#include "../Plant.h"
#include "../World.h"

class Grass : public Plant {
public:
    Grass(const Position &position);

    void Action(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows, int &columns) override;

    char Draw() override;

    string nameToString() override;

    int GetEnum() override;

    ~Grass();
};

#endif //CODE_GRASS_H
