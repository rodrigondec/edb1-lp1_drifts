void Render(){
  	SDL_RenderClear(Renderer);
//================================================== TELA INICIAL =========================================================
  	if(screen == 0){
		SDL_RenderCopy(Renderer, TextureBank[IMG_BACKGROUND], NULL, NULL);

		SDL_RenderCopy(Renderer, TextureBank[IMG_PLAYER], NULL, &playerRect);
  	}
//================================================== MENU ================================================================
  	else if(screen == 1){
		SDL_RenderCopy(Renderer, TextureBank[IMG_BACKGROUND], NULL, NULL);
  	}
//================================================== GAME ================================================================
  	else if(screen == 2){
  	//---------------------------------------------- BACKGROUND ----------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_BACKGROUND], NULL, NULL);

	//---------------------------------------------- MOUSE ---------------------------------------------------------------
		SDL_RenderCopy(Renderer, TextureBank[IMG_PLAYER], NULL, &playerRect);
	//++++++++++++++++++++++++++++++++++++++++++++++ BOLAS ATTACHED ++++++++++++++++++++++++++++++++++++++++++++++++++++++
		int bola = 1;
		while(bola){
		  	SDL_RenderCopy(Renderer, TextureBank[IMG_POINTER], NULL, NULL);
		}
	//---------------------------------------------- BOLAS ---------------------------------------------------------------
		while(true){
		//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; POINTER ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
			if(bola == 1){
		  		SDL_RenderCopy(Renderer, TextureBank[IMG_POINTER], NULL, NULL);
			}
		//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; SAVER ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
			else if(bola == 2){
		  		SDL_RenderCopy(Renderer, TextureBank[IMG_SAVER], NULL, NULL);
			}
		//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; MURDERER ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	
			else if(bola == 3){
		  		SDL_RenderCopy(Renderer, TextureBank[IMG_MURDERER], NULL, NULL);
			}
		}			
  	}
  	SDL_RenderPresent(Renderer);
}