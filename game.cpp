/*
 * game.h
 *
 *  Created on: 19.04.2010
 *      Author: nick
 */

#include "game.h"

game::game()
{
    //Was ist den los? ich kriege ja gar nix zu tuen hier
}

game::~game()
{
    //Was ist den los? ich kriege ja gar nix zu tuen hier
}


void game::background_setter( SDL_Surface * back )
{
    background = back;
}

SDL_Surface* game::background_getter()
{
    return background;
}

void game::clean_up()
{
    //Quit SDL
    SDL_Quit();
}

bool game::load_files()
{
    //Load the dot image
    drawengine DE;
    background_setter(DE.load_image( "background.png" ));

    //If there was a problem in loading the dot
    if( background_getter() == NULL )
    {
        return false;
    }
    //If everything loaded fine
    return true;
}

SDL_Surface* game::init(SDL_Surface* screen)
{
    //Screen attributes
    int SCREEN_WIDTH = 800;
    int SCREEN_HEIGHT = 480;
    int SCREEN_BPP = 32;

    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
/*
    if( screen == NULL )
    {
        return false;
    }
*/
    //Set the window caption
    SDL_WM_SetCaption( "Stratego", NULL );

    //If everything initialized fine
    return screen;
}

bool game :: run()
{
    bool quit = false;

    //The surfaces;
    SDL_Surface * screen = NULL;

    //Initialize
    screen = init(screen);

    //Load the files
    if( load_files() == false ){
        return 1;
    }

    //The frame rate
    //const int FRAMES_PER_SECOND = 20;

    //The event structure
    SDL_Event event;

    drawengine DE;
    DE.apply_surface( 0, 0, background_getter(), screen, NULL );

    if( SDL_Flip( screen ) == -1 )
    {
        return 1;
    }

    SDL_Delay( 2000 );
/*
    while( quit == false)
    {
        //If the user has Xed out the window
        if( event.type == SDL_QUIT )
        {
            //Quit the program
            quit = true;
        }

    }
*/
    return 0;
}
