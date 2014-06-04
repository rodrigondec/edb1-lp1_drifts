#ifndef __BOLA_H__
	#define __BOLA_H__

class Bola{
	private:
		bool attached;
    	string tipo;
    	bool accel_x;
    	bool accel_y;

	public:
		SDL_Rect Rect;

		Bola();
		~Bola();

		void mover();
		void attach();
		bool get_status();
		bool get_accel_x();
		bool get_accel_y();
		string get_type();
};

#endif