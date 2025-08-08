#include "raylib.h"

int main ()
{
int screenWidth = 1600;
int screenHeight = 900;



//
InitWindow(screenWidth, screenHeight, "Raylib Project"  );
int action =  0;
const char* emotion = {"satisfied"};
const char* hunger = {"full"};
double startTime = GetTime ();
double currentTime = 0.0;
double midTime = 4;
double maxTime = 8;
double tooFar = 12;
double eatMaxTime = 9;
SetTargetFPS(60);

while (!WindowShouldClose())
{
    currentTime = GetTime() - startTime;    

    if (IsKeyPressed (KEY_S)) {action = 1; startTime = GetTime ();};
    if (IsKeyPressed (KEY_R)) {action = 2; startTime = GetTime ();};
    if (IsKeyPressed (KEY_C)) {action = 3; startTime = GetTime ();};
    if (IsKeyPressed (KEY_D)) {action = 4;};
    BeginDrawing();

    
    DrawRectangle (620, 425, 360, 150, WHITE);
    //This is to make the "Body"
    DrawRectangle (560, 405, 480, 20, BLACK);
    //This is to make the Base
    DrawRectangle (603, 380, 396, 25, GRAY);
    //This is for the Gray Ribbon
    DrawRectangle (605, 270, 390, 110, BLACK);
    //This is for the Melon
    DrawRectangle (610, 260, 380, 10, BLACK);
    //And this makes the Curve
   
    
    switch (action)
    {
        
     
    case 1:
    DrawText ("Sleeping.", 743, 110, 30, WHITE );
    emotion = { "satisfied"};
    if (currentTime >= midTime) {
        action = 0;
    }
    DrawText ("Z", 713, 97, 25, WHITE);
    DrawText ("Z", 693, 71, 22, WHITE);
    DrawText ("Z", 703, 47, 19, WHITE);
    DrawText ("Z", 690, 30, 16, WHITE);
    DrawRectangle (690, 466, 25, 7, BLACK);
    //This is to make the right eye
    DrawRectangle (870, 466, 25, 7, BLACK);
    //This is for the left eye
    ClearBackground(PURPLE);
    //This is to make a red background.
    
    break;
    
    case 2:

    if (currentTime >= midTime) {
        action = 0;
    }
    DrawText ("Reading.", 743, 110, 30, WHITE );
    emotion = { "satisfied"};
    DrawRectangle (663, 435, 80, 80, BLACK);
    //This is to make the right eye
    DrawRectangle (842.5, 435, 80, 80, BLACK);
    //This is for the left eye
    DrawRectangle (740, 455, 120, 20, BLACK);
    //This is to make the nose bridge
    DrawRectangle (852.5, 445, 60, 60, WHITE);
    //This is for the left eye
    DrawRectangle (673, 445, 60, 60, WHITE);
    //This is to make the right eye
    DrawRectangle (690, 460, 25, 25, BLACK);
    //This is to make the left eye
    DrawRectangle (870, 460, 25, 25, BLACK);
    //This is for the right eye
    ClearBackground(PURPLE);
    //This is to make a red background.
    break;

    case 3:
    if (currentTime >= eatMaxTime) {
        action = 0;
    }
    DrawText ("Consuming.", 730, 110, 30, WHITE );
    hunger = {"full"};
    DrawRectangle (690, 460, 25, 25, RED);
    //This is to make the left eye
    DrawRectangle (870, 460, 25, 25, RED);
    //This is for the right eye
    ClearBackground(RED);
    //This is to make a red background.
    
    break;

    case 4:
    DrawText ("Idling.", 755, 110, 30, WHITE );
    DrawRectangle (690, 460, 25, 25, BLACK);
    //This is to make the left eye
    DrawRectangle (870, 460, 25, 25, BLACK);
    //This is for the right eye
    ClearBackground(PURPLE);
    //This is to make a red background.

    break;

    default:
    DrawText ("Press R, S, D, or C for different interactions!", 473, 110, 30, WHITE );
    DrawRectangle (690, 460, 25, 25, BLACK);
    //This is to make the left eye
    DrawRectangle (870, 460, 25, 25, BLACK);
    //This is for the right eye
    ClearBackground(PURPLE);
    //This is to make a red background.
    break;

    }

     if (currentTime >= midTime) 
    {
        if (currentTime >= maxTime)
        {
            emotion = {"dissatisfied"};
            DrawRectangle (690, 460, 25, 25, WHITE);
        //This is to make the left eye
        DrawRectangle (870, 460, 25, 25, WHITE);
        //This is for the right eye
        ClearBackground(RED);
        //This is to make a red background.
        if (currentTime >= tooFar) 
        {CloseWindow();}

        }       
        else 
        {
            emotion = {"annoyed"};
        }
    }
    else 
    {
        emotion = {"satisfied"};
    }
    if (currentTime >= eatMaxTime)
    {   
        hunger = {"hungering"};
        if (currentTime < maxTime)
        {
            DrawRectangle (690, 460, 25, 25, PURPLE);
    //This is to make the left eye
    DrawRectangle (870, 460, 25, 25, PURPLE);
    //This is for the right eye
    ClearBackground(PURPLE);
        }  
    }
    DrawText(TextFormat("The Entity is feeling %s", emotion), 590, 710, 30, WHITE );
    DrawText(TextFormat("The Entity is %s", hunger), 675, 810, 30, WHITE );
    EndDrawing();
}
CloseWindow();

}