#include <stdio.h>
#include "quadraticroots.h"

void printRoots(QuadraticRootsResult result) {
    if (result.norealroots) {
        printf("Няма реални корени.\n");
    } else {
        printf("Корен 1: %.2Lf\n", result.x1);
        printf("Корен 2: %.2Lf\n", result.x2);
    }
}

int main() {
    printf("Пример с int:\n");
    QuadraticRootsResult result1 = findroots(1, -3, 2);
    printRoots(result1);
    printf("\nПример с float:\n");
    QuadraticRootsResult result2 = findroots(1.0f, -3.0f, 2.0f);
    printRoots(result2);
    printf("\nПример с double:\n");
    QuadraticRootsResult result3 = findroots(1.0, -3.0, 2.0);
    printRoots(result3);

    return 0;
}
