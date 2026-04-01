#include <stdio.h>
#include <stdlib.h>
#include <signal.h> // Required for signal handling

/**
 * EXERCISE 2: MEMORY MANAGEMENT (CRASH PROTECTION EDITION)
 * 
 * Objectives:
 * 1. Catch a "Segmentation Fault" using signals.
 * 2. Understand why stack memory "dies" and heap memory "lives".
 */

// This function runs when the CPU detects a memory error
void handle_crash(int sig) {
    printf("\n[!!!] CRASHED: Caught signal %d (Segmentation Fault)\n", sig);
    printf("The program attempted to access memory that is no longer valid!\n");
    
    // We wait for the user HERE so the window doesn't close on crash
    printf("\nPress Enter to exit (Crash Handler)... ");
    
    // Note: fflush(stdin) is undefined on some systems, 
    // but in Mingw on Windows it's often used to clear the buffer.
    // A more portable way is just calling getchar() twice:
    getchar(); 
    
    exit(sig); 
}

int* createOnStack() {
    int x = 100;
    return &x; // WARNING: Returning address of local variable
}

int* createOnHeap() {
    int* p = (int*)malloc(sizeof(int));
    if (p == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    *p = 200;
    return p;
}

int main() {
    // Register the crash handler
    signal(SIGSEGV, handle_crash);

    printf("--- Part 1: Stack vs Heap ---\n");

    int* heap_ptr = createOnHeap();
    printf("Value from Heap: %d (Safe!)\n", *heap_ptr);

    printf("\nAttempting to access stack-allocated memory...\n");
    int* stack_ptr = createOnStack();
    
    // THIS LINE TRIGGERS THE CRASH HANDLER:
    printf("Value from Stack: %d\n", *stack_ptr);

    // This part will never be reached if Part 1 crashes
    free(heap_ptr);

    printf("\nPress Enter to exit (Normal End)... ");
    getchar();

    return 0;
}
