/*Направете функция, swap, която да разменя стойностите на две променли, чрез указатели. Аргументите на функцията трябва да 
са void указатели, които в тялото на функцията да се преобразуват до int указатели, 
преди да се извърши размяната.*/

#include <stdio.h>

void swap(void *a, void *b){ 
    // int * a1 = (int*)a;
    // int * b1 = (int*)b;
    // int temp = *a1;
    // *a1 = *b1;
    // *b1 = temp;
    int temp = *((int*)a);
    *((int*)a) = *((int*)b);
    *((int*)b) = temp;
}

int main(){
    int a = 1;
    int b = 2;
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);
}

