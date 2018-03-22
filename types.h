#ifndef TINYJULIAPP_TYPES_H
#define TINYJULIAPP_TYPES_H

#include <string>

using namespace std;

enum class ReturnType {
    UNIT,
    INTEGER,
    BOOL,
    STRING,
    INT_ARRAY
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
        case ReturnType::INT_ARRAY:
            return "int array";
    }
}

inline string defaultValue(ReturnType type) {
    switch (type) {
        case ReturnType::UNIT:
            return "";
        case ReturnType::INTEGER:
            return "0";
        case ReturnType::BOOL:
            return "0";
        default:
            return "";
    }
}

inline int defaultSize(ReturnType type) {
    switch (type) {
        case ReturnType::UNIT:
            return 0;
        case ReturnType::INTEGER:
            return 4;
        case ReturnType::BOOL:
            return 4;
        case ReturnType::INT_ARRAY:
            return 400;
        default:
            throw std::invalid_argument(to_string(type));
    }
}

#endif //TINYJULIAPP_TYPES_H
