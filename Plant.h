#ifndef CODE_PLANT_H
#define CODE_PLANT_H

#include "Organism.h"
#include "Define.cpp"

class Plant : public Organism {
private:
    PlantSpecies name;
public:
    Plant(int strength, const Position& position, PlantSpecies name);

    int GetStrength() const;

    void SetStrength(int new_strength);

    Position GetPosition() const;

    void SetPosition(const Position& new_position);

    PlantSpecies GetName() const;

    void SetName(PlantSpecies new_name);

    void Action() override;

    void Collision(Organism* other_organism) override;

    char Draw() override;

    ~Plant() override;
};

#endif //CODE_PLANT_H
