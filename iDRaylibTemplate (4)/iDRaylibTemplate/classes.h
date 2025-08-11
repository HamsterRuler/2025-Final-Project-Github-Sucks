
#include "raylib.h"

class Item
{
    public:
    Texture2D image = LoadTexture("images/png/ammo.png");
    Vector2 position;
    Rectangle collider;
    bool collect = false;
    float size = 54;

    Item(float x, float y)
    {
        position = {x,y};
        collider = {x, y, size, size};
    }
};

class Wall
{
    public:
    Texture2D image = LoadTexture("images/png/workbenchSmall (1) (7).png");
    Vector2 position;
    Rectangle collider;
    float size = 64;

    Wall(float x, float y)
    {
        position = {x,y};
        collider = {x, y, size, size};
    }
};