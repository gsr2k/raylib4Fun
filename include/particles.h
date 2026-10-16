#pragma once
#include <raylib.h>

#define MAX_PARTICLES = 200

typedef struct
{
    Vector2 posXY;
    Vector2 speedXY;
    int alpha;
    bool active;
} Particles;

void initParticles (Particles particles [], int max);

void spawnParticles (Particles particles [], int max);

void drawParticles (Particles Particles [], int max, Texture2D *sprite);

void updateParticles (Particles particles [], int max, int *counter);