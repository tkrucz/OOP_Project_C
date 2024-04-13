#ifndef CODE_WOLF_H
#define CODE_WOLF_H

#include "../Animal.h"

class Wolf : public Animal {
public:
    Wolf(const Position &position);

    ~Wolf();
};

#endif //CODE_WOLF_H
