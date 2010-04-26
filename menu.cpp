#include <iostream>
#include "menu.h"

menu::menu( int x, int y, int w, int h, int mx, int my, SDL_Surface* screen, std::string message )
{
    init();
    font_setter( TTF_OpenFont( "bandy.ttf", 24 ));
    active = { 255, 255, 255 };
    inactive = { 208, 208, 208 };
    box.x = x;
    box.y = y;
    box.w = w;
    box.h = h;
    msg = message;
    draw( screen, mx, my );
}

menu::~menu()
{
    //not yet implented
}

bool menu::init()
{
    if( TTF_Init()  == -1 )
    {
        return false;
    }
    else
    {
        return true;
    }
}

void menu::draw( SDL_Surface* screen, int x, int y )
{
    drawengine DE;
    //The font surfaces
//    SDL_Surface * start_game = NULL;
//    SDL_Surface * join_game = NULL;
//    SDL_Surface * end_game = NULL;
//    SDL_Surface * about_stratego = NULL;
//    SDL_Surface * quit_game = NULL;
    SDL_Surface * message = NULL;

    //rendering messages
//    start_game = TTF_RenderText_Solid( font_getter(), "start game", active_getter() );
//    join_game = TTF_RenderText_Solid( font_getter(), "join game", active_getter() );
//    end_game = TTF_RenderText_Solid( font_getter(), "end game", active_getter() );
//    about_stratego = TTF_RenderText_Solid( font_getter(), "about Stratego", active_getter() );
//    quit_game = TTF_RenderText_Solid( font_getter(), "quit game", active_getter() );
    message = TTF_RenderText_Solid( font_getter(), msg.c_str(), active_getter() );

    //apply messages to screen
//    DE.apply_surface( 520, 50,  start_game, screen, NULL );
//    DE.apply_surface( 520, 100, join_game, screen, NULL );
//    DE.apply_surface( 520, 150, end_game, screen, NULL );
//    DE.apply_surface( 520, 200, about_stratego, screen, NULL );
//    DE.apply_surface( 520, 250, quit_game, screen, NULL );
    DE.apply_surface( x, y, message, screen, NULL );
}

void menu::font_setter( TTF_Font * ttf )
{
    font = ttf;
}

TTF_Font* menu::font_getter()
{
    return font;
}

SDL_Color menu::active_getter()
{
    return active;
}

SDL_Color menu::inactive_getter()
{
    return inactive;
}

//menu::button( int x, int y, int w, int h )
//{

//}

void menu::handle_events( SDL_Event event )
{
    int x = 0, y = 0;
    //If a mouse button was pressed
    if( event.type == SDL_MOUSEBUTTONDOWN )
    {
        //If the left mouse button was pressed
        if( event.button.button == SDL_BUTTON_LEFT )
        {
            //Get the mouse offsets
            x = event.button.x;
            y = event.button.y;

            //If the mouse is over the button
            if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) )
            {
                //Set the button sprite
                std::cout << "test";
            }
        }
    }
}
