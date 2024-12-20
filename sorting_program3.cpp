#include <iostream>
#include <cstring>

using namespace std;

// Function to implement Binary Search for strings
int binarySearchStrings(const char* arr[], int n, const char* key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Compare the key with the middle element
        int result = strcmp(arr[mid], key);

        // If the key matches the middle element
        if (result == 0)
            return mid;

        // If the key is smaller, search in the left subarray
        if (result > 0)
            high = mid - 1;

        // If the key is larger, search in the right subarray
        else
            low = mid + 1;
    }

    // Key not found
    return -1;
}

// Main function
int main() {
    // Sorted array of strings (const char* because string literals are immutable)
    const char* arr[] = {"apple", "banana", "cherry", "date", "fig", "grape"};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Predefined key to search
    const char* key = "cherry";

    int result = binarySearchStrings(arr, n, key);

    if (result != -1)
        cout << "String '" << key << "' found at index " << result << "." << endl;
    else
        cout << "String '" << key << "' not found in the array." << endl;

    return 0;
}