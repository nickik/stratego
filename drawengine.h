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
        SDL_Rect SDL_rec(figur, teamfarbe);
        void apply_surface( int , int , SDL_Surface* , SDL_Surface*, SDL_Rect* );
        static void screen_setter( SDL_Surface* );
        static SDL_Surface* screen_getter();
        static void token_image_setter( SDL_Surface* );
        static SDL_Surface* token_image_getter();
        static void set_token_clips();
        static SDL_Rect token_clips[12];
        static SDL_Surface* screen;
        static SDL_Surface* token_image;
        static SDL_Surface* load_image(std::string );
private:
        void coordinate_to_pixel( int*,int* );
};


#endif // DRAWENGINE_H_INCLUDED
