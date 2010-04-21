#ifndef DRAWENGINE_H_INCLUDED
#define DRAWENGINE_H_INCLUDED

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "feld.h"

class drawengine{
public:
        drawengine();
        virtual ~drawengine();
        void erase_token( int , int  );
        void draw_token( int , int  );
        SDL_Surface* load_image( std::string );
        void apply_surface( int , int , SDL_Surface* , SDL_Surface*, SDL_Rect* );
private:
        koordinaten coordinate_to_pixel( koordinaten );
};


#endif // DRAWENGINE_H_INCLUDED
