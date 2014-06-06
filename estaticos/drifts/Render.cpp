void Drifts::Render(){
  	SDL_RenderClear(Renderer);
//================================================== TELA INICIAL =========================================================
  	if(screen == 0){
		SDL_RenderCopy(Renderer, TextureBank[IMG_INITIALSCREEN], NULL, NULL);
  	}
//================================================== MENU ================================================================
  	else if(screen == 1){
  	//---------------------------------------------- BACKGROUND ---------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_BACKGROUND], NULL, NULL);
	//---------------------------------------------- REWIND ICON ---------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_REWIND], NULL, &rewindRect);
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
  	else if(screen == 2){
  	//---------------------------------------------- BACKGROUND ----------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_BACKGROUND], NULL, NULL);
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
  	else if(screen == 3){
  	//---------------------------------------------- BACKGROUND ----------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_BACKGROUND], NULL, NULL);

		//---------------------------------------------- GAME OVER ---------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_GAMEOVER], NULL, &gameoverRect);
		//---------------------------------------------- PLAY AGAIN ---------------------------------------------------------
		letraRect.x = 200;
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