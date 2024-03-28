#include "iostream"
#include "Animal.h"

using namespace std;

Animal::~Animal() noexcept {
    cout << "Animal was killed" << endl;
}