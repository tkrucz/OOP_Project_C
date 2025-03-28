#ifndef CODE_ORGANISM_H
#define CODE_ORGANISM_H

#include "Define.cpp"
#include "vector"
#include "string"
using namespace std;

class World;

class Organism {
protected:
    int strength;
    int initiative;
    int age; //start from 1, with every round age should be increased
    Position position;
public:
    Organism(int strength, int initiative, int age, const Position &position);

    int GetStrength() const;

    void SetStrength(int newStrength);

    int GetInitiative() const;

    int GetAge() const ;

    void SetAge(int newAge);

    Position GetPosition() const;

    void SetPosition(const Position &newPosition);

    static Organism* findOrganismAtPosition(const Position& position, const vector<Organism*> &organismList, const vector<Cell> &cellList, int columns);

    virtual void Action(vector<Cell> &cellList, vector<Organism*> &organismList, World &world, int &rows, int &columns) = 0;

    virtual void Collision(vector<Cell> &cellList, vector<Organism*> &organismList, Organism *otherOrganism, World &world, int &rows, int &columns) = 0;

    virtual char Draw()  = 0;

    virtual int GetEnum() = 0;

    virtual string nameToString() = 0;

    virtual AnimalSpecies GetName() = 0;

    virtual ~Organism() = default;
};

#endif //CODE_ORGANISM_H
