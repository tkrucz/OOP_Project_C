#ifndef CODE_FOX_H
#define CODE_FOX_H

#include "../Animal.h"

class Fox : public Animal {
public:
    Fox(const Position &position);

    ~Fox();
};

#endif //CODE_FOX_H
