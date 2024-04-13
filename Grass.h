#ifndef CODE_GRASS_H
#define CODE_GRASS_H

#include "../Plant.h"

class Grass : public Plant {
public:
    Grass(const Position &position);

    ~Grass();
};

#endif //CODE_GRASS_H
