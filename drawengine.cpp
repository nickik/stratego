#include "drawengine.h"
//#include "SDL/SDL_image.h"

drawengine::drawengine()
{
    // nix zu tun hier
}

drawengine::~drawengine()
{
    // nix zu tun hier
}


void drawengine::erase_token(int x, int y)
{
   //not yet implems
}

void drawengine::draw_token(int x, int y, figur f, teamfarbe t)
{
    SDL_Rect rec = SDL_rec( f, t );
    apply_surface( x, y, token_image, screen, &rec);
}

SDL_Rect drawengine::SDL_rec(figur f, teamfarbe t)
{
    return token_clips[ (((int)f) - 1) ];
}

SDL_Surface* drawengine::load_image( std::string filename )
{
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = IMG_Load(filename.c_str());

    if( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormat( loadedImage );
        SDL_FreeSurface( loadedImage );
    }
    return optimizedImage;
}

void drawengine::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;

    SDL_BlitSurface( source, NULL, destination, &offset );
}

void drawengine::coordinate_to_pixel(int* x, int* y)
{
    int OBEN = 17;
    int LINKS =  17;

    x[1] = (x[1] * 42) + LINKS;
    y[1] = (y[1] * 42) + OBEN;

}
