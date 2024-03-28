#ifndef CODE_ANIMAL_H
#define CODE_ANIMAL_H

#include "Organism.h"
#include "Define.cpp"

class Animal : public Organism {
private:
    AnimalSpecies name;
public:
    Animal(int strength, int initiative, const Position &position, AnimalSpecies name);

    int GetStrength() const;

    void SetStrength(int new_strength);

    int GetInitiative() const;

    void SetInitiative(int new_initiative);

    Position GetPosition() const;

    void SetPosition(const Position &new_position);

    AnimalSpecies GetName() const;

    void SetName(AnimalSpecies new_name);

    void Action() override;

    void Collision(Organism *other_organism) override;

    char Draw() override;

    ~Animal() override;
};

#endif //CODE_ANIMAL_H
