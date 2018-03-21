//
// Created by Edwin Herrera on 3/20/18.
//

#include "checks.h"
#include "errors.h"
#include <sstream>

void checkType(ReturnType type, ReturnType expected) {
    if (type != expected) {
        throw TypeError(to_string(expected), to_string(type));
    }
}

void checkType(ReturnType type, const vector<ReturnType> &expected) {
    for (const auto &t : expected) {
        if (t == type) {
            return;
        }
    }

    stringstream expectedStr;
    for (const auto &t : expected) {
        expectedStr << to_string(t) << " ";
    }
    throw TypeError(expectedStr.str(), to_string(type));
}

void checkRange(int lower, int upper) {
    if (lower > upper) {
        throw InvalidRangeError();
    }
}