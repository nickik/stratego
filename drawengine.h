#ifndef DRAWENGINE_H_INCLUDED
#define DRAWENGINE_H_INCLUDED

//#include "token.h"
//#include "feld.h"
//#include "level.h"
#include "helper.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>


class drawengine{

public:
        drawengine();
        virtual ~drawengine();
        void erase_token(int,int);
        void draw_token( int, int, figur, teamfarbe);
        void apply_surface( int, int, SDL_Surface*, SDL_Surface*, SDL_Rect* );
        SDL_Rect SDL_rec(figur, teamfarbe);
        SDL_Surface* load_image(std::string );
private:
        void coordinate_to_pixel( int*,int* );
};


#endif // DRAWENGINE_H_INCLUDED
