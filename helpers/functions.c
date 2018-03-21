#include "functions.h"

int pow_helper_function(int a, int b) {
    int result;
    for (int i = 0, result = 1; i < b; i++, result *= a);
    return result;
}