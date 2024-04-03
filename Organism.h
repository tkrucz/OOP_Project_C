#ifndef CODE_ORGANISM_H
#define CODE_ORGANISM_H

#include "Define.cpp"
#include "vector"

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

    void SetInitiative(int newInitiative);

    int GetAge() const ;

    void SetAge(int newAge);

    Position GetPosition() const;

    void SetPosition(const Position &newPosition);

    virtual void Action(vector<Cell> &cellList, vector<Organism*> &organismList, World &world, int &rows, int &columns) = 0;
    //previous     virtual void Action(Vector<Cell>cellList, int &rows, int &columns) = 0;

    virtual void Collision(Organism *otherOrganism, World &world) = 0;

    virtual char Draw()  = 0;

    ~Organism();
};

#endif //CODE_ORGANISM_H
