void Drifts::OnEvent(SDL_Event* Event){
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
            if(player.Rect.x > rewindRect.x && player.Rect.x < (rewindRect.x + rewindRect.w) && 
               player.Rect.y > rewindRect.y && player.Rect.y < (rewindRect.y + rewindRect.h)){
                screen = 0;
            }
            else if(player.Rect.x > startgameRect.x && player.Rect.x < (startgameRect.x + startgameRect.w) &&
                    player.Rect.y > startgameRect.y && player.Rect.y < (startgameRect.y + startgameRect.h)){
                screen = 2;
                SDL_ShowCursor(0);
            }
        }
    }
    else if(screen == 2){
    	if(Event->type == SDL_MOUSEMOTION){
        	SDL_GetMouseState(&player.Rect.x, &player.Rect.y);
    	}
        if(Event->type == SDL_MOUSEBUTTONDOWN && Event->button.button == SDL_BUTTON_LEFT){
            if((player.Rect.x + 20) > pauseplayRect.x && (player.Rect.x + 20) < (pauseplayRect.x + pauseplayRect.w) && 
               (player.Rect.y + 20) > pauseplayRect.y && (player.Rect.y + 20) < (pauseplayRect.y + pauseplayRect.h)){
                paused = !paused;
            }
        }
    }
    else if(screen == 3){
        if(Event->type == SDL_MOUSEBUTTONDOWN && Event->button.button == SDL_BUTTON_LEFT){
            SDL_GetMouseState(&player.Rect.x, &player.Rect.y);
            if(player.Rect.x > 200 && player.Rect.x < 400 && 
               player.Rect.y > letraRect.y && player.Rect.y < (letraRect.h+letraRect.y)){
                screen = 2;
                SDL_ShowCursor(0);
            }
            if(player.Rect.x > gameoverRect.x && player.Rect.x < (gameoverRect.x + gameoverRect.w) && 
               player.Rect.y > gameoverRect.y && player.Rect.y < (gameoverRect.y + gameoverRect.h)){
                screen = 0;
            }
        }
    }
}