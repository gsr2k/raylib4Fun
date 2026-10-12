#include "menu.h"
#include "State.h"
#include <raylib.h>

 extern enum gameState currentState;

 void drawMenu (void)
 {
        int static menuOption = 1;
        Color selected = PINK;
        Color textHover = WHITE;

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
            if (menuOption > 3) menuOption = 1;
        } else if (IsKeyPressed (KEY_UP)) {
            menuOption --;
            if (menuOption < 1) menuOption = 3;
        }

        if (IsKeyPressed(KEY_ENTER)) {
        if (menuOption == 1) currentState = ON_GAME;
        else if (menuOption == 2) currentState = ON_OPTIONS;
        else if (menuOption == 3) currentState = ON_CREDITS;
        }

        DrawRectangleRec(option1, (menuOption == 1) ? PINK : WHITE);
        DrawRectangleRec(option2, (menuOption == 2) ? PINK : WHITE);
        DrawRectangleRec(option3, (menuOption == 3) ? PINK : WHITE);

        DrawText("Play",    350 + (100 - MeasureText("Play", 15)) / 2,    292, 15, (menuOption == 1) ? WHITE : BLACK);
        DrawText("Options", 350 + (100 - MeasureText("Options", 15)) / 2, 352, 15, (menuOption == 2) ? WHITE : BLACK);
        DrawText("About",   350 + (100 - MeasureText("About", 15)) / 2,   412, 15, (menuOption == 3) ? WHITE : BLACK);
 }
