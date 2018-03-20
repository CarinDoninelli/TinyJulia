//
// Created by Edwin Herrera on 3/20/18.
//

#include "checks.h"
#include "errors.h"

void checkType(ReturnType type, ReturnType expected) {
    if (type != expected) {
        throw TypeError(to_string(expected), to_string(type));
    }
}
