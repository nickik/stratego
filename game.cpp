/*
 * game.h
 *
 *  Created on: 19.04.2010
 *      Author: nick
 */

#include "game.h"


void game::background_setter( (SDL_Surface *) back )
{
    background = back;
}

(SDL_Surface *) game::background_getter()
{
    return background;
}

void game::clean_up()
{
    //Free the surface
    SDL_FreeSurface( background );

    //Quit SDL
    SDL_Quit();
}

bool game::load_files()
{
    //Load the dot image
    background = load_image( "background.png" );

    //If there was a problem in loading the dot
    if( background == NULL )
    {
        return false;
    }
    //If everything loaded fine
    return true;
}

bool game::init(int SCREEN_WIDTH, int SCREEN_HEIGHT, int SCREEN_BPP)
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Stratego", NULL );

    //If everything initialized fine
    return true;
}

bool game :: run()
{
    bool quit = false;

    //Screen attributes
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 480;
    const int SCREEN_BPP = 32;


    //Initialize
    if( init(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP) == false )
    {
        return 1;
    }

    //Load the files
    if( load_files() == false )
    {
        return 1;
    }


    //The frame rate
    const int FRAMES_PER_SECOND = 20;

    //The surfaces
    SDL_Surface *dot = NULL;
    SDL_Surface *screen = NULL;

    //The event structure
    SDL_Event event;




    while( quit = false)
    {
        //If the user has Xed out the window
        if( event.type == SDL_QUIT )
        {
            //Quit the program
            quit = true;
        }

    }
}
