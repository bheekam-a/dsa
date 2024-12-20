//  Program to find out factorial of given number using recursion. Also show the various states of stack using in the program.

#include <stdio.h>

// Recursive function to calculate factorial
int factorial(int n, int depth) {
    // Display the stack state (depth indicates call level)
    printf("Entering function call: factorial(%d) | Stack depth: %d\n", n, depth);

    // Base case
    if (n == 0 || n == 1) {
        printf("Returning from function call: factorial(%d) = 1 | Stack depth: %d\n", n, depth);
        return 1;
    }

 
   // Recursive case
    int result = n * factorial(n - 1, depth + 1);

    // Display the state while returning
    printf("Returning from function call: factorial(%d) = %d | Stack depth: %d\n", n, result, depth);
    return result;
}

int main() {
    int num;

    // Input from user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check for invalid input
    if (num < 0) {
        printf("Factorial is not defined for negative numbers!\n");
        return 0;
    }

    // Calculate factorial
    int result = factorial(num, 1);

    // Display the result
    printf("Factorial of %d is: %d\n", num, result);

    return 0;
}

