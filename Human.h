#ifndef CODE_HUMAN_H
#define CODE_HUMAN_H
#include "Animal.h"
class Human : public Animal{
private:
    bool abilityIsActive; //magical potion (strength +5)
    int abilityDuration;
    int abilityCooldown;
public:
    Human(const Position &position);

    void Action(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows, int &columns) override;

    void roundCounting();

    ~Human();
};
#endif //CODE_HUMAN_H
