#include <stdio.h>

/**
 * EXERCISE 4: REFINED MACROS
 * 
 * Objectives:
 * 1. Understand multi-line macros and the do-while(0) pattern.
 * 2. Use useful built-in macros (__FILE__, __LINE__) for logging.
 * 3. Reinforce why parentheses are mandatory in macros.
 */

// A professional logger macro!
// This adds file name, line number, and function name automatically.
// The ##__VA_ARGS__ is a trick to handle cases where there are no extra arguments.
#define LOG_MSG(fmt, ...) \
    do { \
        printf("[%s:%d in %s] " fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__); \
    } while (0)

#define MULTIPLY_BAD(x, y) x * y
#define MULTIPLY_GOOD(x, y) ((x) * (y))

int main() {
    LOG_MSG("Starting macro exercise...");

    int val1 = 5 + 5;
    int val2 = 2;

    // Pitfall: MULTIPLY_BAD(5 + 5, 2) becomes 5 + 5 * 2 = 15.
    // But we expect 10 * 2 = 20!
    printf("Result using MULTIPLY_BAD: %d (Expected 20, got 15 due to operator precedence!)\n", MULTIPLY_BAD(5 + 5, 2));
    printf("Result using MULTIPLY_GOOD: %d (Correct!)\n", MULTIPLY_GOOD(5 + 5, 2));

    LOG_MSG("All tests passed! Value of val1 is %d", val1);

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
