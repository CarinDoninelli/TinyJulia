//
// Created by Edwin Herrera on 3/20/18.
//

#ifndef TINYJULIAPP_CHECKS_H
#define TINYJULIAPP_CHECKS_H


#include <string>
#include <utility>
#include <vector>
#include "types.h"

using namespace std;

void checkType(ReturnType type, ReturnType expected);

void checkType(ReturnType type, const vector<ReturnType> &expected);

#endif //TINYJULIAPP_CHECKS_H
