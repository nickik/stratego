#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <string>
#include "SDL/SDL_ttf.h"
#include "drawengine.h"
#include "globals.h"

//SDL_Event m_event;

class menu{
public:
    menu( int, int, int, int, std::string message );
//    menu();
    virtual ~menu();
    bool init();
	void font_setter( TTF_Font* );
	void draw();
//    button( int, int, int, int );
    void handle_events( SDL_Event );
	TTF_Font* font_getter();
	SDL_Color active_getter();
	SDL_Color inactive_getter();

    TTF_Font* font;
    SDL_Color active;
    SDL_Color inactive;
    SDL_Rect box;
    std::string msg;
    SDL_Surface* scr;
    int my;
    int mx;
private:
};

#endif // MENU_H_INCLUDED
