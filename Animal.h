#ifndef CODE_ANIMAL_H
#define CODE_ANIMAL_H

#include "Organism.h"
#include "Define.cpp"
#include "string"

class World;

class Animal : public Organism {
private:
    AnimalSpecies name;
public:
    Animal(int strength, int initiative, int age, const Position &position, AnimalSpecies name);

    void Action(vector<Cell> &cellList, vector<Organism*> &organismList, World &world, int &rows, int &columns) override;

    void Collision(vector<Cell> &cellList, Organism *otherOrganism, World &world, int &columns) override;

    char Draw() override;

    string nameToString();

    void moveAnimal(vector<Cell> &cellList, int &xCord, int &yCord, int newX, int newY, int columns);

    bool isStronger(vector<Cell> &cellList, vector<Organism*> &organismList, int strength, int columns);

    ~Animal() ;
};

#endif //CODE_ANIMAL_H
