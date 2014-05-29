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
        if(Event->type == SDL_MOUSEBUTTONDOWN && Event->button.button == SDL_BUTTON_LEFT){
            SDL_GetMouseState(&player.Rect.x, &player.Rect.y);
            if(player.Rect.x > rewindRect.x && player.Rect.x < (rewindRect.h+rewindRect.x) && 
               player.Rect.y > rewindRect.y && player.Rect.y < (rewindRect.w+rewindRect.y)){
                screen = 0;
            }
            else if(player.Rect.x > startgameRect.x && player.Rect.x < (startgameRect.x + startgameRect.w) &&
                    player.Rect.y > startgameRect.y && player.Rect.y < (startgameRect.y + startgameRect.h)){
                screen = 2;
            }
        }
    }
    else if(screen == 2){
    	if(Event->type == SDL_MOUSEMOTION){
        	SDL_GetMouseState(&player.Rect.x, &player.Rect.y);
    	}
    }
}