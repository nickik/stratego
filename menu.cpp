#include <iostream>
#include "menu.h"

menu::menu( int x, int y, int w, int h, std::string message )
{
    init();
    font_setter( TTF_OpenFont( "bandy.ttf", 24 ));
    active = { 255, 255, 255 };
    inactive = { 208, 208, 208 };
    this->box.x = x;
    this->box.y = y;
    this->box.w = w;
    this->box.h = h;
    this->msg = message;
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

void menu::draw()
{
    drawengine DE;
    SDL_Surface * message = NULL;

    //rendering message
    message = TTF_RenderText_Solid( font_getter(), msg.c_str(), active_getter() );

    //apply message to screen
    DE.apply_surface( this->box.x, this->box.y, message,  screen, NULL);
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
                std::cout << "test: " << this->msg << "\n";
            }
        }
    }
}
