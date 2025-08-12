
#include "raylib.h"

enum Type
{
    Moving,
    Idle
};

enum Movement
{
    X,
    Y
};

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
class wall
{
    public:
    Texture2D image = LoadTexture("images/png/workbenchSmall (2).png");
    Vector2 position;
    Rectangle collider;
    float size = 64;


    wall(float x, float y)
    {
        position = {x, y};
        collider = {x, y, size, size};
    }
    

};