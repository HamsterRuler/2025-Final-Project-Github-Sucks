#include "raylib.h"

class Item
{
    public:
    Texture2D image =LoadTexture("images/png/ammmo.png");
    Vector2 position;
    Rectangle collider;
    bool colect = false;
    float size = 70;
    Item(float x, float y)
    {
        position = {x,y};
        collider = {x, y, size, size};
    }
};