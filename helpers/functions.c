#include "functions.h"
#include <stdio.h>

int pow_helper_function(int a, int b) {
    int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
//    printf("%d %d %d\n", result, a, b);
    return result;
}