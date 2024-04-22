#ifndef CODE_PLANT_H
#define CODE_PLANT_H

#include "Organism.h"
#include "Define.cpp"

class Plant : public Organism {
private:
    PlantSpecies name;
public:
    Plant(int strength, const Position &position, PlantSpecies name);

    void Action(vector<Cell> &cellList, vector<Organism*> &organismList, World &world, int &rows, int &columns) override;

    void Collision(vector<Cell> &cellList, vector<Organism*> &organismList, Organism *otherOrganism, World &world, int &rows, int &columns) override;

    char Draw() override;

    string nameToString() override;

    AnimalSpecies GetName() override;

    int GetEnum() override;
};

#endif //CODE_PLANT_H