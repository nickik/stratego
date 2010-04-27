#ifndef DRAWENGINE_H_INCLUDED
#define DRAWENGINE_H_INCLUDED

#include "token.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>


class drawengine{
public:
        drawengine();
        virtual ~drawengine();
        void erase_token(int,int);
        //void draw_token(koordinaten, figur, teamfarbe);
        //SDL_Surface* SDL_rect(figur, teamfarbe);
        SDL_Surface* load_image(std::string );
        void apply_surface( int , int , SDL_Surface* , SDL_Surface*, SDL_Rect* );
private:
        void coordinate_to_pixel( int*,int* );
};


#endif // DRAWENGINE_H_INCLUDED
