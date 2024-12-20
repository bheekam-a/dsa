#include <iostream>
#include <cstring>
using namespace std;

// Function to implement Linear Search for strings
int linearSearchStrings(const char* arr[], int n, const char* key) {
    for (int i = 0; i < n; i++) {
        // Compare the key with the current element in the array
        if (strcmp(arr[i], key) == 0) {
            return i;  // Return the index if found
        }
    }
    return -1;  // Return -1 if not found
}

// Main function
int main() {
    // Array of strings (const char* because string literals are immutable)
    const char* arr[] = {"apple", "banana", "cherry", "date", "fig", "grape"};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Predefined key to search
    const char* key = "apple";

    // Perform Linear Search
    int result = linearSearchStrings(arr, n, key);

    if (result != -1)
        cout << "String '" << key << "' found at index " << result << "." << endl;
    else
        cout << "String '" << key << "' not found in the array." << endl;

    return 0;

}  