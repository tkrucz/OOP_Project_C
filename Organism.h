#ifndef CODE_ORGANISM_H
#define CODE_ORGANISM_H

#include "Define.cpp"
#include "Vector.h"
class World;

class Organism {
protected:
    int strength;
    int initiative;
    int age; //start from 1, with every round age should be increased
    Position position;
public:
    Organism(int strength, int initiative, int age, const Position &position, World* world);

    int GetStrength() const;

    void SetStrength(int new_strength);

    int GetInitiative() const;

    void SetInitiative(int new_initiative);

    int GetAge() const ;

    void SetAge(int new_age);

    Position GetPosition() const;

    void SetPosition(const Position &new_position);

    virtual void Action(Vector<Cell>cellList, int &rows, int &cols) = 0;

    virtual void Collision(Organism *other_organism) = 0;

    virtual char Draw()  = 0;

    ~Organism();
};

#endif //CODE_ORGANISM_H
