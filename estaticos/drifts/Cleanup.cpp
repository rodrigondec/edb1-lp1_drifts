void Drifts::Cleanup(){
	if(Music){
		Mix_FreeMusic(Music);
		Music = NULL;
	}
	if(Renderer){
		SDL_DestroyRenderer(Renderer);
		Renderer = NULL;
	}

	if(Window){
		SDL_DestroyWindow(Window);
		Window = NULL;
	}
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}