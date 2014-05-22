void Render(){
  	SDL_RenderClear(Renderer);
//================================================== TELA INICIAL =========================================================
  	/*if(screen == 0){*/
	  	SDL_Texture* backgroundTexture = load_PNG("estaticos/images/background.png");
		SDL_RenderCopy(Renderer, backgroundTexture, NULL, NULL);

		/*playerTexture = load_PNG("estaticos/images/player.png");
		SDL_RenderCopy(Renderer, playerTexture, NULL, &playerRect);
  	}
//================================================== MENU ================================================================
  	else if(screen == 1){
	  	backgroundTexture = load_PNG("estaticos/images/background.png");
		SDL_RenderCopy(Renderer, backgroundTexture, NULL, NULL);
  	}
//================================================== GAME ================================================================
  	else if(screen == 2){
  	//---------------------------------------------- BACKGROUND ----------------------------------------------------------
	  	backgroundTexture = load_PNG("estaticos/images/background.png");
		SDL_RenderCopy(Renderer, backgroundTexture, NULL, NULL);

	//---------------------------------------------- MOUSE ---------------------------------------------------------------
	  	playerTexture = load_PNG("estaticos/images/player.png");
		SDL_RenderCopy(Renderer, playerTexture, NULL, &playerRect);
	//++++++++++++++++++++++++++++++++++++++++++++++ BOLAS ATTACHED ++++++++++++++++++++++++++++++++++++++++++++++++++++++
		while(bolaTexture){
		  	bolaTexture = load_PNG("estaticos/images/pointer.png");
		  	SDL_RenderCopy(Renderer, bolaTexture, NULL, NULL);
		}
	//---------------------------------------------- BOLAS ---------------------------------------------------------------
		int bola = 1;
		while(true){
		//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; POINTER ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
			if(bola == 1){
		  		bolaTexture = load_PNG("estaticos/images/pointer.png");
			}
		//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; SAVER ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
			else if(bola == 2){
		  		bolaTexture = load_PNG("estaticos/images/saver.png");
			}
		//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; MURDERER ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	
			else if(bola == 3){
		  		bolaTexture = load_PNG("estaticos/images/murderer.png");
			}
			
			SDL_RenderCopy(Renderer, bolaTexture, NULL, NULL);
		}
  	}*/

  	SDL_RenderPresent(Renderer);
}