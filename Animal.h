#ifndef CODE_ANIMAL_H
#define CODE_ANIMAL_H

#include "Organism.h"
#include "Define.cpp"

class Animal : public Organism {
private:
    AnimalSpecies name;
public:
    Animal(int strength, int initiative, int age, const Position &position, AnimalSpecies name);

    void Action(Vector<Cell>cellList, int &rows, int &cols) override;

    void Collision(Organism *other_organism) override;

    char Draw() override;

    ~Animal() ;
};

#endif //CODE_ANIMAL_H
