#ifndef CODE_GUARANA_H
#define CODE_GUARANA_H

#include "../Plant.h"
#include "../World.h"

class Guarana : public Plant {
public:
    Guarana(const Position &position);

    char Draw() override;

    void Action(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows, int &columns) override;

    void Collision(vector<Cell> &cellList, vector<Organism *> &organismList, Organism *otherOrganism, World &world, int &rows, int &columns) override;

    string nameToString() override;

    int GetEnum() override;
};

#endif //CODE_GUARANA_H