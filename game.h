
/*
 * game.h
 *
 *  Created on: 19.04.2010
 *      Author: nick
 */
#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

class game {
public:
	game();
	virtual ~game();
	bool run();
	void getInput();
	void SendData();
	bool init();
	bool load_files();
	bool clean_up();
	void background_setter( (SDL_Surface *) );
	(SDL_Surface *) background_getter();
private:
    (SDL_Surface *)background;
};

#endif // GAME_H_INCLUDED
