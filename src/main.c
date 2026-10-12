#include <raylib.h>
#include <stdbool.h>
#include "menu.h"
#include "State.h"
#include "music.h"

enum gameState currentState = ON_MENU;
enum gameState previousState = ON_MENU;

bool musicStarted = true;

/*void updateMusicState (Music aliveMusic, Music previousMusic)
{
    static enum gameState previousState = ON_MENU;
    
        if (currentState != previousState)
        {
            switch (currentState)
            {
            case ON_MENU:
                    StopMusicStream (previousMusic);
                    PlayMusicStream (aliveMusic);
                break;
            
            default:
                break;
            }
        }
}

Music startMusicState (Music Name)
{
    if (currentState == ON_MENU)
    {
        PlayMusicStream (Name);
    } 
} 
*/    
    

int main (void)
{
    const int width = 800;
    const int height = 600;

    InitWindow (width, height, "Kanade Tachibana");

    InitAudioDevice ();

    Music mainTheme = LoadMusicStream ("resources/audios/mainTheme.mp3");
    Music mainVariation = LoadMusicStream ("resources/audios/mainVariation.mp3");
    Music testOption = LoadMusicStream ("resources/audios/Test.mp3");
    Music kanadeTheme = LoadMusicStream ("resources/audios/KanadeTheme.mp3");
    

    SetTargetFPS (60);

    int textWidth = MeasureText("An Angel?", 15);

    Color selected = PINK;

    Color textHover = WHITE;
    
    //game loop !!!
    while (!WindowShouldClose())
    {

        BeginDrawing ();

        ClearBackground (BLACK);

        switch (currentState)
        {
        case ON_MENU:
                drawMenu();
            break;
        
        case ON_GAME:
                DrawText ("hello", 350, 100, 35, RED);
                
            break;

        case ON_OPTIONS:
                
            break;

        case ON_CREDITS:
        
            break;

        default:
            break;
        }
        
        updateMusicState (mainTheme, testOption, mainVariation, kanadeTheme);

        //end draw!!!!
        EndDrawing ();


    }

    CloseAudioDevice ();

    CloseWindow ();

    return 0;
}
