#ifndef CODE_WOLF_H
#define CODE_WOLF_H

#include "../Animal.h"
#include "../World.h"

class Wolf : public Animal {
public:
    Wolf(const Position &position);

    char Draw() override;

    string nameToString() override;

    int GetEnum() override;

    void breeding(vector<Cell> &cellList, World &world, int rows, int columns) override;

    ~Wolf();
};

#endif //CODE_WOLF_H
