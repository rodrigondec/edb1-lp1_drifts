void Drifts::OnEvent(SDL_Event* Event){
	if(Event->type == SDL_QUIT) {
        Running = false;
    }
    if(screen == CREDITOS){
    	if(Event->type == SDL_MOUSEBUTTONDOWN && Event->button.button == SDL_BUTTON_LEFT){
            SDL_GetMouseState(&player.Rect.x, &player.Rect.y);
            if(player.Rect.x > soundRect.x && player.Rect.x < (soundRect.x + soundRect.w) && 
               player.Rect.y > soundRect.y && player.Rect.y < (soundRect.y + soundRect.h)){
                if(!Mix_PausedMusic()){
                    Mix_PauseMusic();
                }
                else{
                    Mix_ResumeMusic();
                }
            }
            else{
                screen = MENU;
            }
    	}
    }
    else if(screen == MENU){
        if(Event->type == SDL_MOUSEBUTTONDOWN && Event->button.button == SDL_BUTTON_LEFT){
            SDL_GetMouseState(&player.Rect.x, &player.Rect.y);
            if(player.Rect.x > rewindRect.x && player.Rect.x < (rewindRect.x + rewindRect.w) && 
               player.Rect.y > rewindRect.y && player.Rect.y < (rewindRect.y + rewindRect.h)){
                screen = CREDITOS;
            }
            else if(player.Rect.x > startgameRect.x && player.Rect.x < (startgameRect.x + startgameRect.w) &&
                    player.Rect.y > startgameRect.y && player.Rect.y < (startgameRect.y + startgameRect.h)){
                screen = GAME;
                SDL_ShowCursor(0);
            }
            else if(player.Rect.x > soundRect.x && player.Rect.x < (soundRect.x + soundRect.w) && 
               player.Rect.y > soundRect.y && player.Rect.y < (soundRect.y + soundRect.h)){
                if(!Mix_PausedMusic()){
                    Mix_PauseMusic();
                }
                else{
                    Mix_ResumeMusic();
                }
            }
        }
    }
    else if(screen == GAME){
    	if(Event->type == SDL_MOUSEMOTION){
        	SDL_GetMouseState(&player.Rect.x, &player.Rect.y);
    	}
        if(Event->type == SDL_MOUSEBUTTONDOWN && Event->button.button == SDL_BUTTON_LEFT){
            if((player.Rect.x + 20) > pauseplayRect.x && (player.Rect.x + 20) < (pauseplayRect.x + pauseplayRect.w) && 
               (player.Rect.y + 20) > pauseplayRect.y && (player.Rect.y + 20) < (pauseplayRect.y + pauseplayRect.h)){
                paused = !paused;
            }
            else if((player.Rect.x + 20) > soundRect.x && (player.Rect.x + 20) < (soundRect.x + soundRect.w) && 
               (player.Rect.y + 20) > soundRect.y && (player.Rect.y + 20) < (soundRect.y + soundRect.h)){
                if(!Mix_PausedMusic()){
                    Mix_PauseMusic();
                }
                else{
                    Mix_ResumeMusic();
                }
            }
        }
    }
    else if(screen == GAMEOVER){
        if(Event->type == SDL_MOUSEBUTTONDOWN && Event->button.button == SDL_BUTTON_LEFT){
            SDL_GetMouseState(&player.Rect.x, &player.Rect.y);
            if(player.Rect.x > 200 && player.Rect.x < 400 && 
               player.Rect.y > letraRect.y && player.Rect.y < (letraRect.h+letraRect.y)){
                screen = GAME;
                SDL_ShowCursor(0);
                rip = 0;
            }
            else if(player.Rect.x > gameoverRect.x && player.Rect.x < (gameoverRect.x + gameoverRect.w) && 
               player.Rect.y > gameoverRect.y && player.Rect.y < (gameoverRect.y + gameoverRect.h)){
                screen = CREDITOS;
                rip = 0;
            }
            else if(player.Rect.x > soundRect.x && player.Rect.x < (soundRect.x + soundRect.w) && 
               player.Rect.y > soundRect.y && player.Rect.y < (soundRect.y + soundRect.h)){
                if(!Mix_PausedMusic()){
                    Mix_PauseMusic();
                }
                else{
                    Mix_ResumeMusic();
                }
            }
        }
    }
}