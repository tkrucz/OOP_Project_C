#ifndef CODE_TURTLE_H
#define CODE_TURTLE_H

#include "../Animal.h"

class Turtle : public Animal {
public:
    Turtle(const Position &position);

    ~Turtle();
};

#endif //CODE_TURTLE_H
