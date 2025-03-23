/*Направете функция, която се казва compareasc и която да приема два void константни указателя към константи и да връща int стойност. 
Функцията трябва да преобразува указателите към указатели от тип int и да сравнява стойностите, към които сочат. 
Ако първата стойност е по-голяма от втората, функцията трябва да връща 1. 
Ако първата стойност е по-малка от втората функцията трябва да връща -1. 
Ако са равни функцията трябва да връща 0. Направете втора функция comparedesc, 
която да има същата структура като първата, само, че да връща 1 ако първата стойност е по-малка от втората 
и -1 ако първата стойност е по-голяма от втората (0 ако и двете стойности са равни).
Демонстрирайте използването на функциите.*/

#include <stdio.h>

int compareasc(const void * const p1, const void * const p2){
    const int x1 = *((const int * const)p1);
    const int x2 = *((const int * const)p2);
    if(x1 > x2) return 1;
    if(x2 > x1) return -1;
    return 0;
}

// int comparedesc(const void * const p1, const void * const p2){
//     const int x1 = *((const int * const)p1);
//     const int x2 = *((const int * const)p2);
//     if(x2 > x1) return 1;
//     if(x1 > x2) return -1;
//     return 0;
// }

int comparedesc(const void * const p1, const void * const p2){
    return -compareasc(p1, p2);
}

int main(){
    const int a = 10, b = 20;
    printf("Comparing %d and %d: %d\n", a, b, compareasc(&a, &b));
    printf("Comparing %d and %d: %d\n", a, b, comparedesc(&a, &b));
}