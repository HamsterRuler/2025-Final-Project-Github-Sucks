#include "raylib.h"

int main ()
{
int screenWidth = 1600;
int screenHeight = 900;



//
InitWindow(screenWidth, screenHeight, "Raylib Project"  );
Texture2D playerImage = LoadTexture ("png/front view.png");
float playerX = 500;
float playerY = 100;
Vector2 player = {playerX, playerY};
SetTargetFPS(60);

while (!WindowShouldClose())
{
BeginDrawing();

ClearBackground(PURPLE);

DrawTexture(playerImage, player.x, player.y, WHITE);

EndDrawing();
}
CloseWindow();

}