#include "iostream"
#include "Plant.h"

using namespace std;

Plant::~Plant() noexcept {
    cout << "Plant died" << endl;
}