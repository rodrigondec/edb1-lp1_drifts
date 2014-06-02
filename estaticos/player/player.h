#ifndef __PLAYER_H__
	#define __PLAYER_H__

class Player{
	private:
		int life;
	    int score;
	    SDL_Rect Icon;
	    SDL_Rect Life;
	    SDL_Rect Score;
	    SDL_Rect Rect;

	public:
		Player();
		~Player();

		void reset_life();
		void death();
		void reset_x_rscore();
		void incr_x_rscore(int n);
		void incr_score(int n);

		int get_life();
		int get_score();
		SDL_Rect* get_ricon();
		SDL_Rect* get_rlife();
		SDL_Rect* get_rscore();
		SDL_Rect* get_rrect();
		int* get_rrect_x();
		int* get_rrect_y();
};

#endif