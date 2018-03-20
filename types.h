//
// Created by Edwin Herrera on 3/20/18.
//

#ifndef TINYJULIAPP_TYPES_H
#define TINYJULIAPP_TYPES_H

#include <string>

using namespace std;

enum class ReturnType {
    UNIT,
    INTEGER,
    BOOL,
    STRING
};

inline string to_string(ReturnType type) {
    switch (type) {
        case ReturnType::UNIT:
            return "unit";
        case ReturnType::INTEGER:
            return "integer";
        case ReturnType::BOOL:
            return "bool";
        case ReturnType::STRING:
            return "string";
    }
}

#endif //TINYJULIAPP_TYPES_H
