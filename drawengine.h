#ifndef DRAWENGINE_H_INCLUDED
#define DRAWENGINE_H_INCLUDED

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "helpder.h"

class drawengine{
public:
        drawengine();
        virtual ~drawengine();
        void erase_token( int , int  );
        void draw_token( int , int  );
        SDL_Surface* load_image( std::string );
private:
        void apply_surface( int , int , SDL_Surface* , SDL_Surface* );
        koordinaten coordinate_to_pixel( koordinaten );
};


#endif // DRAWENGINE_H_INCLUDED
