#ifndef CODE_HUMAN_H
#define CODE_HUMAN_H
#include "Animal.h"
class Human : public Animal{
public:
    Human(const Position &position);

    void Action(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows, int &columns) override;

    ~Human();
};
#endif //CODE_HUMAN_H
