#ifndef CODE_SOWTHISTLE_H
#define CODE_SOWTHISTLE_H

#include "../Plant.h"
#include "../World.h"
class SowThistle : public Plant {
public:
    SowThistle(const Position &position);

    void Action(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows, int &columns) override;

    char Draw() override;

    string nameToString() override;

    int GetEnum() override;

    ~SowThistle();
};

#endif //CODE_SOWTHISTLE_H
