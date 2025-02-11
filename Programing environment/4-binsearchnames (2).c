#include <stdio.h>
#include <string.h>

// Function prototypes
void inssortdesc(char arr[7][10], int arrlen);
int binsearch(char arr[7][10], int arrlen, char search[]);

int main(void) {
    char arr[7][10] = {
        "Ivan",
        "Marin",
        "Marianna",
        "Daniel",
        "Nikolai",
        "Plamena",
        "Atanas",
    };

    // Sort the array in descending order
    inssortdesc(arr, 7);

    // Search for "Dragan" and "Marin"
    printf("%s in array? => %d\n", "Dragan", binsearch(arr, 7, "Dragan"));
    printf("%s in array? => %d\n", "Marin", binsearch(arr, 7, "Marin"));
    
    return 0;
}

// Function to sort the array in descending order
void inssortdesc(char arr[7][10], int arrlen) {
    for (int i = 1; i < arrlen; i++) {
        // Error: Original condition was for ascending order. Fixing to sort in descending order.
        for (int j = i; j > 0 && strcmp(arr[j], arr[j-1]) > 0; j--) { 
            char temp[10];
            // Copy current element to temp
            strcpy(temp, arr[j]); 
            strcpy(arr[j], arr[j-1]); // Move the smaller element up
            strcpy(arr[j-1], temp);   // Place the current element in the correct position
        }
    }
}

// Function for binary search
int binsearch(char arr[7][10], int arrlen, char search[]) {
    int left = 0;
    int right = arrlen - 1;
    
    // Error: The loop condition should be left <= right to include the last element.
    while (left <= right) { 
        int mid = (right + left) / 2;
        
        if (strcmp(arr[mid], search) == 0) {
            return mid; // Element found, return index
        }

        // Error: Comparison should reflect descending order logic
        if (strcmp(search, arr[mid]) > 0) {
            right = mid - 1; // Search in the left half
        } else {
            left = mid + 1; // Search in the right half
        }
    } 

    return -1; // Element not found
}
