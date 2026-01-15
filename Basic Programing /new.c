#include <stdio.h>

// Function prototype for swapping by value
void swapByValue(int x, int y);

// Function prototype for swapping by reference
void swapByReference(int *x, int *y);

int main() {
    int a = 10;
    int b = 20;

    // --- 1. Demonstrate Pass by Value ---
    printf("--- Pass by Value ---\n");
    printf("Before swapping: a = %d, b = %d\n", a, b);

    // Call the function with copies of a and b
    swapByValue(a, b);

    printf("After swapping in main: a = %d, b = %d (Values did not change)\n\n", a, b);


    // --- 2. Demonstrate Pass by Reference ---
    printf("--- Pass by Reference ---\n");
    printf("Before swapping: a = %d, b = %d\n", a, b);

    // Call the function with memory addresses of a and b
    swapByReference(&a, &b);

    printf("After swapping in main: a = %d, b = %d (Values changed successfully)\n", a, b);

    return 0;
}

/**
 * @brief Swaps two numbers by value.
 * This function receives COPIES of the original values.
 * The swap only happens locally within this function's scope.
 * It has NO effect on the variables 'a' and 'b' in main().
 */
void swapByValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
    // The variables x and y are swapped here, but they are just copies.
}

/**
 * @brief Swaps two numbers by reference.
 * This function receives the MEMORY ADDRESSES of the original variables.
 * By using the dereference operator (*), we can access and modify
 * the original values of 'a' and 'b' from within this function.
 */
void swapByReference(int *x, int *y) {
    int temp = *x; // Get the value at the address 'x'
    *x = *y;       // Put the value from address 'y' into the address 'x'
    *y = temp;     // Put the temp value into the address 'y'
}

