#include "menu.h"
#include "State.h"
#include <raylib.h>

    

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
        } else if (IsKeyPressed (KEY_UP)) {
            menuOption --;
        }

        switch (menuOption)
        {
        case 1: 
                DrawRectangleRec (option1, selected);
                DrawText("Play", 350 + (100 - MeasureText("Play", 15)) / 2, 292, 15, WHITE);                
            break;

        case 2:
                DrawRectangleRec (option2, selected);
                DrawText("Options", 350 + (100 - MeasureText("Options", 15)) / 2, 352, 15, WHITE);
            break;

        case 3:
                DrawRectangleRec (option3, selected);
                DrawText("About", 350 + (100 - MeasureText("About", 15)) / 2, 412, 15, WHITE);
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
 }
