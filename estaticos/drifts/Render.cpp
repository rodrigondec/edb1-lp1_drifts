void Drifts::Render(){
  	SDL_RenderClear(Renderer);
//================================================== TELA INICIAL =========================================================
  	if(screen == CREDITOS){
  	// ---------------------------------------------- BACKGROUND ----------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_INITIALSCREEN], NULL, NULL);
	// ---------------------------------------------- SOUND ---------------------------------------------------------------
		if(!Mix_PausedMusic()){
			SDL_RenderCopy(Renderer, TextureBank[IMG_SOUNDON], NULL, &soundRect);
		}
		else{
			SDL_RenderCopy(Renderer, TextureBank[IMG_SOUNDOFF], NULL, &soundRect);
		}
	// ---------------------------------------------- MUSIC ---------------------------------------------------------------
		letraRect.x = 200;
		letraRect.y = 10;
		SDL_RenderCopy(Renderer, TextureBank[IMG_T], NULL, &letraRect);
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_H], NULL, &letraRect);
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_E], NULL, &letraRect);
		letraRect.x += 20;
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_P], NULL, &letraRect);
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_R], NULL, &letraRect);
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_O], NULL, &letraRect);
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_D], NULL, &letraRect);
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_I], NULL, &letraRect);
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_G], NULL, &letraRect);
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_Y], NULL, &letraRect);
		letraRect.x += 20;
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_H], NULL, &letraRect);
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_O], NULL, &letraRect);
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_T], NULL, &letraRect);
		letraRect.x += 20;
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_R], NULL, &letraRect);
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_I], NULL, &letraRect);
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_D], NULL, &letraRect);
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_E], NULL, &letraRect);

  	}
//================================================== MENU ================================================================
  	else if(screen == MENU){
  	//---------------------------------------------- BACKGROUND ---------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_BACKGROUND], NULL, NULL);
	//---------------------------------------------- REWIND ICON ---------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_REWIND], NULL, &rewindRect);
	// ---------------------------------------------- SOUND ---------------------------------------------------------------
		if(!Mix_PausedMusic()){
			SDL_RenderCopy(Renderer, TextureBank[IMG_SOUNDON], NULL, &soundRect);
		}
		else{
			SDL_RenderCopy(Renderer, TextureBank[IMG_SOUNDOFF], NULL, &soundRect);
		}
	//-------------------------------------------- ICON LIFE + LIFE ------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_USERLIFE], NULL, &player.Icon);
		if(player.get_life() == 3){
			SDL_RenderCopy(Renderer, TextureBank[IMG_3], NULL, &player.Life);
		}
		else if(player.get_life() == 2){
			SDL_RenderCopy(Renderer, TextureBank[IMG_2], NULL, &player.Life);
		}
		else if(player.get_life() == 1){
			SDL_RenderCopy(Renderer, TextureBank[IMG_1], NULL, &player.Life);
		}
	//---------------------------------------------- player.score --------------------------------------------------------------
		int temp_score;
		int score = player.get_score();
		player.reset_x_rscore();
		do{
			temp_score = score%10;
			score /= 10;
			if(temp_score == 0){
				SDL_RenderCopy(Renderer, TextureBank[IMG_0], NULL, &player.Score);
			}
			else if(temp_score == 1){
				SDL_RenderCopy(Renderer, TextureBank[IMG_1], NULL, &player.Score);
			}
			else if(temp_score == 2){
				SDL_RenderCopy(Renderer, TextureBank[IMG_2], NULL, &player.Score);
			}
			else if(temp_score == 3){
				SDL_RenderCopy(Renderer, TextureBank[IMG_3], NULL, &player.Score);
			}
			else if(temp_score == 4){
				SDL_RenderCopy(Renderer, TextureBank[IMG_4], NULL, &player.Score);
			}
			else if(temp_score == 5){
				SDL_RenderCopy(Renderer, TextureBank[IMG_5], NULL, &player.Score);
			}
			else if(temp_score == 6){
				SDL_RenderCopy(Renderer, TextureBank[IMG_6], NULL, &player.Score);
			}
			else if(temp_score == 7){
				SDL_RenderCopy(Renderer, TextureBank[IMG_7], NULL, &player.Score);
			}
			else if(temp_score == 8){
				SDL_RenderCopy(Renderer, TextureBank[IMG_8], NULL, &player.Score);
			}
			else if(temp_score == 9){
				SDL_RenderCopy(Renderer, TextureBank[IMG_9], NULL, &player.Score);
			}
			player.Score.x -= 20;
		}while(score > 0);
	//---------------------------------------------- START GAME ---------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_STARTGAME], NULL, &startgameRect);
  	}
//================================================== GAME ================================================================
  	else if(screen == GAME){
  	//---------------------------------------------- BACKGROUND ----------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_BACKGROUND], NULL, NULL);
	//---------------------------------------------- PLAY/PAUSE ICON -----------------------------------------------------
		if(!paused){
			SDL_RenderCopy(Renderer, TextureBank[IMG_PAUSE], NULL, &pauseplayRect);
		}
		else{
			SDL_RenderCopy(Renderer, TextureBank[IMG_PLAY], NULL, &pauseplayRect);
		}
	// ---------------------------------------------- SOUND ---------------------------------------------------------------
		if(!Mix_PausedMusic()){
			SDL_RenderCopy(Renderer, TextureBank[IMG_SOUNDON], NULL, &soundRect);
		}
		else{
			SDL_RenderCopy(Renderer, TextureBank[IMG_SOUNDOFF], NULL, &soundRect);
		}	
	//---------------------------------------------- BOLAS ---------------------------------------------------------------
		for(unsigned i = 0; i < bolas.size(); i++){
			if(bolas[i].get_type() == "pointer"){
				SDL_RenderCopy(Renderer, TextureBank[IMG_POINTER], NULL, &bolas[i].Rect);
			}
			else if(bolas[i].get_type() == "murderer"){
				SDL_RenderCopy(Renderer, TextureBank[IMG_MURDERER], NULL, &bolas[i].Rect);
			}
			else if(bolas[i].get_type() == "saver"){
				SDL_RenderCopy(Renderer, TextureBank[IMG_SAVER], NULL, &bolas[i].Rect);
			}
		}
	//---------------------------------------------- MOUSE ---------------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_PLAYER], NULL, &player.Rect);
	//---------------------------------------------- GET MORE POINTERS ? -------------------------------------------------
		if(get_more_pointers >= 1 && get_more_pointers <= 2599){
			letraRect.x = (player.Rect.x - 160);
			letraRect.y = (player.Rect.y - 40);
			SDL_RenderCopy(Renderer, TextureBank[IMG_G], NULL, &letraRect);
			letraRect.x += 20;
			SDL_RenderCopy(Renderer, TextureBank[IMG_E], NULL, &letraRect);
			letraRect.x += 20;
			SDL_RenderCopy(Renderer, TextureBank[IMG_T], NULL, &letraRect);
			letraRect.x += 30;
			if(counter_pointers == 0){
				SDL_RenderCopy(Renderer, TextureBank[IMG_3], NULL, &letraRect);
			}
			else if(counter_pointers == 1){
				SDL_RenderCopy(Renderer, TextureBank[IMG_2], NULL, &letraRect);
			}
			else if(counter_pointers == 2){
				SDL_RenderCopy(Renderer, TextureBank[IMG_1], NULL, &letraRect);
			}
			letraRect.x += 30;
			SDL_RenderCopy(Renderer, TextureBank[IMG_M], NULL, &letraRect);
			letraRect.x += 20;
			SDL_RenderCopy(Renderer, TextureBank[IMG_O], NULL, &letraRect);
			letraRect.x += 20;
			SDL_RenderCopy(Renderer, TextureBank[IMG_R], NULL, &letraRect);
			letraRect.x += 20;
			SDL_RenderCopy(Renderer, TextureBank[IMG_E], NULL, &letraRect);
			letraRect.x += 20;
			letraRect.x += 20;
			SDL_RenderCopy(Renderer, TextureBank[IMG_P], NULL, &letraRect);
			letraRect.x += 20;
			SDL_RenderCopy(Renderer, TextureBank[IMG_O], NULL, &letraRect);
			letraRect.x += 20;
			SDL_RenderCopy(Renderer, TextureBank[IMG_I], NULL, &letraRect);
			letraRect.x += 20;
			SDL_RenderCopy(Renderer, TextureBank[IMG_N], NULL, &letraRect);
			letraRect.x += 20;
			SDL_RenderCopy(Renderer, TextureBank[IMG_T], NULL, &letraRect);
			letraRect.x += 20;
			SDL_RenderCopy(Renderer, TextureBank[IMG_E], NULL, &letraRect);
			letraRect.x += 20;
			SDL_RenderCopy(Renderer, TextureBank[IMG_R], NULL, &letraRect);
			letraRect.x += 20;
			if(counter_pointers != 2){
				SDL_RenderCopy(Renderer, TextureBank[IMG_S], NULL, &letraRect);
				letraRect.x += 20;
			}
		}
	//---------------------------------------------- RIP?? ---------------------------------------------------------------
		if(rip >= 1 && rip <= 2599){
			letraRect.x = (player.Rect.x - 80);
			letraRect.y = (player.Rect.y - 80);
			SDL_RenderCopy(Renderer, TextureBank[IMG_G], NULL, &letraRect);
			letraRect.x += 20;
			SDL_RenderCopy(Renderer, TextureBank[IMG_E], NULL, &letraRect);
			letraRect.x += 20;
			SDL_RenderCopy(Renderer, TextureBank[IMG_T], NULL, &letraRect);
			letraRect.x += 20;
			letraRect.x += 20;
			SDL_RenderCopy(Renderer, TextureBank[IMG_R], NULL, &letraRect);
			letraRect.x += 20;
			SDL_RenderCopy(Renderer, TextureBank[IMG_E], NULL, &letraRect);
			letraRect.x += 20;
			SDL_RenderCopy(Renderer, TextureBank[IMG_A], NULL, &letraRect);
			letraRect.x += 20;
			SDL_RenderCopy(Renderer, TextureBank[IMG_D], NULL, &letraRect);
			letraRect.x += 20;
			SDL_RenderCopy(Renderer, TextureBank[IMG_Y], NULL, &letraRect);
			letraRect.x += 20;
			letraRect.x = (player.Rect.x - 2);
			letraRect.y = (player.Rect.y - 40);
			if(rip >= 1 && rip <= 866){
				SDL_RenderCopy(Renderer, TextureBank[IMG_3], NULL, &letraRect);
			}
			else if(rip >= 867 && rip <= 1732){
				SDL_RenderCopy(Renderer, TextureBank[IMG_2], NULL, &letraRect);
			}
			else if(rip >= 1733 && rip <= 2599){
				SDL_RenderCopy(Renderer, TextureBank[IMG_1], NULL, &letraRect);
			}
		}	
	//---------------------------------------------- ICON LIFE + LIFE ----------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_USERLIFE], NULL, &player.Icon);
		if(player.get_life() == 3){
			SDL_RenderCopy(Renderer, TextureBank[IMG_3], NULL, &player.Life);
		}
		else if(player.get_life() == 2){
			SDL_RenderCopy(Renderer, TextureBank[IMG_2], NULL, &player.Life);
		}
		else if(player.get_life() == 1){
			SDL_RenderCopy(Renderer, TextureBank[IMG_1], NULL, &player.Life);
		}
	//---------------------------------------------- player.score --------------------------------------------------------------
		int temp_score;
		int score = player.get_score();
		player.reset_x_rscore();
		do{
			temp_score = score%10;
			score /= 10;
			if(temp_score == 0){
				SDL_RenderCopy(Renderer, TextureBank[IMG_0], NULL, &player.Score);
			}
			else if(temp_score == 1){
				SDL_RenderCopy(Renderer, TextureBank[IMG_1], NULL, &player.Score);
			}
			else if(temp_score == 2){
				SDL_RenderCopy(Renderer, TextureBank[IMG_2], NULL, &player.Score);
			}
			else if(temp_score == 3){
				SDL_RenderCopy(Renderer, TextureBank[IMG_3], NULL, &player.Score);
			}
			else if(temp_score == 4){
				SDL_RenderCopy(Renderer, TextureBank[IMG_4], NULL, &player.Score);
			}
			else if(temp_score == 5){
				SDL_RenderCopy(Renderer, TextureBank[IMG_5], NULL, &player.Score);
			}
			else if(temp_score == 6){
				SDL_RenderCopy(Renderer, TextureBank[IMG_6], NULL, &player.Score);
			}
			else if(temp_score == 7){
				SDL_RenderCopy(Renderer, TextureBank[IMG_7], NULL, &player.Score);
			}
			else if(temp_score == 8){
				SDL_RenderCopy(Renderer, TextureBank[IMG_8], NULL, &player.Score);
			}
			else if(temp_score == 9){
				SDL_RenderCopy(Renderer, TextureBank[IMG_9], NULL, &player.Score);
			}
			player.Score.x -= 20;
		}while(score > 0);	
  	}
//================================================== GAME OVER ============================================================
  	else if(screen == GAMEOVER){
  	//---------------------------------------------- BACKGROUND ----------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_BACKGROUND], NULL, NULL);
	// ---------------------------------------------- SOUND ---------------------------------------------------------------
		if(!Mix_PausedMusic()){
			SDL_RenderCopy(Renderer, TextureBank[IMG_SOUNDON], NULL, &soundRect);
		}
		else{
			SDL_RenderCopy(Renderer, TextureBank[IMG_SOUNDOFF], NULL, &soundRect);
		}
	//---------------------------------------------- GAME OVER ---------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_GAMEOVER], NULL, &gameoverRect);
	//---------------------------------------------- PLAY AGAIN ---------------------------------------------------------
		letraRect.x = 200;
		letraRect.y = 300;
		SDL_RenderCopy(Renderer, TextureBank[IMG_P], NULL, &letraRect);
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_L], NULL, &letraRect);
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_A], NULL, &letraRect);
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_Y], NULL, &letraRect);
		letraRect.x += 20;
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_A], NULL, &letraRect);
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_G], NULL, &letraRect);
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_A], NULL, &letraRect);
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_I], NULL, &letraRect);
		letraRect.x += 20;
		SDL_RenderCopy(Renderer, TextureBank[IMG_N], NULL, &letraRect);
		letraRect.x += 20;
	}
  	SDL_RenderPresent(Renderer);
}