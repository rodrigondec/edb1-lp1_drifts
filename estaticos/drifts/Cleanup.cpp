void Cleanup(){

	if(Renderer) {
		SDL_DestroyRenderer(Renderer);
		Renderer = NULL;
	}

	if(Window) {
		SDL_DestroyWindow(Window);
		Window = NULL;
	}
	//differ
	IMG_Quit();
	SDL_Quit();
}