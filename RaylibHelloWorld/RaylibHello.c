#include "raylib/include/raylib.h"

/**
 * RAYLIB HELLO WORLD
 */
int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Raylib Hello World - C Review");

    SetTargetFPS(60); // Lock to 60 FPS

    Color textColor = DARKGRAY;

    // Main loop
    while (!WindowShouldClose()) // Returns true when ESC is pressed
    {    
        // 1. Input Update
        textColor = IsKeyDown(KEY_SPACE) ? RED : DARKGRAY;

        // 2. Draw
        BeginDrawing();

        // Screen Definitions
        {
            ClearBackground(RAYWHITE);

            DrawText("Hello World!", 190, 150, 40, BLACK);
            DrawText("This is the C basics review!", 190, 200, 20, textColor);
            DrawText("Hold SPACE to change color", 190, 240, 20, LIGHTGRAY);
        }
            
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
