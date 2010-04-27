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
    background_setter(drawengine::load_image( "background.png" ));

    //If there was a problem in loading the dot
    if( background_getter() == NULL )
    {
        return false;
    }

    //If everything loaded fine
    return true;
}

bool game::init()
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
//    drawengine::screen_setter( SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE ));

    token_image = drawengine::load_image( "tokens.png" );

    //Set the window caption
    SDL_WM_SetCaption( "Stratego", NULL );
}

bool game :: run()
{
    bool quit = false;

    //The surfaces;
    SDL_Surface * screen = NULL;

    //Initialize
    init();

    //Load the files
    if( load_files() == false ){
        return 1;
    }


    //The frame rate
    const int FRAMES_PER_SECOND = 20;
    timer fps;

    //The event structure
    SDL_Event event;

    drawengine DE;
    menu MN_start( 520, 50, 70, 25,  "start game" );
    menu MN_join( 550, 100, 70, 25, "join game" );
    menu MN_end( 550, 150, 70, 25, "end game" );
    menu MN_about( 520, 200, 70, 25, "about Stratego" );
    menu MN_quit( 520, 250, 70, 25, "quit game" );

/*
    level l;
    if(aufstellung(l) == false)
    {
        return false;
    }
*/


    while( quit == false )
    {
        fps.start();
        while( SDL_PollEvent( &event ) )
        {
            if( event.type == SDL_QUIT )
            {
                quit = true;
            }
        }

        DE.apply_surface( 0, 0, background_getter(), screen, NULL );

        MN_start.draw();
        MN_join.draw();
        MN_end.draw();
        MN_about.draw();
        MN_quit.draw();

        MN_start.handle_events( event );
        MN_join.handle_events( event );
        MN_end.handle_events( event );
        MN_about.handle_events( event );
        MN_quit.handle_events( event );

        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        if( fps.ticks_getter() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.ticks_getter() );
        }
    }
    return true;
}
