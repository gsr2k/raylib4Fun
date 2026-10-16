#include "gameLevel.h"

void initGameLevel(GameLevel *level, const char *bgPath)
{
    Image img = LoadImage(bgPath);
    level->backgroundAsset = LoadTextureFromImage(img);
    UnloadImage(img);
}

void unloadGameLevel(GameLevel *level)
{
    UnloadTexture(level->backgroundAsset);
}

void drawBackground(GameLevel *level)
{
    Rectangle source = { 0.0f, 0.0f, (float)level->backgroundAsset.width, (float)level->backgroundAsset.height };
    Rectangle dest   = { 0.0f, 0.0f, 800.0f, 600.0f };
    Vector2 origin   = { 0.0f, 0.0f };

    DrawTexturePro(level->backgroundAsset, source, dest, origin, 0.0f, WHITE);
}

void drawAssets(GameLevel *level, Player *player)
{
    drawPlayer(player);
    updatePlayer(player);
}