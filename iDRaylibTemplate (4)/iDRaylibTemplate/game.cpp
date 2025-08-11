

#include "raylib.h"
#include "classes.h"

// ===================================================================================================================
int main()
{
    // Initialize Window
    int screenWidth = 800;
    int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Top-Down Game");

       Texture2D bgImage = LoadTexture("images/png/.png");
     

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
    // ================================================================================================================
    Texture2D playerRight = LoadTexture("images/png/side view right 3x.png");
    Texture2D playerLeft = LoadTexture("images/png/side view left 3x.png");
    Texture2D playerUp = LoadTexture("images/png/side view back 3x.png");
    Texture2D playerDown = LoadTexture("images/png/front view 3x.png");
    // ================================================================================================================
    bool ammoCollection = false;
    Item items[3] = {Item(100, 100), Item(200, 200), Item(300, 300)};
    // Set the target FPS
    SetTargetFPS(60);
    // ================================================================================================================



    // Game Loop
    while (!WindowShouldClose())
    {
        BeginDrawing();

        DrawTexture(bgImage, 0, 0, WHITE);

        for (int i=0; i < 3; i++)
        {
            if (items[i].colect ==false)
            {
                
            }
        }


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
         // Boundaries for the Player Movement
        if ((player.x + 64) >= screenWidth) // Right
        {
            player.x = (screenWidth - 64);
        }
        if (player.x <= -20) // Left
        {
            player.x = -20;
        }
        if (player.y <= 0) // Up
        {
            player.y = 0;
        }
        if ((player.y + 64) >= screenHeight) // Down
        {
            player.y = (screenHeight - 64);
        }

        //-------------------------------------------------
        
        // Draw Background
        ClearBackground(DARKBLUE);
        // Draw the Player
        DrawTexture(playerImage, player.x, player.y, WHITE);

        switch (playerDir)
        {
            case right:
                DrawTexture(playerRight, player.x, player.y, WHITE);
            break;
            case left:
                DrawTexture(playerLeft, player.x, player.y, WHITE);
            break;
            case up:
                DrawTexture(playerUp, player.x, player.y, WHITE);
            break;
            case down:
                DrawTexture(playerDown, player.x, player.y, WHITE);
            break;
            default:
            break;
        }

        EndDrawing();
        //-------------------------------------------------
    }
    CloseWindow();
}