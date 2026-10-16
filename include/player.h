#pragma once
#include <raylib.h>

typedef struct {
    float x;
    float y;
    float speed;
    float width;
    float height;
} Player;

void initPlayer (Player *p);
void drawPlayer (Player *p);
void updatePlayer (Player *p);

