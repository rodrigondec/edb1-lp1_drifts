void OnEvent(SDL_Event* Event){
	if(Event->type == SDL_QUIT) {
        Running = false;
    }
    if(screen == 0){
    	if(Event->type == SDL_MOUSEBUTTONDOWN && Event->button.button == SDL_BUTTON_LEFT){
	        screen = 1;
    	}
    }
    else if(screen == 1){

    }
    else if(screen == 2){
    	if(Event->type == SDL_MOUSEMOTION){
        	SDL_GetMouseState(&playerRect.x, &playerRect.y);
    	}
    }
    
    
}