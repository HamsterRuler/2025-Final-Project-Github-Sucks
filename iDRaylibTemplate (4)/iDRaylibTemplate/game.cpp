

#include "raylib.h"
#include "classes.h"

// ===================================================================================================================
int main()
{
    // Initialize Window
    int screenWidth = 800;
    int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Top-Down Game");

    int ammoInventory = 0;

       Texture2D bgImage = LoadTexture("images/png/bkgrndnobenchwithnoblackbar (1).png");

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
       
=======
=======
>>>>>>> parent of e8ebd5d (Merge branch 'main' of https://github.com/HamsterRuler/2025-Final-Project-Github-Sucks)
=======
>>>>>>> parent of e8ebd5d (Merge branch 'main' of https://github.com/HamsterRuler/2025-Final-Project-Github-Sucks)
=======
>>>>>>> parent of e8ebd5d (Merge branch 'main' of https://github.com/HamsterRuler/2025-Final-Project-Github-Sucks)
       Texture2D workBenchImage = LoadTexture("images/png/workbench.png");
     
>>>>>>> parent of e8ebd5d (Merge branch 'main' of https://github.com/HamsterRuler/2025-Final-Project-Github-Sucks)

    // Initialize Player
    Texture2D playerImage = LoadTexture("images/png/front view 3x.png");
    float playerX = 500;
    float playerY = 100;
    Vector2 player = {playerX, playerY};
    float speed = 3.0f; // Speed in pixels per second
    Rectangle playerCollider = {player.x, player.y, 40, 40};
    // ================================================================================================================
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
   bool coinCollision = false;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    Item items[3] = {Item(300, 100), Item(300, 200), Item(300, 300)};
    // ================================================================================================================


    // Initialize Walls


    bool wallCollision = false;
    Wall walls[1] = {Wall(100, 100)};
    // ================================================================================================================
=======
    Item items[3] = {Item(100, 100), Item(100, 200), Item(100, 300)};
>>>>>>> parent of e8ebd5d (Merge branch 'main' of https://github.com/HamsterRuler/2025-Final-Project-Github-Sucks)
=======
    Item items[3] = {Item(100, 100), Item(100, 200), Item(100, 300)};
>>>>>>> parent of e8ebd5d (Merge branch 'main' of https://github.com/HamsterRuler/2025-Final-Project-Github-Sucks)
=======
    Item items[3] = {Item(100, 100), Item(100, 200), Item(100, 300)};
>>>>>>> parent of e8ebd5d (Merge branch 'main' of https://github.com/HamsterRuler/2025-Final-Project-Github-Sucks)
=======
    Item items[3] = {Item(100, 100), Item(100, 200), Item(100, 300)};
>>>>>>> parent of e8ebd5d (Merge branch 'main' of https://github.com/HamsterRuler/2025-Final-Project-Github-Sucks)

    // Set the target FPS
    SetTargetFPS(60);
    // ================================================================================================================



    // Game Loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        DrawRectangle(0, 0, screenWidth, 50, BLACK);
        DrawText("Ammo: ", 10, 10, 30, WHITE);

        DrawTexture(bgImage, 0, 0, WHITE);

       for (int i = 0; i < 2; ++i)
        {
            DrawTexture(walls[i].image, walls[i].position.x, walls[i].position.y, WHITE);
            wallCollision = CheckCollisionRecs(playerCollider, walls[i].collider);
            if (wallCollision == true)
            {
                switch (playerDir)
                {
                    case up:
                        player.y = walls[i].position.y + 0;
                    break;
                        
                    case down:
                        player.y = walls[i].position.y - 0;
                    break;

                    case left:
                        player.x = walls[i].position.x + 0;
                    break;

                    case right:
                        player.x = walls[i].position.x - 0;
                    break;

                    default:
                    break;
                }
            }
        }

        // Draw the Coin (Old)
        /*if (collect == false)
        {
            DrawTexture(coinImage, coin.x, coin.y, WHITE);
        }*/


        // Draw the Coin (Old)
        /*if (collect == false)
        {
            DrawTexture(coinImage, coin.x, coin.y, WHITE);
        }*/

       for (int i = 0; i < 2; ++i)
        {
            DrawTexture(walls[i].image, walls[i].position.x, walls[i].position.y, WHITE);
            wallCollision = CheckCollisionRecs(playerCollider, walls[i].collider);
            if (wallCollision == true)
            {
                switch (playerDir)
                {
                    case up:
                        player.y = walls[i].position.y + 32;
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
         playerCollider.x = player.x;
        playerCollider.y = player.y;
        if ((player.x + 64) >= screenWidth) // Right
        {
            player.x = (screenWidth - 64);
        }
        if (player.x <= -20) // Left
        {
            player.x = -20;
        }
        if (player.y <= 60) // Up
        {
            player.y = 60;
        }
        if ((player.y + 120) >= screenHeight) // Down
        {
            player.y = (screenHeight - 120);
        }

        //-------------------------------------------------
        
        // Draw Background
        ClearBackground(DARKBLUE);
        // Draw the Player
        DrawTexture(playerImage, player.x, player.y, WHITE);
        
<<<<<<< HEAD
       

        // Draw the Ammo Inventory
        // Draw the Ammo Label
        DrawRectangle(0, 0, screenWidth, 50, BLACK);
        DrawText("Ammo: ", 10, 10, 30, WHITE);
        // Display the Ammo Count
        DrawText(TextFormat("%d", ammoInventory), 100, 10, 30, WHITE);
=======
        // Draw the Workbench
        DrawTexture(workBenchImage, 20, 40, WHITE);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> parent of e8ebd5d (Merge branch 'main' of https://github.com/HamsterRuler/2025-Final-Project-Github-Sucks)
=======
>>>>>>> parent of e8ebd5d (Merge branch 'main' of https://github.com/HamsterRuler/2025-Final-Project-Github-Sucks)
=======
>>>>>>> parent of e8ebd5d (Merge branch 'main' of https://github.com/HamsterRuler/2025-Final-Project-Github-Sucks)
=======
>>>>>>> parent of e8ebd5d (Merge branch 'main' of https://github.com/HamsterRuler/2025-Final-Project-Github-Sucks)

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