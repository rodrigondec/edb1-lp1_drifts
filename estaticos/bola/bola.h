#ifndef __BOLA_H__
	#define __BOLA_H__

class Bola{
	private:
		bool attached;
    	string tipo;
    	bool direct_x;

	public:
		SDL_Rect Rect;

		Bola();
		~Bola();

		void mover();
		void attach();
		bool get_status();
		bool get_direct_x();
		string get_type();
};

#endif