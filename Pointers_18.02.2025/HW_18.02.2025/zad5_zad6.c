/*5.Направете функция която се нарича bubblesort. Функцията трябва да приема масив, който ще сортира, 
броят на елементите в масива, указател към функция (нека указателя се казва compare), 
която да указва в какъв ред да се сортира масив и указател към функция, 
която да указва как се разменят два елемента от масива (нека този указател се казва swapelements). 
Указателят compare трябва да сочи към функция, която приема два void указателя и връща int. 
Указателят swapelements, трябва да сочи, към функция, която приема два void указателя и ввръща void. 
Спомнете си, че алгоритъма ще сортира елементите в зависимост от сравнението което правите за да определите дали ще се разменят елементите.
Ако размяната става когато първия елемент е по-голям от втория, тогава имаме възходящо сортиране. 
Ако размяната става когато първия елемент е по-малък от втория, тогава имаме низходящо сортиране. 
Затова в тази част може да извикаме указателя към функция compare и зависимост от резултата да определим дали да разменим елементите с 
помощта на указателя към функции swapelements.

6.Извикайте функцията bubblesort, като подадете веднъж функцията compareasc като трети аргумент на bubblesort и като подадете веднъж
функцията comparedesc като трети аргумент на bubblesort. Масивът, който подавате за сортиране, може да е описан в програмата. 
Не забравяйте да принтирате сортираните масиви след извикването на bubblesort.
*/


#include <stdio.h>

typedef int (*Compare)(const void * const a, const void * const b);
typedef int (*Swapelements)(void * const c, void * const d); 

/*void bubblesort(int arr[], int count, 
    int (*compare)(const void *, const void *), 
    void (*swapelements)(void *, void *)) 
{

}*/

void bubblesort(int arr[], int count, Compare compare, Swapelements swapelements)
{
    for(int i = 0; i < count; i++){
        int swapped = 0;
        for(int j = 1; j < count - i; j++){
            if (compare(&arr[j - 1], &arr[j]) > 0) {
                swapelements(&arr[j-1], &arr[j]);
                swapped = 1;
            }
        }
        if (!swapped) return; 
    }
}

int compareAsc(const void * const p1, const void * const p2){
    return *((int*)p1) - *((int*)p2);
}

int compareDesc(const void * const p1, const void * const p2){
    return -compareAsc(p1, p2);
}

int swapInt(void * const p1, void * const p2){
    int *pi1 = (int*)p1;
    int *pi2 = (int*)p2;
    int temp = *pi1;
    *pi1 = *pi2;
    *pi2 = temp;
}

void printArray(int arr[], int count){
    for(int i = 0;i < count; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {5, 2, 9, 1, 5, 6};
    int count = sizeof(arr) / sizeof(arr[0]);
    bubblesort(arr, count, compareAsc, swapInt);
    printf("Sorted asc: ");
    printArray(arr, count);
    bubblesort(arr, count, compareDesc, swapInt);
    printf("Sorted desc: ");
    printArray(arr, count);
}