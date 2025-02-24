#include <stdio.h>
#include "maths.h"

int main() {
    int number;
    printf("Add a number to calculate the factoriel: ");
    scanf("%d", &number);

    long result = factoriel(number);
    if (result == -1) {
        printf("Factorel cannot be calculated for negative numbers.\n");
    } else {
        printf("Factorel of  %d is %ld\n", number, result);
    }

    return 0;
}