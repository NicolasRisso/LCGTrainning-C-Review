#include <stdio.h>
#include <string.h>

/**
 * EXERCISE 3: STRUCTS & TYPEDEFS
 * 
 * Objectives:
 * 1. Define custom data types using struct and typedef.
 * 2. Use pointers to structs (the -> operator).
 * 3. Understand pass-by-value vs. pass-by-pointer.
 */

// 1. Basic struct definition
struct Vector2 {
    float x;
    float y;
};

// 2. Typedef struct definition (The "Cleaner" way)
typedef struct {
    char name[32];
    int health;
    struct Vector2 position;
} Player;

// Pass-by-value (Copies the entire struct)
void updateHealthValue(Player player) {
    player.health -= 10; // This only changes the COPY
}

// Pass-by-pointer (Modifies the original)
void updateHealthRef(Player* player) {
    player->health -= 10; 
}

int main() {
    // Initializing a struct
    Player hero = { "Argus", 100, { 0.0f, 0.0f } };

    printf("--- Part 1: Pass by Value ---\n");
    printf("Initial Health: %d\n", hero.health);
    
    updateHealthValue(hero);
    printf("Health after updateHealthValue (copy): %d\n", hero.health);

    printf("\n--- Part 2: Pass by Reference (Pointer) ---\n");
    updateHealthRef(&hero);
    printf("Health after updateHealthRef (pointer): %d\n", hero.health);

    printf("\n--- Part 3: Nested Structs and the '->' operator ---\n");
    Player* p_hero = &hero;
    
    // Accessing nested data via pointer
    p_hero->position.x = 15.5f;
    p_hero->position.y = -10.0f;

    printf("Player %s is at (%.2f, %.2f)\n", p_hero->name, p_hero->position.x, hero.position.y);

    printf("\nPress Enter to exit...");
    getchar();

    return 0;
}
