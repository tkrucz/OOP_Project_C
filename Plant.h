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

    void Action(Vector<Cell> &cellList, Vector<Organism*> &organismList, World &world, int &rows, int &columns) override;

    void Collision(Organism *otherOrganism, World &world) override;

    char Draw() override;

    ~Plant() ;
};

#endif //CODE_PLANT_H
