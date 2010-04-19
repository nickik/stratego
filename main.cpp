#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif
#ifdef __APPLE__
#include <SDL/SDL.h>
#else
#include <SDL/SDL.h>
#endif

int main ( int argc, char** argv )
{
    if (Game.run() == false)
    {
        printf("Error");
    }
    return 0;
}
