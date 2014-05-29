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
		int temp_score = player.score - 10;
		int score = player.score;
		if(temp_score < 0){
			if(player.score == 0){	
				SDL_RenderCopy(Renderer, TextureBank[IMG_0], NULL, &player.Score1);
			}
			else if(player.score == 1){
				SDL_RenderCopy(Renderer, TextureBank[IMG_1], NULL, &player.Score1);
			}
			else if(player.score == 2){
				SDL_RenderCopy(Renderer, TextureBank[IMG_2], NULL, &player.Score1);
			}
			else if(player.score == 3){
				SDL_RenderCopy(Renderer, TextureBank[IMG_3], NULL, &player.Score1);
			}
			else if(player.score == 4){
				SDL_RenderCopy(Renderer, TextureBank[IMG_4], NULL, &player.Score1);
			}
			else if(player.score == 5){
				SDL_RenderCopy(Renderer, TextureBank[IMG_5], NULL, &player.Score1);
			}
			else if(player.score == 6){
				SDL_RenderCopy(Renderer, TextureBank[IMG_6], NULL, &player.Score1);
			}
			else if(player.score == 7){
				SDL_RenderCopy(Renderer, TextureBank[IMG_7], NULL, &player.Score1);
			}
			else if(player.score == 8){
				SDL_RenderCopy(Renderer, TextureBank[IMG_8], NULL, &player.Score1);
			}
			else if(player.score == 9){
				SDL_RenderCopy(Renderer, TextureBank[IMG_9], NULL, &player.Score1);
			}			
		}
		else if(temp_score >= 0 && temp_score < 90){
			int dig2 = score/10;
			if(dig2 == 0){	
				SDL_RenderCopy(Renderer, TextureBank[IMG_0], NULL, &player.Score1);
			}
			else if(dig2 == 1){
				SDL_RenderCopy(Renderer, TextureBank[IMG_1], NULL, &player.Score1);
			}
			else if(dig2 == 2){
				SDL_RenderCopy(Renderer, TextureBank[IMG_2], NULL, &player.Score1);
			}
			else if(dig2 == 3){
				SDL_RenderCopy(Renderer, TextureBank[IMG_3], NULL, &player.Score1);
			}
			else if(dig2 == 4){
				SDL_RenderCopy(Renderer, TextureBank[IMG_4], NULL, &player.Score1);
			}
			else if(dig2 == 5){
				SDL_RenderCopy(Renderer, TextureBank[IMG_5], NULL, &player.Score1);
			}
			else if(dig2 == 6){
				SDL_RenderCopy(Renderer, TextureBank[IMG_6], NULL, &player.Score1);
			}
			else if(dig2 == 7){
				SDL_RenderCopy(Renderer, TextureBank[IMG_7], NULL, &player.Score1);
			}
			else if(dig2  == 8){
				SDL_RenderCopy(Renderer, TextureBank[IMG_8], NULL, &player.Score1);
			}
			else if(dig2 == 9){
				SDL_RenderCopy(Renderer, TextureBank[IMG_9], NULL, &player.Score1);
			}

			int dig1 = score%10;
			if(dig1 == 0){	
				SDL_RenderCopy(Renderer, TextureBank[IMG_0], NULL, &player.Score2);
			}
			else if(dig1 == 1){
				SDL_RenderCopy(Renderer, TextureBank[IMG_1], NULL, &player.Score2);
			}
			else if(dig1 == 2){
				SDL_RenderCopy(Renderer, TextureBank[IMG_2], NULL, &player.Score2);
			}
			else if(dig1 == 3){
				SDL_RenderCopy(Renderer, TextureBank[IMG_3], NULL, &player.Score2);
			}
			else if(dig1 == 4){
				SDL_RenderCopy(Renderer, TextureBank[IMG_4], NULL, &player.Score2);
			}
			else if(dig1 == 5){
				SDL_RenderCopy(Renderer, TextureBank[IMG_5], NULL, &player.Score2);
			}
			else if(dig1 == 6){
				SDL_RenderCopy(Renderer, TextureBank[IMG_6], NULL, &player.Score2);
			}
			else if(dig1 == 7){
				SDL_RenderCopy(Renderer, TextureBank[IMG_7], NULL, &player.Score2);
			}
			else if(dig1 == 8){
				SDL_RenderCopy(Renderer, TextureBank[IMG_8], NULL, &player.Score2);
			}
			else if(dig1 == 9){
				SDL_RenderCopy(Renderer, TextureBank[IMG_9], NULL, &player.Score2);
			}			
		}
		else if(temp_score >= 90){
			int dig3 = score/100;
			if(dig3 == 0){	
				SDL_RenderCopy(Renderer, TextureBank[IMG_0], NULL, &player.Score1);
			}
			else if(dig3 == 1){
				SDL_RenderCopy(Renderer, TextureBank[IMG_1], NULL, &player.Score1);
			}
			else if(dig3 == 2){
				SDL_RenderCopy(Renderer, TextureBank[IMG_2], NULL, &player.Score1);
			}
			else if(dig3 == 3){
				SDL_RenderCopy(Renderer, TextureBank[IMG_3], NULL, &player.Score1);
			}
			else if(dig3 == 4){
				SDL_RenderCopy(Renderer, TextureBank[IMG_4], NULL, &player.Score1);
			}
			else if(dig3 == 5){
				SDL_RenderCopy(Renderer, TextureBank[IMG_5], NULL, &player.Score1);
			}
			else if(dig3 == 6){
				SDL_RenderCopy(Renderer, TextureBank[IMG_6], NULL, &player.Score1);
			}
			else if(dig3 == 7){
				SDL_RenderCopy(Renderer, TextureBank[IMG_7], NULL, &player.Score1);
			}
			else if(dig3  == 8){
				SDL_RenderCopy(Renderer, TextureBank[IMG_8], NULL, &player.Score1);
			}
			else if(dig3 == 9){
				SDL_RenderCopy(Renderer, TextureBank[IMG_9], NULL, &player.Score1);
			}

			int dig2 = score/10;
			dig2 = dig2%10;
			if(dig2 == 0){	
				SDL_RenderCopy(Renderer, TextureBank[IMG_0], NULL, &player.Score2);
			}
			else if(dig2 == 1){
				SDL_RenderCopy(Renderer, TextureBank[IMG_1], NULL, &player.Score2);
			}
			else if(dig2 == 2){
				SDL_RenderCopy(Renderer, TextureBank[IMG_2], NULL, &player.Score2);
			}
			else if(dig2 == 3){
				SDL_RenderCopy(Renderer, TextureBank[IMG_3], NULL, &player.Score2);
			}
			else if(dig2 == 4){
				SDL_RenderCopy(Renderer, TextureBank[IMG_4], NULL, &player.Score2);
			}
			else if(dig2 == 5){
				SDL_RenderCopy(Renderer, TextureBank[IMG_5], NULL, &player.Score2);
			}
			else if(dig2 == 6){
				SDL_RenderCopy(Renderer, TextureBank[IMG_6], NULL, &player.Score2);
			}
			else if(dig2 == 7){
				SDL_RenderCopy(Renderer, TextureBank[IMG_7], NULL, &player.Score2);
			}
			else if(dig2  == 8){
				SDL_RenderCopy(Renderer, TextureBank[IMG_8], NULL, &player.Score2);
			}
			else if(dig2 == 9){
				SDL_RenderCopy(Renderer, TextureBank[IMG_9], NULL, &player.Score2);
			}

			int dig1 = score%10;
			if(dig1 == 0){	
				SDL_RenderCopy(Renderer, TextureBank[IMG_0], NULL, &player.Score3);
			}
			else if(dig1 == 1){
				SDL_RenderCopy(Renderer, TextureBank[IMG_1], NULL, &player.Score3);
			}
			else if(dig1 == 2){
				SDL_RenderCopy(Renderer, TextureBank[IMG_2], NULL, &player.Score3);
			}
			else if(dig1 == 3){
				SDL_RenderCopy(Renderer, TextureBank[IMG_3], NULL, &player.Score3);
			}
			else if(dig1 == 4){
				SDL_RenderCopy(Renderer, TextureBank[IMG_4], NULL, &player.Score3);
			}
			else if(dig1 == 5){
				SDL_RenderCopy(Renderer, TextureBank[IMG_5], NULL, &player.Score3);
			}
			else if(dig1 == 6){
				SDL_RenderCopy(Renderer, TextureBank[IMG_6], NULL, &player.Score3);
			}
			else if(dig1 == 7){
				SDL_RenderCopy(Renderer, TextureBank[IMG_7], NULL, &player.Score3);
			}
			else if(dig1 == 8){
				SDL_RenderCopy(Renderer, TextureBank[IMG_8], NULL, &player.Score3);
			}
			else if(dig1 == 9){
				SDL_RenderCopy(Renderer, TextureBank[IMG_9], NULL, &player.Score3);
			}
		}
	//---------------------------------------------- START GAME ---------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_STARTGAME], NULL, &startgameRect);
  	}
//================================================== GAME ================================================================
  	else if(screen == 2){
  	//---------------------------------------------- BACKGROUND ----------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_BACKGROUND], NULL, NULL);
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
		int temp_score = player.score - 10;
		int score = player.score;
		if(temp_score < 0){
			if(player.score == 0){	
				SDL_RenderCopy(Renderer, TextureBank[IMG_0], NULL, &player.Score1);
			}
			else if(player.score == 1){
				SDL_RenderCopy(Renderer, TextureBank[IMG_1], NULL, &player.Score1);
			}
			else if(player.score == 2){
				SDL_RenderCopy(Renderer, TextureBank[IMG_2], NULL, &player.Score1);
			}
			else if(player.score == 3){
				SDL_RenderCopy(Renderer, TextureBank[IMG_3], NULL, &player.Score1);
			}
			else if(player.score == 4){
				SDL_RenderCopy(Renderer, TextureBank[IMG_4], NULL, &player.Score1);
			}
			else if(player.score == 5){
				SDL_RenderCopy(Renderer, TextureBank[IMG_5], NULL, &player.Score1);
			}
			else if(player.score == 6){
				SDL_RenderCopy(Renderer, TextureBank[IMG_6], NULL, &player.Score1);
			}
			else if(player.score == 7){
				SDL_RenderCopy(Renderer, TextureBank[IMG_7], NULL, &player.Score1);
			}
			else if(player.score == 8){
				SDL_RenderCopy(Renderer, TextureBank[IMG_8], NULL, &player.Score1);
			}
			else if(player.score == 9){
				SDL_RenderCopy(Renderer, TextureBank[IMG_9], NULL, &player.Score1);
			}			
		}
		else if(temp_score >= 0 && temp_score < 90){
			int dig2 = score/10;
			if(dig2 == 0){	
				SDL_RenderCopy(Renderer, TextureBank[IMG_0], NULL, &player.Score1);
			}
			else if(dig2 == 1){
				SDL_RenderCopy(Renderer, TextureBank[IMG_1], NULL, &player.Score1);
			}
			else if(dig2 == 2){
				SDL_RenderCopy(Renderer, TextureBank[IMG_2], NULL, &player.Score1);
			}
			else if(dig2 == 3){
				SDL_RenderCopy(Renderer, TextureBank[IMG_3], NULL, &player.Score1);
			}
			else if(dig2 == 4){
				SDL_RenderCopy(Renderer, TextureBank[IMG_4], NULL, &player.Score1);
			}
			else if(dig2 == 5){
				SDL_RenderCopy(Renderer, TextureBank[IMG_5], NULL, &player.Score1);
			}
			else if(dig2 == 6){
				SDL_RenderCopy(Renderer, TextureBank[IMG_6], NULL, &player.Score1);
			}
			else if(dig2 == 7){
				SDL_RenderCopy(Renderer, TextureBank[IMG_7], NULL, &player.Score1);
			}
			else if(dig2  == 8){
				SDL_RenderCopy(Renderer, TextureBank[IMG_8], NULL, &player.Score1);
			}
			else if(dig2 == 9){
				SDL_RenderCopy(Renderer, TextureBank[IMG_9], NULL, &player.Score1);
			}

			int dig1 = score%10;
			if(dig1 == 0){	
				SDL_RenderCopy(Renderer, TextureBank[IMG_0], NULL, &player.Score2);
			}
			else if(dig1 == 1){
				SDL_RenderCopy(Renderer, TextureBank[IMG_1], NULL, &player.Score2);
			}
			else if(dig1 == 2){
				SDL_RenderCopy(Renderer, TextureBank[IMG_2], NULL, &player.Score2);
			}
			else if(dig1 == 3){
				SDL_RenderCopy(Renderer, TextureBank[IMG_3], NULL, &player.Score2);
			}
			else if(dig1 == 4){
				SDL_RenderCopy(Renderer, TextureBank[IMG_4], NULL, &player.Score2);
			}
			else if(dig1 == 5){
				SDL_RenderCopy(Renderer, TextureBank[IMG_5], NULL, &player.Score2);
			}
			else if(dig1 == 6){
				SDL_RenderCopy(Renderer, TextureBank[IMG_6], NULL, &player.Score2);
			}
			else if(dig1 == 7){
				SDL_RenderCopy(Renderer, TextureBank[IMG_7], NULL, &player.Score2);
			}
			else if(dig1 == 8){
				SDL_RenderCopy(Renderer, TextureBank[IMG_8], NULL, &player.Score2);
			}
			else if(dig1 == 9){
				SDL_RenderCopy(Renderer, TextureBank[IMG_9], NULL, &player.Score2);
			}			
		}
		else if(temp_score >= 90){
			int dig3 = score/100;
			if(dig3 == 0){	
				SDL_RenderCopy(Renderer, TextureBank[IMG_0], NULL, &player.Score1);
			}
			else if(dig3 == 1){
				SDL_RenderCopy(Renderer, TextureBank[IMG_1], NULL, &player.Score1);
			}
			else if(dig3 == 2){
				SDL_RenderCopy(Renderer, TextureBank[IMG_2], NULL, &player.Score1);
			}
			else if(dig3 == 3){
				SDL_RenderCopy(Renderer, TextureBank[IMG_3], NULL, &player.Score1);
			}
			else if(dig3 == 4){
				SDL_RenderCopy(Renderer, TextureBank[IMG_4], NULL, &player.Score1);
			}
			else if(dig3 == 5){
				SDL_RenderCopy(Renderer, TextureBank[IMG_5], NULL, &player.Score1);
			}
			else if(dig3 == 6){
				SDL_RenderCopy(Renderer, TextureBank[IMG_6], NULL, &player.Score1);
			}
			else if(dig3 == 7){
				SDL_RenderCopy(Renderer, TextureBank[IMG_7], NULL, &player.Score1);
			}
			else if(dig3  == 8){
				SDL_RenderCopy(Renderer, TextureBank[IMG_8], NULL, &player.Score1);
			}
			else if(dig3 == 9){
				SDL_RenderCopy(Renderer, TextureBank[IMG_9], NULL, &player.Score1);
			}

			int dig2 = score/10;
			dig2 = dig2%10;
			if(dig2 == 0){	
				SDL_RenderCopy(Renderer, TextureBank[IMG_0], NULL, &player.Score2);
			}
			else if(dig2 == 1){
				SDL_RenderCopy(Renderer, TextureBank[IMG_1], NULL, &player.Score2);
			}
			else if(dig2 == 2){
				SDL_RenderCopy(Renderer, TextureBank[IMG_2], NULL, &player.Score2);
			}
			else if(dig2 == 3){
				SDL_RenderCopy(Renderer, TextureBank[IMG_3], NULL, &player.Score2);
			}
			else if(dig2 == 4){
				SDL_RenderCopy(Renderer, TextureBank[IMG_4], NULL, &player.Score2);
			}
			else if(dig2 == 5){
				SDL_RenderCopy(Renderer, TextureBank[IMG_5], NULL, &player.Score2);
			}
			else if(dig2 == 6){
				SDL_RenderCopy(Renderer, TextureBank[IMG_6], NULL, &player.Score2);
			}
			else if(dig2 == 7){
				SDL_RenderCopy(Renderer, TextureBank[IMG_7], NULL, &player.Score2);
			}
			else if(dig2  == 8){
				SDL_RenderCopy(Renderer, TextureBank[IMG_8], NULL, &player.Score2);
			}
			else if(dig2 == 9){
				SDL_RenderCopy(Renderer, TextureBank[IMG_9], NULL, &player.Score2);
			}

			int dig1 = score%10;
			if(dig1 == 0){	
				SDL_RenderCopy(Renderer, TextureBank[IMG_0], NULL, &player.Score3);
			}
			else if(dig1 == 1){
				SDL_RenderCopy(Renderer, TextureBank[IMG_1], NULL, &player.Score3);
			}
			else if(dig1 == 2){
				SDL_RenderCopy(Renderer, TextureBank[IMG_2], NULL, &player.Score3);
			}
			else if(dig1 == 3){
				SDL_RenderCopy(Renderer, TextureBank[IMG_3], NULL, &player.Score3);
			}
			else if(dig1 == 4){
				SDL_RenderCopy(Renderer, TextureBank[IMG_4], NULL, &player.Score3);
			}
			else if(dig1 == 5){
				SDL_RenderCopy(Renderer, TextureBank[IMG_5], NULL, &player.Score3);
			}
			else if(dig1 == 6){
				SDL_RenderCopy(Renderer, TextureBank[IMG_6], NULL, &player.Score3);
			}
			else if(dig1 == 7){
				SDL_RenderCopy(Renderer, TextureBank[IMG_7], NULL, &player.Score3);
			}
			else if(dig1 == 8){
				SDL_RenderCopy(Renderer, TextureBank[IMG_8], NULL, &player.Score3);
			}
			else if(dig1 == 9){
				SDL_RenderCopy(Renderer, TextureBank[IMG_9], NULL, &player.Score3);
			}
		}
	//---------------------------------------------- MOUSE ---------------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_PLAYER], NULL, &player.Rect);
	//---------------------------------------------- BOLAS ---------------------------------------------------------------
		for(unsigned i; i < bolas.size(); i++){
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
  	}
  	SDL_RenderPresent(Renderer);
}