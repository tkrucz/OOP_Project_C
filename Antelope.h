#ifndef CODE_ANTELOPE_H
#define CODE_ANTELOPE_H

#include "../Animal.h"

class Antelope : public Animal {
public:
    Antelope(const Position &position);

    ~Antelope();
};

#endif //CODE_ANTELOPE_H
