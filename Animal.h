#ifndef CODE_ANIMAL_H
#define CODE_ANIMAL_H
#include "Organism.h"
class Animal : public Organism{
private:
    char name;
public:
    ~Animal() override;
};
#endif //CODE_ANIMAL_H
