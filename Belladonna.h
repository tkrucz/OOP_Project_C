#ifndef CODE_BELLADONNA_H
#define CODE_BELLADONNA_H

#include "../Plant.h"
#include "../World.h"

class Belladonna : public Plant {
public:
    Belladonna(const Position &position);

    void Action(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows, int &columns) override;

    void Collision(vector<Cell> &cellList, vector<Organism *> &organismList, Organism *otherOrganism, World &world, int &rows, int &columns) override;

    char Draw() override;

    string nameToString() override;

    int GetEnum() override;
};

#endif //CODE_BELLADONNA_H