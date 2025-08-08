

#include "raylib.h"

// ===================================================================================================================
int main()
{
    // Initialize Window
    int screenWidth = 800;
    int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Top-Down Game");

     Texture2D bgImage = LoadTexture("Grey-Granada-Tile-Cement-8x8-large.png");

    // Initialize Player
    Texture2D playerImage = LoadTexture("images/png/front view 3x.png");
    float playerX = 500;
    float playerY = 100;
    Vector2 player = {playerX, playerY};
    float speed = 3.0f; // Speed in pixels per second
    // ================================================================================================================
    typedef enum {
        up,
        down,
        left,
        right
    }Direction;
    Direction playerDir = down;
    // Set the target FPS
    SetTargetFPS(60);
    // ================================================================================================================
    // Game Loop
    while (!WindowShouldClose())
    {
        BeginDrawing();


        if (IsKeyDown(KEY_D))
        {
            player.x += speed;
            playerDir = right;
        }

        if (IsKeyDown(KEY_A))
        {
            player.x -= speed;
            playerDir = left;
        }

        if (IsKeyDown(KEY_W))
        {
            player.y -= speed;
            playerDir = up;
        }

        if (IsKeyDown(KEY_S))
        {
            player.y += speed;
            playerDir = down;
        }

        //-------------------------------------------------
        
        // Draw Background
        ClearBackground(DARKBLUE);
        // Draw the Player
        DrawTexture(playerImage, player.x, player.y, WHITE);

        EndDrawing();
        //-------------------------------------------------
    }
    CloseWindow();
}