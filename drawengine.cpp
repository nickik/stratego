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
    apply_surface( x, y, drawengine::token_image_getter(), drawengine::screen_getter(), &rec);
}

SDL_Rect drawengine::SDL_rec(figur f, teamfarbe t)
{
    return drawengine::token_clips[ (((int)f) - 1) ];
}

static SDL_Surface* load_image( std::string filename )
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

}

static void screen_setter( SDL_Surface* scr )
{
    drawengine::screen = scr;
}

static SDL_Surface* screen_getter()
{
    return drawengine::screen;
}

static void token_image_setter( std::string path )
{
    drawengine::token_image = load_image(path);
}

static SDL_Surface* token_image_getter()
{
    return drawengine::token_image;
}

static void set_token_clips()
{
    const int TOKEN_H = 42;

    drawengine::token_clips[0].x = 0;
    drawengine::token_clips[0].y = 0;
    drawengine::token_clips[0].h = TOKEN_H;
    drawengine::token_clips[0].w = TOKEN_H;

    drawengine::token_clips[1].x = TOKEN_H;
    drawengine::token_clips[1].y = 0;
    drawengine::token_clips[1].h = TOKEN_H;
    drawengine::token_clips[1].w = TOKEN_H;

    drawengine::token_clips[2].x = TOKEN_H * 2;
    drawengine::token_clips[2].y = 0;
    drawengine::token_clips[2].h = TOKEN_H;
    drawengine::token_clips[2].w = TOKEN_H;

    drawengine::token_clips[3].x = TOKEN_H * 3;
    drawengine::token_clips[3].y = 0;
    drawengine::token_clips[3].h = TOKEN_H;
    drawengine::token_clips[3].w = TOKEN_H;

    drawengine::token_clips[4].x = TOKEN_H * 4;
    drawengine::token_clips[4].y = 0;
    drawengine::token_clips[4].h = TOKEN_H;
    drawengine::token_clips[4].w = TOKEN_H;

    drawengine::token_clips[5].x = TOKEN_H * 5;
    drawengine::token_clips[5].y = 0;
    drawengine::token_clips[5].h = TOKEN_H;
    drawengine::token_clips[5].w = TOKEN_H;

    drawengine::token_clips[6].x = 0;
    drawengine::token_clips[6].y = TOKEN_H;
    drawengine::token_clips[6].h = TOKEN_H;
    drawengine::token_clips[6].w = TOKEN_H;

    drawengine::token_clips[7].x = TOKEN_H;
    drawengine::token_clips[7].y = TOKEN_H;
    drawengine::token_clips[7].h = TOKEN_H;
    drawengine::token_clips[7].w = TOKEN_H;

    drawengine::token_clips[8].x = TOKEN_H * 2;
    drawengine::token_clips[8].y = TOKEN_H;
    drawengine::token_clips[8].h = TOKEN_H;
    drawengine::token_clips[8].w = TOKEN_H;

    drawengine::token_clips[9].x = TOKEN_H * 3;
    drawengine::token_clips[9].y = TOKEN_H;
    drawengine::token_clips[9].h = TOKEN_H;
    drawengine::token_clips[9].w = TOKEN_H;

    drawengine::token_clips[10].x = TOKEN_H * 4;
    drawengine::token_clips[10].y = TOKEN_H;
    drawengine::token_clips[10].h = TOKEN_H;
    drawengine::token_clips[10].w = TOKEN_H;

    drawengine::token_clips[11].x = TOKEN_H * 5;
    drawengine::token_clips[11].y = TOKEN_H;
    drawengine::token_clips[11].h = TOKEN_H;
    drawengine::token_clips[11].w = TOKEN_H;
}
