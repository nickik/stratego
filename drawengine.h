#ifndef DRAWENGINE_H_INCLUDED
#define DRAWENGINE_H_INCLUDED

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

class drawengine{
public:
        drawengine();
        void erase_token( int x, int y );
        void draw_token( int x, int y );
private:
        (SDL_Surface *)load_image( std::string filename );
        void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
        koordinaten coordinate_to_pixel( koordinaten koords );
};


#endif // DRAWENGINE_H_INCLUDED
