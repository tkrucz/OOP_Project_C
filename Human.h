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

    char Draw() override;

    string nameToString() override;

    int GetEnum() override;

    void abilityActivation();

    void roundCounting();

    bool getAbilityIsActive();

    void setAbilityIsActive(bool value);

    int getAbilityCooldown();

    void setAbilityCooldown(int value);

    int getAbilityDuration();

    void setAbilityDuration(int value);

    void breeding(vector<Cell> &cellList, World &world, int rows, int columns) override;

    ~Human();
};
#endif //CODE_HUMAN_H
