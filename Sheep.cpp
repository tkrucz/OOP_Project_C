#include "Sheep.h"

using namespace std;

Sheep::Sheep(const Position &position) : Animal(4, 4, position, sheep, false) {}

Sheep::~Sheep() {};