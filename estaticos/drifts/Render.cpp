void Render(){
  	SDL_RenderClear(Renderer);
//================================================== TELA INICIAL =========================================================
  	if(screen == 0){
	  	//backgroundTexture = load_PNG("/home/clara/Documents/UFRN/2014.1/EDBI/drifts/estaticos/images/background.png");//clara
	  	backgroundTexture = load_PNG("C:/Users/homepc/Downloads/rod/prog/drifts/estaticos/images/background.png");//rod
		SDL_RenderCopy(Renderer, backgroundTexture, NULL, NULL);
		//playerTexture = load_PNG("/home/clara/Documents/UFRN/2014.1/EDBI/drifts/estaticos/images/player.png");//clara
	  	playerTexture = load_PNG("C:/Users/homepc/Downloads/rod/prog/drifts/estaticos/images/player.png");//rod
		SDL_RenderCopy(Renderer, playerTexture, NULL, &playerRect);
  	}
//================================================== MENU ================================================================
  	else if(screen == 1){
  		//backgroundTexture = load_PNG("/home/clara/Documents/UFRN/2014.1/EDBI/drifts/estaticos/images/background.png");//clara
	  	backgroundTexture = load_PNG("C:/Users/homepc/Downloads/rod/prog/drifts/estaticos/images/background.png");//rod
		SDL_RenderCopy(Renderer, backgroundTexture, NULL, NULL);
  	}
//================================================== GAME ================================================================
  	else if(screen == 2){
  	//---------------------------------------------- BACKGROUND ----------------------------------------------------------
  		//backgroundTexture = load_PNG("/home/clara/Documents/UFRN/2014.1/EDBI/drifts/estaticos/images/background.png");//clara
	  	backgroundTexture = load_PNG("C:/Users/homepc/Downloads/rod/prog/drifts/estaticos/images/background.png");//rod
		SDL_RenderCopy(Renderer, backgroundTexture, NULL, NULL);

	//---------------------------------------------- MOUSE ---------------------------------------------------------------
		//playerTexture = load_PNG("/home/clara/Documents/UFRN/2014.1/EDBI/drifts/estaticos/images/player.png");//clara
	  	playerTexture = load_PNG("C:/Users/homepc/Downloads/rod/prog/drifts/estaticos/images/player.png");//rod
		SDL_RenderCopy(Renderer, playerTexture, NULL, &playerRect);
		SDL_Texture* bolas_attack;
		while(bolas_attack){
			//bolas_attack = load_PNG("/home/clara/Documents/UFRN/2014.1/EDBI/drifts/estaticos/images/pointer.png");//clara
		  	bolaTexture = load_PNG("C:/Users/homepc/Downloads/rod/prog/drifts/estaticos/images/pointer.png");//rod
		  	SDL_RenderCopy(Renderer, bolas_attack, NULL, NULL);
		}
	//---------------------------------------------- BOLAS ---------------------------------------------------------------
		int bola;
		while(true){
		//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; POINTER ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
			if(bola == 1){
				//bolaTexture = load_PNG("/home/clara/Documents/UFRN/2014.1/EDBI/drifts/estaticos/images/pointer.png");//clara
		  		bolaTexture = load_PNG("C:/Users/homepc/Downloads/rod/prog/drifts/estaticos/images/pointer.png");//rod
			}
		//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; SAVER ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
			else if(bola == 2){
				//bolaTexture = load_PNG("/home/clara/Documents/UFRN/2014.1/EDBI/drifts/estaticos/images/saver.png");//clara
		  		bolaTexture = load_PNG("C:/Users/homepc/Downloads/rod/prog/drifts/estaticos/images/saver.png");//rod
			}
		//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; MURDERER ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	
			else if(bola == 3){
				//bolaTexture = load_PNG("/home/clara/Documents/UFRN/2014.1/EDBI/drifts/estaticos/images/murderer.png");//clara
		  		bolaTexture = load_PNG("C:/Users/homepc/Downloads/rod/prog/drifts/estaticos/images/murderer.png");//rod
			}
			
			SDL_RenderCopy(Renderer, bolaTexture, NULL, NULL);
		}
  	}

  	SDL_RenderPresent(Renderer);
}