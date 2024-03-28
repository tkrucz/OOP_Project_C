#ifndef CODE_ORGANISM_H
#define CODE_ORGANISM_H
#include "Define.cpp"
class Organism{
public:
    int strength;
    int initiative;
    Position position;

    virtual void Action();
    virtual void Collision();
    virtual void Draw();
    virtual ~Organism();
};
#endif //CODE_ORGANISM_H
