#ifndef CODE_SHEEP_H
#define CODE_SHEEP_H

#include "../Animal.h"
#include "../World.h"

class Sheep : public Animal {
public:
    Sheep(const Position &position);

    char Draw() override;

    string nameToString() override;

    int GetEnum() override;

    void breeding(vector<Cell> &cellList, World &world, int rows, int columns) override;

    ~Sheep();
};

#endif //CODE_SHEEP_H