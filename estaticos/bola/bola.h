#ifndef __BOLA_H__
	#define __BOLA_H__

class Bola{
	private:
		bool attached;
    	string tipo;
    	int bola_to_mouse[4];
    	int accel_x;
    	int accel_y;

	public:
		SDL_Rect Rect;

		Bola();
		~Bola();

		void mover();
		void attach(int mouse_x, int mouse_y);
		void set_type(string type);
		void seguir_mouse(int mouse_x, int mouse_y);
		void invert_accel_x();
		void invert_accel_y();
		void parada();
		bool get_status();
		int get_accel_x();
		int get_accel_y();
		string get_type();
};

#endif