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
    token_image = drawengine::load_image( "tokens.png" );
    screen =  SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    set_token_clips();

    //Set the window caption
    SDL_WM_SetCaption( "Stratego", NULL );
}

void set_token_clips()
{
    const int TOKEN_H = 42;

    token_clips[0].x = 0;
    token_clips[0].y = 0;
    token_clips[0].h = TOKEN_H;
    token_clips[0].w = TOKEN_H;

    token_clips[1].x = TOKEN_H;
    token_clips[1].y = 0;
    token_clips[1].h = TOKEN_H;
    token_clips[1].w = TOKEN_H;

    token_clips[2].x = TOKEN_H * 2;
    token_clips[2].y = 0;
    token_clips[2].h = TOKEN_H;
    token_clips[2].w = TOKEN_H;

    token_clips[3].x = TOKEN_H * 3;
    token_clips[3].y = 0;
    token_clips[3].h = TOKEN_H;
    token_clips[3].w = TOKEN_H;

    token_clips[4].x = TOKEN_H * 4;
    token_clips[4].y = 0;
    token_clips[4].h = TOKEN_H;
    token_clips[4].w = TOKEN_H;

    token_clips[5].x = TOKEN_H * 5;
    token_clips[5].y = 0;
    token_clips[5].h = TOKEN_H;
    token_clips[5].w = TOKEN_H;

    token_clips[6].x = 0;
    token_clips[6].y = TOKEN_H;
    token_clips[6].h = TOKEN_H;
    token_clips[6].w = TOKEN_H;

    token_clips[7].x = TOKEN_H;
    token_clips[7].y = TOKEN_H;
    token_clips[7].h = TOKEN_H;
    token_clips[7].w = TOKEN_H;

    token_clips[8].x = TOKEN_H * 2;
    token_clips[8].y = TOKEN_H;
    token_clips[8].h = TOKEN_H;
    token_clips[8].w = TOKEN_H;

    token_clips[9].x = TOKEN_H * 3;
    token_clips[9].y = TOKEN_H;
    token_clips[9].h = TOKEN_H;
    token_clips[9].w = TOKEN_H;

    token_clips[10].x = TOKEN_H * 4;
    token_clips[10].y = TOKEN_H;
    token_clips[10].h = TOKEN_H;
    token_clips[10].w = TOKEN_H;

    token_clips[11].x = TOKEN_H * 5;
    token_clips[11].y = TOKEN_H;
    token_clips[11].h = TOKEN_H;
    token_clips[11].w = TOKEN_H;
}


bool game :: run()
{
    bool quit = false;

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
