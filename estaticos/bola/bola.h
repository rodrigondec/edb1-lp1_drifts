#ifndef __BOLA_H__
	#define __BOLA_H__

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
		SDL_Rect* get_rect();
		string get_type();
};

#endif