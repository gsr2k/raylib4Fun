#include "player.h"
#include <raylib.h>

void initPlayer (Player *p) 
{

    p -> x = 400.0f;
    p -> y = 300.0f;
    p -> speed = 05.0f;
    p -> width = 20.0f;
    p -> height = 20.0f;

}

void drawPlayer (Player *p)
{
    Rectangle playerSprite = { p->x, p->y, p->width, p->height};

    DrawRectangleRec (playerSprite, RED);
}

void updatePlayer (Player *p)
{
    //X
    if (IsKeyDown (KEY_RIGHT) || IsKeyDown (KEY_D)) {
        p->x += p->speed;
    }
        else if (IsKeyDown (KEY_LEFT) || IsKeyDown (KEY_A)) {
            p->x -= p->speed;
        }

    //Y
    if (IsKeyDown (KEY_DOWN) || IsKeyDown (KEY_S)) {
        p->y += p->speed;
    }
        else if (IsKeyDown (KEY_UP) || IsKeyDown (KEY_W)) {
            p->y -= p->speed;
        }

    //limit
    if (p -> x < 0) p -> x = 0;
    if (p -> x + p -> width > 800) p -> x = 800 - p -> width;
    if (p -> y < 0) p -> y = 0;
    if (p -> y + p -> height > 600) p -> y = 600 - p -> height;
}