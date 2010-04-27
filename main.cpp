#include "game.h"
#include "SDL/SDL.h"

int main ( int argc, char** argv )
{
    game stratego;
    if (stratego.run() == false)
    {
        printf("Error");
    }
    return 0;
}
