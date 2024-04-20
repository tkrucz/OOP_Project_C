#ifndef CODE_FOX_H
#define CODE_FOX_H

#include "../Animal.h"
#include "../World.h"

class Fox : public Animal {
public:
    Fox(const Position &position);

    void Action(vector<Cell> &cellList, vector<Organism *> &organismList, World &world, int &rows, int &columns) override;

    char Draw() override;

    string nameToString() override;

    int GetEnum() override;

    bool checkOpponent(vector<Cell> &cellList, vector<Organism *> &organismList, int newX, int newY, int columns);

    void breeding(vector<Cell> &cellList, World &world, int rows, int columns) override;

    ~Fox();
};

#endif //CODE_FOX_H
