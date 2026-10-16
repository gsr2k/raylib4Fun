#include <raylib.h>
#include <stdbool.h>
#include "menu.h"
#include "State.h"
#include "music.h"
#include "player.h"
#include "options.h"
#include "particles.h"
#include "gameLevel.h"

enum gameState currentState = ON_MENU;
enum gameState previousState = ON_MENU;

Player mainPlayer;
Particles particles;

int main (void)
{

    int frameCounter = 0;
    int animCounter = 0;
    const int width = 800;
    const int height = 600;

    InitWindow (width, height, "Innocence");

    Image Star = LoadImage ("resources/sprites/starSprite.png");
    Texture2D starSprite = LoadTextureFromImage (Star);
    UnloadImage (Star);

    GameLevel mainLevel;
    initGameLevel(&mainLevel, "resources/sprites/gameBackground.jpg");

    InitAudioDevice ();

    Music menuTheme = LoadMusicStream ("resources/audios/menuTheme.mp3");
    Music menuVariation = LoadMusicStream ("resources/audios/menuVariation.mp3");
    Music gameTheme = LoadMusicStream ("resources/audios/mainGame.mp3");
    Music aboutTheme = LoadMusicStream ("resources/audios/aboutTheme.mp3");
    

    SetTargetFPS (60);

    int textWidth = MeasureText("An Angel?", 15);

    Color selected = PINK;

    Color textHover = WHITE;
    
    Particles particles [200];
    initParticles (particles, 200);
    initPlayer (&mainPlayer);
    
    //game loop !!!
    while (!WindowShouldClose())
    {

        
        BeginDrawing ();

        ClearBackground (BLACK);

        switch (currentState)
        {
        case ON_MENU:
                frameCounter++;
                animCounter ++;
                if (frameCounter >= 10) {
                    spawnParticles (particles, 200);
                    frameCounter = 0;
                }
                drawParticles (particles, 200, &starSprite);
                if (animCounter >= 1)
                {
                    updateParticles (particles, 200, &animCounter);
                    animCounter = 0;
                }
                drawMenu();
            break;
        
        case ON_GAME:
                drawBackground(&mainLevel);
                drawAssets(&mainLevel, &mainPlayer);
            break;

        case ON_OPTIONS:
                
            break;

        case ON_CREDITS:
        
            break;

        default:
            break;
        }
        
        //the parameters are in the same orden as the switch/enum
        updateMusicState (&menuTheme, &gameTheme, &menuVariation, &aboutTheme);
        
        //end draw!!!!
        EndDrawing ();


    }

    unloadGameLevel(&mainLevel);

    CloseAudioDevice ();

    CloseWindow ();

    return 0;
}


//TODO: Clean up main.c XD
//this code looks baadd
//anyways, we can always improve ;)