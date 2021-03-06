#ifndef TINYJULIAPP_CHECKS_H
#define TINYJULIAPP_CHECKS_H


#include <string>
#include <utility>
#include <vector>
#include "types.h"

using namespace std;

void checkType(ReturnType type, ReturnType expected);

void checkType(ReturnType type, const vector<ReturnType> &expected);

void checkRange(int lower, int upper);

#endif //TINYJULIAPP_CHECKS_H
