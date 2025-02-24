
/*Направете макро функция (SWAP(А, B, TYPE)), което да разменя стойностите на две променливи от произволен тип.
Помощ: въведете типа като допълнителен аргумент на макро функцията. Демонстрирайте използването на подобно макро.
Когато дефинирате макрото за да се чете по лесно кодът, можете да слагата
“\” за да направите макрото на няколко реда.*/

#include <stdio.h>
#include <stdlib.h>

#define SWAP(A,B,TYPE) { \
    TYPE temp = A; \
    A = B; \
    B = temp; \
}

int main()
{
    {
        int x = 1, y = 2;
        printf("Before swap: x = %d, y = %d\n", x, y);
        SWAP(x, y, int)
        printf("After swap: x = %d, y = %d\n", x, y);
    }
    {
        double x = 1, y = 2;
        printf("Before swap: x = %lf, y = %lf\n", x, y);
        SWAP(x, y, double)
        printf("After swap: x = %lf, y = %lf\n", x, y);
    }
}
