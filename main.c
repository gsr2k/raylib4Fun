#include <raylib.h>
#include <stdbool.h>


int main (void)
{
   
    const int width = 800;
    const int height = 600;

    InitWindow (width, height, "Kanade Tachibana");

    InitAudioDevice ();

    Music kanadeTheme = LoadMusicStream ("resources/audios/KanadeTheme.mp3");

    PlayMusicStream (kanadeTheme);

    SetTargetFPS (60);

    int gameState = 1;
    int menuOption = 1;

    int textWidth = MeasureText("An Angel?", 15);

    //bool isOnMenu = true;

    //Color idle = WHITE;
    Color selected = PINK;

    //text color
    Color textHover = WHITE;
    //Color unselectText = BLACK;
    
    //game loop !!!
    while (!WindowShouldClose())
    {

        BeginDrawing ();

        switch (gameState)
        {
        //menu
        case 1:
            UpdateMusicStream (kanadeTheme);
            ClearBackground (BLACK);

            Rectangle option1  = {
            (800 - 100) / 2, // 350
            (600 - 50) / 2,  // 275
            100,
            50
        };

        Rectangle option2 = {
            (800 - 100) / 2, //350
            335,
            100,
            50
        };

        Rectangle option3 = {
            (800 - 100) / 2, //350
            395,
            100,
            50
        };


        DrawRectangleRec(option1, WHITE);
        DrawRectangleRec(option2, WHITE);
        DrawRectangleRec(option3, WHITE);

        DrawText("Play", 350 + (100 - MeasureText("Play", 15)) / 2, 292, 15, BLACK);
        DrawText("Options", 350 + (100 - MeasureText("Options", 15)) / 2, 352, 15, BLACK);
        DrawText("About", 350 + (100 - MeasureText("About", 15)) / 2, 412, 15, BLACK);

        if (IsKeyPressed (KEY_DOWN))
        {
            menuOption++;
        } else if (IsKeyPressed (KEY_UP)) {
            menuOption --;
        }

        switch (menuOption)
        {
        case 1: 
                DrawRectangleRec (option1, selected);
                DrawText("Play", 350 + (100 - MeasureText("Play", 15)) / 2, 292, 15, textHover);                
            break;

        case 2:
                DrawRectangleRec (option2, selected);
                DrawText("Options", 350 + (100 - MeasureText("Options", 15)) / 2, 352, 15, textHover);
            break;

        case 3:
                DrawRectangleRec (option3, selected);
                DrawText("About", 350 + (100 - MeasureText("About", 15)) / 2, 412, 15, textHover);
            break;
        
        default:
                //loop 
                if (menuOption > 3)
                    {
                        menuOption = 1;
                    } else if (menuOption < 1) {
                        menuOption = 3;
                    }

            break;
        }

        //main menu break
            break;
        // ==============================

        case 2:
            //empity
            break;

        default:
            break;
        }


    



        //end draw!!!!
        EndDrawing ();


    }

    UnloadMusicStream (kanadeTheme);

    CloseAudioDevice ();

    CloseWindow ();

    return 0;
}
