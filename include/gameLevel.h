#pragma once
#include <raylib.h>
#include "player.h"

typedef struct 
{
    Texture2D backgroundAsset;
} GameLevel;

void initGameLevel(GameLevel *level, const char *bgPath);
void unloadGameLevel(GameLevel *level);
void drawBackground(GameLevel *level);
void drawAssets(GameLevel *level, Player *player);