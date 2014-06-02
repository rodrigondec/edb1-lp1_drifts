#ifndef __BOLA_H__
	#define __BOLA_H__

class Bola{
	private:
		bool attached;
    	string tipo;

	public:
		SDL_Rect Rect;

		Bola();
		~Bola();

		void mover();
		void attach();
		bool get_status();

		string get_type();
};

#endif