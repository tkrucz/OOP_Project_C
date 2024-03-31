#ifndef CODE_PLANT_H
#define CODE_PLANT_H

#include "Organism.h"
#include "Define.cpp"

class Plant : public Organism {
private:
    PlantSpecies name;
public:
    Plant(int strength, int age, const Position &position, PlantSpecies name);

    void Action(Vector<Cell>cellList, int &rows, int &cols) override;

    void Collision(Organism *other_organism) override;

    char Draw() override;

    ~Plant() ;
};

#endif //CODE_PLANT_H
