#ifndef CODE_PLANT_H
#define CODE_PLANT_H
#include "Organism.h"
class Plant : public Organism{
private:
    char name;
public:
    ~Plant() override;
};
#endif //CODE_PLANT_H
