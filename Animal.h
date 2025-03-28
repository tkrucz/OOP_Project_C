#ifndef CODE_ANIMAL_H
#define CODE_ANIMAL_H

#include "Organism.h"
#include "Define.cpp"

class Animal : public Organism {
private:
    AnimalSpecies name;
    bool isBaby;
public:
    Animal(int strength, int initiative, const Position &position, AnimalSpecies name, bool isBaby);

    void Action(vector<Cell> &cellList, vector<Organism*> &organismList, World &world, int &rows, int &columns) override;

    void Collision(vector<Cell> &cellList, vector<Organism*> &organismList, Organism *otherOrganism, World &world, int &rows, int &columns) override;

    char Draw() override;

    string nameToString() override;

    AnimalSpecies GetName() override;

    int GetEnum() override;

    bool GetIsBaby();

    void SetIsBaby();

    void SetIsNoBaby();

    void moveAnimal(vector<Cell> &cellList, int &xCord, int &yCord, int newX, int newY, int columns);

    virtual void breeding(vector<Cell> &cellList, World &world, int rows, int columns) = 0;

};

#endif //CODE_ANIMAL_H