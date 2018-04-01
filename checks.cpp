//
// Created by Edwin Herrera on 3/20/18.
//

#include "checks.h"
#include "errors.h"
#include <sstream>

bool typeIsSubSet(ReturnType type, ReturnType superSet) {
    if (type == superSet) {
        return true;
    }

    if (superSet == ReturnType::INTEGER) {
        if (type == ReturnType::BOOL) {
            return true;
        }
    }

    return false;
}

void checkType(ReturnType type, ReturnType expected) {
    if (!typeIsSubSet(type, expected)) {
        throw TypeError(to_string(expected), to_string(type));
    }
}

void checkType(ReturnType type, const vector<ReturnType> &expected) {
    for (const auto &t : expected) {
        if (typeIsSubSet(t, type)) {
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

bool isValidSubtype(ReturnType type, ReturnType expected) {
    
}