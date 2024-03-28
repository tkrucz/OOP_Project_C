#ifndef CODE_ORGANISM_H
#define CODE_ORGANISM_H

#include "Define.cpp"
#include "World.h"

class Organism {
protected:
    int strength;
    int initiative;
    Position position;
    World *world;

public:
    Organism(int strength, int initiative, const Position &position, World *world);

    virtual void Action() = 0;

    virtual void Collision(Organism *other_organism) = 0;

    virtual char Draw()  = 0;

    int GetStrength() const;

    void SetStrength(int new_strength);

    int GetInitiative() const;

    void SetInitiative(int new_initiative);

    Position GetPosition() const;

    void SetPosition(const Position &new_position);

    World *GetWorld() const;

    void SetWorld(World *new_world);

    virtual ~Organism();
};

#endif //CODE_ORGANISM_H
