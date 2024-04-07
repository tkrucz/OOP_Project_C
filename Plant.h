#ifndef CODE_PLANT_H
#define CODE_PLANT_H

#include "Organism.h"
#include "Define.cpp"

class World;

class Plant : public Organism {
private:
    PlantSpecies name;
public:
    Plant(int strength, int age, const Position &position, PlantSpecies name);

    void Action(vector<Cell> &cellList, vector<Organism*> &organismList, World &world, int &rows, int &columns) override;

    void Collision(vector<Cell> &cellList, Organism *otherOrganism, World &world, int &columns) override;

    char Draw() override;

    string nameToString() override;

    void sosnowskysAction(vector<Cell> &cellList, vector<Organism*> &organismList, World &world, int &rows, int &columns);

    ~Plant() ;
};

#endif //CODE_PLANT_H
