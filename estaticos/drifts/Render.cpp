void Render(){
  	SDL_RenderClear(Renderer);
//================================================== TELA INICIAL =========================================================
  	if(screen == 0){
		SDL_RenderCopy(Renderer, TextureBank[IMG_INITIALSCREEN], NULL, NULL);
  	}
//================================================== MENU ================================================================
  	else if(screen == 1){
		SDL_RenderCopy(Renderer, TextureBank[IMG_BACKGROUND], NULL, NULL);

		SDL_RenderCopy(Renderer, TextureBank[IMG_REWIND], NULL, &rewindRect);
		
		SDL_RenderCopy(Renderer, TextureBank[IMG_STARTGAME], NULL, &startgameRect);
  	}
//================================================== GAME ================================================================
  	else if(screen == 2){
  	//---------------------------------------------- BACKGROUND ----------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_BACKGROUND], NULL, NULL);

	//---------------------------------------------- MOUSE ---------------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_PLAYER], NULL, &playerRect);
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