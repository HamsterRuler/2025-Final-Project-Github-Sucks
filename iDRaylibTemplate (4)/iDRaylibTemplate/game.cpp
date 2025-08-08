

#include "raylib.h"

// ===================================================================================================================
int main()
{
    // Initialize Window
    int screenWidth = 800;
    int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Top-Down Game");

    

    // Initialize Player
    Texture2D playerImage = LoadTexture("images/png/front view 3x.png");
    float playerX = 500;
    float playerY = 100;
    Vector2 player = {playerX, playerY};

    SetTargetFPS(60);
    // ================================================================================================================
    // Game Loop
    while (!WindowShouldClose())
    {
        //-------------------------------------------------
        BeginDrawing();

        // Draw Background
        ClearBackground(DARKGREEN);
        // Draw the Player
        DrawTexture(playerImage, player.x, player.y, WHITE);

        EndDrawing();
        //-------------------------------------------------
    }
    CloseWindow();
}