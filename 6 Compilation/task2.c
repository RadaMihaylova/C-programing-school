/*Направете програма, която да намира най-малко общо кратно на две числа. 
Пример: a=12, б=18, най-малко общо кратно = 36. Изпълнете първите две стъпки от процеса на компилация на тази програма и качете асембли кода заедно със задачата към заданието.*/


#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int a = 12;
    int b = 18;

    int result = lcm(a, b);

    printf("The least common multiple of %d and %d is: %d\n", a, b, result);

    return 0;
}