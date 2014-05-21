void Render(){
  	SDL_RenderClear(Renderer);
//================================================== TELA INICIAL =========================================================
  	if(screen == 0){
	  	//SDL_Texture* BackgroundText = load_PNG("/home/clara/Documents/UFRN/2014.1/EDBI/drifts/estaticos/images/background.png");//clara
	  	SDL_Texture* BackgroundText = load_PNG("C:/Users/homepc/Downloads/rod/prog/drifts/estaticos/images/background.png");//rod
		SDL_RenderCopy(Renderer, BackgroundText, NULL, &backgroundRect);
		//SDL_Texture* Player = load_PNG("/home/clara/Documents/UFRN/2014.1/EDBI/drifts/estaticos/images/player.png");//clara
	  	SDL_Texture* Player = load_PNG("C:/Users/homepc/Downloads/rod/prog/drifts/estaticos/images/player.png");//rod
		SDL_RenderCopy(Renderer, Player, NULL, &playerRect);
  	}
//================================================== MENU ================================================================
  	else if(screen == 1){
  		//SDL_Texture* BackgroundText = load_PNG("/home/clara/Documents/UFRN/2014.1/EDBI/drifts/estaticos/images/background.png");//clara
	  	SDL_Texture* BackgroundText = load_PNG("C:/Users/homepc/Downloads/rod/prog/drifts/estaticos/images/background.png");//rod
		SDL_RenderCopy(Renderer, BackgroundText, NULL, NULL);
  	}
//================================================== GAME ================================================================
  	else if(screen == 2){
  	//---------------------------------------------- BACKGROUND ----------------------------------------------------------
  		//SDL_Texture* BackgroundText = load_PNG("/home/clara/Documents/UFRN/2014.1/EDBI/drifts/estaticos/images/background.png");//clara
	  	SDL_Texture* BackgroundText = load_PNG("C:/Users/homepc/Downloads/rod/prog/drifts/estaticos/images/background.png");//rod
		SDL_RenderCopy(Renderer, BackgroundText, NULL, NULL);

	//---------------------------------------------- MOUSE ---------------------------------------------------------------
		//SDL_Texture* Player = load_PNG("/home/clara/Documents/UFRN/2014.1/EDBI/drifts/estaticos/images/player.png");//clara
	  	SDL_Texture* Player = load_PNG("C:/Users/homepc/Downloads/rod/prog/drifts/estaticos/images/player.png");//rod
		SDL_RenderCopy(Renderer, Player, NULL, &playerRect);
		SDL_Texture* bolas_attack;
		while(bolas_attack){
			//bolas_attack = load_PNG("/home/clara/Documents/UFRN/2014.1/EDBI/drifts/estaticos/images/pointer.png");//clara
		  	SDL_Texture* BackgroundText = load_PNG("C:/Users/homepc/Downloads/rod/prog/drifts/estaticos/images/pointer.png");//rod
		  	SDL_RenderCopy(Renderer, bolas_attack, NULL, NULL);
		}
	//---------------------------------------------- BOLAS ---------------------------------------------------------------
		SDL_Texture* Bola;
		int bola;
		while(true){
		//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; POINTER ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
			if(bola == 1){
				//Bola = load_PNG("/home/clara/Documents/UFRN/2014.1/EDBI/drifts/estaticos/images/pointer.png");//clara
		  		Bola = load_PNG("C:/Users/homepc/Downloads/rod/prog/drifts/estaticos/images/pointer.png");//rod
			}
		//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; SAVER ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
			else if(bola == 2){
				//Bola = load_PNG("/home/clara/Documents/UFRN/2014.1/EDBI/drifts/estaticos/images/saver.png");//clara
		  		Bola = load_PNG("C:/Users/homepc/Downloads/rod/prog/drifts/estaticos/images/saver.png");//rod
			}
		//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; MURDERER ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	
			else if(bola == 3){
				//Bola = load_PNG("/home/clara/Documents/UFRN/2014.1/EDBI/drifts/estaticos/images/murderer.png");//clara
		  		Bola = load_PNG("C:/Users/homepc/Downloads/rod/prog/drifts/estaticos/images/murderer.png");//rod
			}
			
			SDL_RenderCopy(Renderer, Bola, NULL, NULL);
		}
  	}

  	SDL_RenderPresent(Renderer);
}