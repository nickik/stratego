#include "drawengine.h"

void drawengine::erase_token(int x, int y)
{
  //not yet implemented
}

void drawengine::draw_token(int x, int y)
{
  //not yet implemented
}

(SDL_Surface *)drawengine::load_image( std::string filename )
{
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = IMG_Load( filename.c_str() );

    if( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormat( loadedImage );
        SDL_FreeSurface( loadedImage );
    }

    return optimizedImage;
}


void drawengine::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;

    SDL_BlitSurface( source, NULL, destination, &offset );
}

koordinaten drawengine::coordinate_to_pixel()
{
  //not yet implemented
}
