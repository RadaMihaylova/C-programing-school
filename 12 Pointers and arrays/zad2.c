/*Направете функция, която да сортира масив, използвайки адресна аритметика. Създайте функция, която се казва swap, 
и която да разменя две променливи. Използвайте я в алгоритъма за сортиране.*/

#include <stdio.h>

// izwyrshwa razmqna na stojnostite na parametrite na funkciqta i poneje te sa podadeni kato ukazateli 
// se izwyrshwa razmqna i wyw funciqta bubble_sort
int swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int * arr, int size){
    for(int i = 0; i < size; i++){
        int swapped = 0;
        for(int j = 1; j < size - i; j++){
            // sumira j kym bazowiq adres na masiva arr i sys zwezdata se izwyrshwa izwlichane na stojnostta ot masiwa, 
            // koeto e ekwiwalentno na arr[j]
            if (*(arr + j) < *(arr + j - 1)) {
                // izwikwa se funkciqta swap s parametri s adres arr+j i arr+j-1
                swap(arr+j, arr+j-1);
                swapped = 1;
            }
        }
        if (!swapped) return;
    }
}

void print_arr(int * arr,int size){
    for(int i = 0;i < size;i++){
        printf("%d ", *(arr + i));
    }
}

int main(){
    int arr[] = {1, 5, 6, 4, 3, 8, 9, 0, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, size);
    printf("Sorted: ");
    print_arr(arr, size);
}