#include <raylib.h>
#include "State.h"

extern enum gameState currentState;

void updateMusicState(
    Music *mainTheme,
    Music *gameTheme,
    Music *optionsTheme,
    Music *creditsTheme
)
{
    static int previousState = 0;

    if (previousState != currentState)
    {
        switch (previousState)
        {
            case ON_MENU:
                StopMusicStream(*mainTheme);
                break;

            case ON_GAME:
                StopMusicStream(*gameTheme);
                break;

            case ON_OPTIONS:
                StopMusicStream(*optionsTheme);
                break;

            case ON_CREDITS:
                StopMusicStream(*creditsTheme);
                break;
        }

        switch (currentState)
        {
            case ON_MENU:
                PlayMusicStream(*mainTheme);
                break;

            case ON_GAME:
                PlayMusicStream(*gameTheme);
                break;

            case ON_OPTIONS:
                PlayMusicStream(*optionsTheme);
                break;

            case ON_CREDITS:
                PlayMusicStream(*creditsTheme);
                break;
        }

        previousState = currentState;
    }

    switch (currentState)
    {
        case ON_MENU:
            UpdateMusicStream(*mainTheme);
            break;

        case ON_GAME:
            UpdateMusicStream(*gameTheme);
            break;

        case ON_OPTIONS:
            UpdateMusicStream(*optionsTheme);
            break;

        case ON_CREDITS:
            UpdateMusicStream(*creditsTheme);
            break;
    }
}
