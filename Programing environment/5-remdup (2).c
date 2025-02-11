#include <stdio.h>

int removeDuplicates(int* nums, int numsSize);

int main(void) {
    int nums[10] = {0, 0, 0, 1, 1, 2, 2, 5, 5, 7};
    int size = removeDuplicates(nums, 10);
  
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}

int removeDuplicates(int* nums, int numsSize) {
    // Changed curel to a more meaningful variable and initialized k to 1
    int k = 0; // Start counting unique elements, initialize k to 1 (first unique element)

    // Iterate through the array starting from the second element
    for (int i = 1; i < numsSize; i++) {
        // Error: Original logic incorrectly assigned curel to nums[k]
        // Instead, we need to compare with the last unique element: nums[k - 1]
        if (nums[i] != nums[k]) { // Compare current element with the last unique element
            nums[k] = nums[i]; // Assign the new unique element to the next position
            k++; // Increment k to indicate a new unique element has been found
        }
    }
    return k; // Return the count of unique elements
}
