void Render(){
  	SDL_RenderClear(Renderer);
//================================================== TELA INICIAL =========================================================
  	if(screen == 0){
		SDL_RenderCopy(Renderer, TextureBank[IMG_INITIALSCREEN], NULL, NULL);
  	}//differ
//================================================== MENU ================================================================
  	else if(screen == 1){
  	//---------------------------------------------- BACKGROUND ---------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_BACKGROUND], NULL, NULL);
	//---------------------------------------------- REWIND ICON ---------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_REWIND], NULL, &rewindRect);
	//-------------------------------------------- ICON LIFE + LIFE ------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_USERLIFE], NULL, &player.Icon);
		if(player.life == 3){
			SDL_RenderCopy(Renderer, TextureBank[IMG_3], NULL, &player.Life);
		}
		else if(player.life == 2){
			SDL_RenderCopy(Renderer, TextureBank[IMG_2], NULL, &player.Life);
		}
		else if(player.life == 1){
			SDL_RenderCopy(Renderer, TextureBank[IMG_1], NULL, &player.Life);
		}
	//---------------------------------------------- player.score --------------------------------------------------------------
		int temp_score;
		int score = player.score;
		player.Score.x = 265;
		while(score > 0){
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
			player.Score.x += 20;
		}
	//---------------------------------------------- START GAME ---------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_STARTGAME], NULL, &startgameRect);
  	}
//================================================== GAME ================================================================
  	else if(screen == 2){
  	//---------------------------------------------- BACKGROUND ----------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_BACKGROUND], NULL, NULL);
	//---------------------------------------------- MOUSE ---------------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_PLAYER], NULL, &player.Rect);
	//---------------------------------------------- ICON LIFE + LIFE ----------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_USERLIFE], NULL, &player.Icon);
		if(player.life == 3){
			SDL_RenderCopy(Renderer, TextureBank[IMG_3], NULL, &player.Life);
		}
		else if(player.life == 2){
			SDL_RenderCopy(Renderer, TextureBank[IMG_2], NULL, &player.Life);
		}
		else if(player.life == 1){
			SDL_RenderCopy(Renderer, TextureBank[IMG_1], NULL, &player.Life);
		}
	//---------------------------------------------- player.score --------------------------------------------------------------
		int temp_score;
		int score = player.score;
		player.Score.x = 265;
		while(score > 0){
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
			player.Score.x += 20;
		}
	//---------------------------------------------- BOLAS ---------------------------------------------------------------
		for(unsigned i = 0; i < bolas.size(); i++){
			if(bolas[i].tipo == "pointer"){
				SDL_RenderCopy(Renderer, TextureBank[IMG_POINTER], NULL, &bolas[i].Rect);
			}
			else if(bolas[i].tipo == "murderer"){
				SDL_RenderCopy(Renderer, TextureBank[IMG_MURDERER], NULL, &bolas[i].Rect);
			}
			else if(bolas[i].tipo == "saver"){
				SDL_RenderCopy(Renderer, TextureBank[IMG_SAVER], NULL, &bolas[i].Rect);
			}
		}
		//SDL_RenderCopy(Renderer, TextureBank[IMG_POINTER], NULL, &bolas[0].Rect);			
  	}
  	SDL_RenderPresent(Renderer);
}