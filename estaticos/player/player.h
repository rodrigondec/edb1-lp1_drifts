#ifndef __PLAYER_H__
	#define __PLAYER_H__

class Player{
	private:
		int life;
	    int score;
	    

	public:
		SDL_Rect Icon;
	    SDL_Rect Life;
	    SDL_Rect Score;
	    SDL_Rect Rect;

		Player();
		~Player();

		void reset_life();
		void reset_score();
		void death();
		void reset_x_rscore();
		void incr_score(int n);

		int get_life();
		int get_score();
		
};

#endif