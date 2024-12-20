#include <stdio.h>

// Function to implement Binary Search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the key is at mid
        if (arr[mid] == key)
            return mid;

        // If the key is smaller than the mid, it must be in the left subarray
        if (arr[mid] > key)
            high = mid - 1;

        // If the key is larger than the mid, it must be in the right subarray
        else
            low = mid + 1;
    }

    // Key not found
    return -1;
}

// Function to print the result
void printResult(int result, int key) {
    if (result != -1)
        printf("Element %d found at index %d.\n", key, result);
    else
        printf("Element %d not found in the array.\n", key);
}

// Main function
int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);
    printResult(result, key);

    return 0;
}