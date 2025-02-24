/*Направете програма, която да приема масив от тип long с числа и да заменя всеки елемент от него с стойността на елемента повдигнат на четвърта степен. 
За да реализирате програмата използвайте функцията pow, която приема два аргумента числото, което да се повдигне на степен и степента, на която да се повдигне числото. 
Така например 2 ^ 4 = pow(2, 4). Функцията е дефинирана в библиотеката libm.a със заглавен файл math.h, 
така, че за да я използвате трябва да свържете библиотеката по време на компилация. Тъй като библиотеката се намира в стандартните директории няма нужда да указвате пътя до нея, 
а само да я включите. Запишете командата, с която компилирате програмата в отделен текстови файл и го прикачете към задачата.*/ 


#include <stdio.h>
#include <math.h> 

void povdigane_na_chetvurta(long arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = (long)pow(arr[i], 4); 
    }
}

int main() {
    long numbers[] = {2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Array before conversion:\n");
    for (int i = 0; i < size; i++) {
        printf("%ld ", numbers[i]);
    }
    printf("\n");

    povdigane_na_chetvurta(numbers, size);

    printf("Array after conversion:\n");
    for (int i = 0; i < size; i++) {
        printf("%ld ", numbers[i]);
    }
    printf("\n");

    return 0;
}