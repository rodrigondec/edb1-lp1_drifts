#ifndef __DRIFTS_H__
	#define __DRIFTS_H__

class Drifts{
	private:
		bool Running;
		int screen;

		int WindowWidth;
		int WindowHeight;

		SDL_Window* Window;
		SDL_Texture* TextureBank[TOTAL_IMG];
		SDL_Renderer* Renderer;
		SDL_Event Event;

		Mix_Music *Music;

		SDL_Rect startgameRect;
		SDL_Rect gameoverRect;
		SDL_Rect rewindRect;
		SDL_Rect pauseplayRect;
		SDL_Rect letraRect;

		Player player;
        vector <Bola> bolas;

	public:
		Drifts();
		~Drifts();

		bool checker_create_bola;
		int paused;
		int rip;
		int checker_move_bola;
		int clock_spawn;
		int invert_accel;
		int get_more_pointers;
		int counter_pointers;

		SDL_Texture* load_PNG(string path);
		void load_WAV(string path);

		void Collision(int indice);
		int get_secs();
		void Run();
		void Cleanup();
		void Create_Bola();
		bool Init();
		void Loop();
		void OnEvent(SDL_Event* Event);
		void Render();
};

#endif

