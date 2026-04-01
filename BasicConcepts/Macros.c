#include <stdio.h>

#define SQUARE_BAD(x) x * x
#define SQUARE_GOOD(x) ((x) * (x))

int main() {
    int val = 5 + 5;

    printf("Using SQUARE_BAD(5 + 5) as a variable: %d\n", SQUARE_BAD(val)); 
    
    printf("Using SQUARE_BAD(5 + 5) directly: %d\n", SQUARE_BAD(5 + 5));
    printf("Using SQUARE_GOOD(5 + 5): %d\n", SQUARE_GOOD(5 + 5));

    printf("Press Enter to exit...");
    getchar(); // This waits for the user to hit the 'Enter' key

    return 0;
}