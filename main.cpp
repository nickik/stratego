#include "game.h"
#include "SDL/SDL.h"

SDL_Rect token_clips[12];
SDL_Surface* screen;


int main ( int argc, char** argv )
{
    game stratego;
    if (stratego.run() == false)
    {
        printf("Error");
    }
    return 0;
}
