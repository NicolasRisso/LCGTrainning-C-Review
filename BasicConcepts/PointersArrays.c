#include <stdio.h>

/**
 * EXERCISE 1: POINTERS & ARRAYS
 * 
 * Objectives:
 * 1. Understand pointer dereferencing and addresses.
 * 2. See how arrays "decay" into pointers.
 * 3. Explore pointer arithmetic.
 */

void modifyValue(int* p) {
    *p = 42; // Dereferencing to change the value at the address
}

int main() {
    int x = 10;
    int* ptr = &x;

    printf("--- Part 1: Basics ---\n");
    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", (void*)&x);
    printf("Value of ptr (address): %p\n", (void*)ptr);
    printf("Value pointed to by ptr: %d\n", *ptr);

    modifyValue(&x);
    printf("Value of x after modifyValue: %d\n\n", x);

    printf("--- Part 2: Arrays & Pointers ---\n");
    int arr[] = {10, 20, 30, 40, 50};
    int *p_arr = arr; // Array decays to pointer to the first element

    printf("arr[0]: %d, *p_arr: %d\n", arr[0], *p_arr);
    printf("arr[2]: %d, *(p_arr + 2): %d\n", arr[2], *(p_arr + 2)); // Pointer arithmetic
    
    // Sizeof pitfall
    printf("sizeof(arr): %zu bytes\n", sizeof(arr));      // Size of the whole array
    printf("sizeof(p_arr): %zu bytes\n", sizeof(p_arr));  // Size of the pointer only
    printf("\n");

    printf("--- Part 3: Pointer Arithmetic ---\n");
    p_arr++; // Move to the next int
    printf("After p_arr++, *p_arr is: %d\n", *p_arr);

    // Casting and byte-level access (ADVANCED)
    unsigned char *byte_ptr = (unsigned char*)&x;
    printf("First byte of x (as unsigned char): %02x\n", *byte_ptr);

    printf("\nPress Enter to exit...");
    getchar();

    return 0;
}
