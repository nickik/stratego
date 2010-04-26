#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <string>
#include "SDL/SDL_ttf.h"
#include "drawengine.h"

//SDL_Event m_event;

class menu{
public:
    menu( int, int, int, int, int, int, SDL_Surface*, std::string message );
    virtual ~menu();
    bool init();
	void font_setter( TTF_Font* );
	void draw( SDL_Surface*, int, int );
//    button( int, int, int, int );
    void handle_events( SDL_Event );
	TTF_Font* font_getter();
	SDL_Color active_getter();
	SDL_Color inactive_getter();
private:
    TTF_Font* font;
    SDL_Color active;
    SDL_Color inactive;
    SDL_Rect box;
    std::string msg;

};

#endif // MENU_H_INCLUDED
