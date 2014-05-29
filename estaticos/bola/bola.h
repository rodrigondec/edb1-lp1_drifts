#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>

#ifndef __BOLA_H__
	#define __BOLA_H__

using std::string;

class Bola{
	private:
		bool attached;
    	string tipo;
    	SDL_Rect Rect;

	public:
		Bola();
		~Bola();

		void mover();
		void colision();

		int get_x();
		int get_y();
};

#endif