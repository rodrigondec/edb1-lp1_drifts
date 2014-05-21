void OnEvent(SDL_Event* Event){
	if(Event->type == SDL_QUIT) {
        Running = false;
    }
    if(Event->type == SDL_MOUSEMOTION){
        SDL_GetMouseState(&playerRect.x, &playerRect.y);
    }
}