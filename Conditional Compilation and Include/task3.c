/*
--
Направете функция, която използва различен алгоритъм за сортиране в зависимост от операционната система,
на която се намира. Ако операционната система е windows да се използва метод на мехурчето.
Ако системата е linux да използва метод на пряката селекция. Ако операционната система е MacOS
да се използва метода на прякото вмъкване. Ако операционната система не е нито една от трите,
функцията да обръща масива
(първият му елемент, да стане последен, втория предпоследен и т.н).
--
*/

#include <stdio.h>

void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void reverseArray(int arr[], int size);


void sortByOs(int arr[], int size) {

    #if defined(_WIN32)
        printf("Using Bubble Sort on Windows\n");
        bubbleSort(arr, size);
    #elif defined(__APPLE__)
        printf("Using Insertion Sort on MacOS\n");
        insertionSort(arr, size);
    #elif defined(__linux__)
        printf("Using Selection Sort on Linux\n");
        selectionSort(arr, size);
    #else 
        printf("Unknown OS, reversing array\n");
        reverseArray(arr, size);
    #endif
}

int main() {
    int arr[] = {1, 5, 2 , 4, 3};
    sortByOs(arr, 5);

    return 0;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}