
#include "raylib.h"
#include "classes.h"

// ===================================================================================================================
int main()
{
    // wall stuff---
    //Texture2D table = LoadTexture("images/png/workbenchSmall (2).png");
    bool wallCollision = false;
    // Create an array of walls
    wall walls[1] = {wall(100, 100)};


    // Initialize Window
    int screenWidth = 800;
    int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Top-Down Game");

    // Variables
    int score = 0;

    // Initialize Background
    Texture2D bgImage = LoadTexture("images/png/bkgrndnobenchwithnoblackbar (1).png");

    

    // Initialize Player
    //Texture2D playerImage = LoadTexture("images/player.png");
    float playerX = 500;
    float playerY = 100;
    Vector2 player = {playerX, playerY};
    float speed = 4.0f;
    Rectangle playerCollider = {player.x, player.y, 40, 40};

    // Player Direction
    Texture2D playerRight = LoadTexture("images/png/side view right 3X.png");
    Texture2D playerLeft = LoadTexture("images/png/side view left 3X.png");
    Texture2D playerUp = LoadTexture("images/png/side view back 3X.png");
    Texture2D playerDown = LoadTexture("images/png/front view 3x.png");
    typedef enum
    {
        up,
        down,
        left,
        right
    } Direction;
    Direction playerDir = down;

    // Item Initialization
    /*Texture2D coinImage = LoadTexture("images/coin.png");
    Vector2 coin = {100, 200};
    Rectangle coinCollider = {coin.x, coin.y, 50, 50};
    bool collect = false;*/
    bool coinCollision = false;
    Item items[2] = {Item(100, 200), Item(100, 300)};

    SetTargetFPS(60);
    // ================================================================================================================
    // Game Loop
    while (!WindowShouldClose())
    {
        //-------------------------------------------------
        // Player Controls
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
        {
            player.x += speed;
            playerDir = right;
        }
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
        {
            player.x -= speed;
            playerDir = left;
        }
        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
        {
            player.y -= speed;
            playerDir = up;
        }
        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
        {
            player.y += speed;
            playerDir = down;
        }
        // Set the Collider's Position
        playerCollider.x = player.x;
        playerCollider.y = player.y;

        //----------------------
        // Boundaries for the Player Movement
        if ((player.x + 64) >= screenWidth) // Right
        {
            player.x = (screenWidth - 64);
        }
        if (player.x <= -50) // Left
        {
            player.x = -50;
        }
        if (player.y <= 50) // Up
        {
            player.y = 50;
        }
        if ((player.y + 64) >= screenHeight) // Down
        {
            player.y = (screenHeight - 64);
        }

        //----------------------
        // Coin Collision (Old)
        /*if (collect == false)
        {
            coinCollision = CheckCollisionRecs(playerCollider, coinCollider);
            if (coinCollision == true)
            {
                collect = true;
            }
        }*/

        //-------------------------------------------------
        BeginDrawing();

        // Draw Background
        DrawTexture(bgImage, 0, 0, WHITE);

    

        //----------------------
         //Coin Collision
        for (int i = 0; i < 3; ++i)
        {
            if (items[i].collect == false)
            {
                coinCollision = CheckCollisionRecs(playerCollider, items[i].collider);
                if (coinCollision == true)
                {
                    score += 1;
                    items[i].collect = true;
                }
                else
                {
                    DrawTexture(items[i].image, items[i].position.x, items[i].position.y, WHITE);
                }
            }
        }
            

        // Draw the Coin (Old)
        /*if (collect == false)
        {
            DrawTexture(coinImage, coin.x, coin.y, WHITE);
        }*/

        //----------------------
        // Draw Score
        DrawRectangle(0, 0, screenWidth, 50, BLACK);
        DrawText(TextFormat("Ammo: %i", score), 10, 10, 30, WHITE);

        // Draw Walls
        for (int i = 0; i < 2; ++i)
        {
            DrawTexture(walls[i].image, walls[i].position.x, walls[i].position.y, WHITE);
            wallCollision = CheckCollisionRecs(playerCollider, walls[i].collider);
            if (wallCollision == true)
            {
                switch (playerDir)
                {
                    case up:
                        player.y = walls[i].position.y + 64;
                    break;
                        
                    case down:
                        player.y = walls[i].position.y - 64;
                    break;

                    case left:
                        player.x = walls[i].position.x + 64;
                    break;

                    case right:
                        player.x = walls[i].position.x - 64;
                    break;

                    default:
                    break;
                }
            }
        }

        // Draw the Player
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
        
    }
    CloseWindow();
}

