#ifndef CODE_SHEEP_H
#define CODE_SHEEP_H

#include "../Animal.h"

class Sheep : public Animal {
public:
    Sheep(const Position &position);

    ~Sheep();
};

#endif //CODE_SHEEP_H
