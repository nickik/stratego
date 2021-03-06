
/*
 * game.h
 *
 *  Created on: 19.04.2010
 *      Author: nick
 */

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "drawengine.h"
#include "timer.h"
#include "network.h"
#include "menu.h"
#include "level.h"
#include "globals.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class game {
public:
	game();
	virtual ~game();
	bool run();
	void getInput();
	void SendData();
	bool init();
	bool load_files();
	void clean_up();
	void background_setter( SDL_Surface* );
	void set_token_clips();
	SDL_Surface* background_getter();
private:
    SDL_Surface* background;
};

#endif // GAME_H_INCLUDED
