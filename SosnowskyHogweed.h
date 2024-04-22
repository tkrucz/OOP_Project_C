#ifndef CODE_SOSNOWSKYHOGWEED_H
#define CODE_SOSNOWSKYHOGWEED_H

#include "../Plant.h"
#include "../World.h"

class SosnowskyHogweed : public Plant {
public:
    SosnowskyHogweed(const Position &position);

    void Action(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows, int &columns) override;

    void Collision(vector<Cell> &cellList, vector<Organism *> &organismList, Organism *otherOrganism, World &world, int &rows, int &columns) override;

    char Draw() override;

    string nameToString() override;

    int GetEnum() override;
};

#endif //CODE_SOSNOWSKYHOGWEED_H
