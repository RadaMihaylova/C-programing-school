#include <stdio.h>
#include <stdlib.h>
#include "safeint.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Please enter two whole numbers.\n");
        return 1;
    }
    
    SafeResult result = safestrtoint(argv[1]);
    if (result.errorflag) {
        printf("The first number is invalid or out of limits.\n");
        return 1;
    }
    
    SafeResult result2 = safestrtoint(argv[2]);
    if (result2.errorflag) {
        printf("The second number is invalid or out of the allowed limits.\n");
        return 1;
    }
    
    SafeResult sum = safeadd(result.value, result2.value);
    if (sum.errorflag) {
        printf("Overflow or underflow on collection.\n");
        return 1;
    }

    printf("The sum is: %d\n", sum.value);
    return 0;
}
