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

		SDL_Rect startgameRect;
		SDL_Rect rewindRect;

		Player player;
        vector <Bola> bolas;

	public:
		Drifts();
		~Drifts();

		bool checker_create_bola;
		int clock_spawn;

		SDL_Texture* load_PNG(string path);

		void Collision();
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

