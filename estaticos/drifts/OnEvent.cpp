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
                screen = INSTRUCOES;
            }
    	}
    }
    else if(screen == INSTRUCOES){
        SDL_ShowCursor(1);
        if(Event->type == SDL_MOUSEBUTTONDOWN && Event->button.button == SDL_BUTTON_LEFT){
            SDL_GetMouseState(&player.Rect.x, &player.Rect.y);
            if(player.Rect.x > rewindRect.x && player.Rect.x < (rewindRect.x + rewindRect.w) && 
               player.Rect.y > rewindRect.y && player.Rect.y < (rewindRect.y + rewindRect.h)){
                screen = CREDITOS;
            }
            else if(player.Rect.x > instrucao1Rect.x && player.Rect.x < (instrucao1Rect.x + instrucao1Rect.w) && 
               player.Rect.y > instrucao1Rect.y && player.Rect.y < (instrucao1Rect.y + instrucao1Rect.h)){
                screen = INSTRUCAO1;
                SDL_ShowCursor(0);
            }
            else if(player.Rect.x > instrucao2Rect.x && player.Rect.x < (instrucao2Rect.x + instrucao2Rect.w) && 
               player.Rect.y > instrucao2Rect.y && player.Rect.y < (instrucao2Rect.y + instrucao2Rect.h)){
                screen = INSTRUCAO2;
                SDL_ShowCursor(0);
            }
            else if(player.Rect.x > instrucao3Rect.x && player.Rect.x < (instrucao3Rect.x + instrucao3Rect.w) && 
               player.Rect.y > instrucao3Rect.y && player.Rect.y < (instrucao3Rect.y + instrucao3Rect.h)){
                screen = INSTRUCAO3;
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
            else if(player.Rect.x > forwardRect.x && player.Rect.x < (forwardRect.x + forwardRect.w) && 
               player.Rect.y > forwardRect.y && player.Rect.y < (forwardRect.y + forwardRect.h)){
                screen = MENU;
            }
        }
    }
    else if(screen == INSTRUCAO1){
        if(Event->type == SDL_MOUSEBUTTONDOWN && Event->button.button == SDL_BUTTON_LEFT){
            screen = INSTRUCOES;
        }
    }
    else if(screen == INSTRUCAO2){
        if(Event->type == SDL_MOUSEBUTTONDOWN && Event->button.button == SDL_BUTTON_LEFT){
            screen = INSTRUCOES;
        }
    }
    else if(screen == INSTRUCAO3){
        if(Event->type == SDL_MOUSEBUTTONDOWN && Event->button.button == SDL_BUTTON_LEFT){
            screen = INSTRUCOES;
        }
    }
    else if(screen == MENU){
        if(Event->type == SDL_MOUSEBUTTONDOWN && Event->button.button == SDL_BUTTON_LEFT){
            SDL_GetMouseState(&player.Rect.x, &player.Rect.y);
            if(player.Rect.x > rewindRect.x && player.Rect.x < (rewindRect.x + rewindRect.w) && 
               player.Rect.y > rewindRect.y && player.Rect.y < (rewindRect.y + rewindRect.h)){
                screen = INSTRUCOES;
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
            if((player.Rect.x + 27) > pauseplayRect.x && (player.Rect.x + 21) < (pauseplayRect.x + pauseplayRect.w) && 
               (player.Rect.y + 27) > pauseplayRect.y && (player.Rect.y + 21) < (pauseplayRect.y + pauseplayRect.h)){
                paused = !paused;
            }
            else if((player.Rect.x + 27) > soundRect.x && (player.Rect.x + 21) < (soundRect.x + soundRect.w) && 
               (player.Rect.y + 27) > soundRect.y && (player.Rect.y + 21) < (soundRect.y + soundRect.h)){
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