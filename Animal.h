#ifndef CODE_ANIMAL_H
#define CODE_ANIMAL_H

#include "Organism.h"
#include "Define.cpp"

class World;

class Animal : public Organism {
private:
    AnimalSpecies name;
public:
    Animal(int strength, int initiative, int age, const Position &position, AnimalSpecies name);

    void Action(vector<Cell> &cellList, vector<Organism*> &organismList, World &world, int &rows, int &columns) override;

    void Collision(Organism *otherOrganism, World &world) override;

    char Draw() override;

    ~Animal() ;
};

#endif //CODE_ANIMAL_H
