/*
--
Дефинирайте макро, което се казва DEBUG. Направете, функция която да сортира масив възходящо
и да намира сумата на елементите, които се намират на индекси, които се делят с точност на 3
и да я принтира на екрана.

Направете функцията така, че ако DEBUG макрото е дефинирано, на екрана
да се принтира сортирания масив и елементите, които се намират на индекси, които се делят с точност на 3
(като допълнение на сумата) 
--
*/


#include <stdio.h>

#define DEBUG

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
}

void func(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    #ifdef DEBUG
        printArray(arr, size);
    #endif

    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (i % 3 == 0) {
            #ifdef DEBUG
                printf("%d\n", arr[i]);
            #endif
            sum += arr[i];
        }
    }
    
    printf("Sum: %d\n", sum);

}

int main() {
    int arr[] = {1, 4, 2, 5, 3};
    func(arr, 5);

    return 0;
}

