
/*
 * game.h
 *
 *  Created on: 19.04.2010
 *      Author: nick
 */

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "drawengine.h"
#include "helpder.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class game {
public:
	game();
	virtual ~game();
	bool run();
	void getInput();
	void SendData();
	SDL_Surface* init(SDL_Surface*);
	bool load_files();
	void clean_up();
	void background_setter( SDL_Surface* );
	SDL_Surface* background_getter();
private:
    SDL_Surface* background;
};

#endif // GAME_H_INCLUDED
