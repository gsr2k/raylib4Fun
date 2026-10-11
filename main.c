#include <raylib.h>
#include <stdbool.h>
#include "menu.h"
#include "State.h"


int main (void)
{
    enum gameState startGame = ON_MENU;
    const int width = 800;
    const int height = 600;

    InitWindow (width, height, "Kanade Tachibana");

    InitAudioDevice ();

    Music kanadeTheme = LoadMusicStream ("resources/audios/KanadeTheme.mp3");
    PlayMusicStream (kanadeTheme);

    SetTargetFPS (60);

    int textWidth = MeasureText("An Angel?", 15);

    Color selected = PINK;

    Color textHover = WHITE;
    
    //game loop !!!
    while (!WindowShouldClose())
    {

        BeginDrawing ();

        switch (startGame)
        {
        case ON_MENU:
                drawMenu();
                UpdateMusicStream (kanadeTheme);
            break;
        
        default:
            break;
        }
        


        //end draw!!!!
        EndDrawing ();


    }

    CloseAudioDevice ();

    CloseWindow ();

    return 0;
}
