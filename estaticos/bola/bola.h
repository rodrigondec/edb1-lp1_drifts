#ifndef __BOLA_H__
	#define __BOLA_H__

class Bola{
	private:
		bool attached;
    	string tipo;
    	int accel_x;
    	int accel_y;

	public:
		SDL_Rect Rect;

		Bola();
		~Bola();

		void mover();
		void attach();
		void invert_accel_x();
		void invert_accel_y();
		void parada();
		bool get_status();
		int get_accel_x();
		int get_accel_y();
		string get_type();
};

#endif